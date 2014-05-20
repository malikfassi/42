<?php
error_reporting(1);
ini_set('display_errors', 'On');
session_start();
$array = explode("\n", file_get_contents("user.conf"));
$url = $array[0];
$user = $array[1];
$passwd = $array[2];
$dbname = $array[3];
?>
<meta charset="utf-8">
<link rel="stylesheet" href="../includes/style/style.css" type="text/css"/>
<h1>Bienvenue,  <?php echo $_SESSION["username"]; ?></h1>
<br/>
<ul class="menu">
	<li><a href="?action=add">Ajouter un produit</a></li>
	<li><a href="?action=set">Modifier et/ou supprimer un produit</a></li>
	<li><a href="?action=addcat">Ajouter une categorie</a></li>
	<li><a href="?action=setcat">Modifier et/ou supprimer une categorie</a></li>
</ul>
<br/>
<br/>
<?php
if (isset($_SESSION["username"]))
{
	if (isset($_GET['action']))
	{
		if ($_GET['action'] == 'add')
		{
			if (isset($_POST["submit"]))
			{
				$title=$_POST["title"];
				$description = $_POST["description"];
				$price=$_POST["price"];
				$category = $_POST["category"];
				$img = $_FILES['img']['name'];
				$img_tmp = $_FILES['img']['tmp_name'];
				if (empty($img_tmp))
					echo "Veuillez entrer une image";
				else
				{
					$dataimg;
					$image = explode('.', $img);
					$image_ext = end($image);
					if (in_array(strtolower($image_ext), array('png', 'jpeg')) === false)
					{
						echo "Veuillez entrer une image ayant pour extension : png, ou jpeg";
					}
					else 
					{
						$image_size = getimagesize($img_tmp);
						if ($image_size['mime']== 'image/jpeg')
							$image_src = imagecreatefromjpeg($img_tmp);
						else if ($image_size['mime']== 'image/png')
							$image_src = imagecreatefrompng($img_tmp);
						else
						{
							$image_src = false;
							echo "Veuillez rentrer une image valide";
						}
						if ($image_src !== false)
						{
							$image_width = 200;

							if ($image_size[0] == $image_width)
							{
								echo "hey";
								$image_finale = $image_src;
							}
							else
							{
								$new_width[0] = $image_width;
								$new_height[1] = 200;
								$image_finale = imagecreatetruecolor($new_width[0], $new_height[1]);
								imagecopyresampled($image_finale, $image_src, 0, 0, 0, 0, $new_width[0], $new_height[1], $image_size[0], $image_size[1]);
							}
							$var = imagejpeg($image_finale, 'imgs/'.$title.'.jpg');
							$dataimg = base64_encode(file_get_contents('imgs/'.$title.'.jpg'));
						}
						if ($title && $description && $price)
						{
							if (!is_numeric($price))
								echo "Le prix doit etre numerique.";
							else
							{
								$con=mysqli_connect("$url","$user","$passwd", "$dbname");
					// Check connection
								if (mysqli_connect_errno())
									echo "Failed to connect to MySQL: " . mysqli_connect_error();
								$result = mysqli_query($con, "INSERT INTO products (`id`, `title`, `price`, `description`, `category`, `img`) VALUES ('?', '$title', $price, '$description', '$category', '$dataimg')");
								if ( false===$result ) {
									printf("error: %s\n", mysqli_error($con));
								}
								mysqli_close($con);
							}
						}
						else
							echo "Veuillez remplir tout les champs";
					}
				}
			}	
			?>
			<form action="" method="post" enctype="multipart/form-data">
				<h3> Titre du produit : </h3><input type="text" name="title"/>
				<h3> Description du produit : </h3><textarea name="description"></textarea>
				<h3> Prix : </h3><input type="text" name="price"/>€<br/>
				<h3> Image : </h3>
				<input type="file" name="img"/><br/>
				<h3> Categorie : </h3><select name="category">
				<?php
				$con=mysqli_connect("$url","$user","$passwd", "$dbname");
					// Check connection
				if (mysqli_connect_errno())
					echo "Failed to connect to MySQL: " . mysqli_connect_error();
				$result = mysqli_query($con, "SELECT * FROM category");
				if ( false===$result ) {
					printf("error: %s\n", mysqli_error($con));
				}
				while ($data = mysqli_fetch_assoc($result))
				{
					?>
					<option><?php echo $data["name"]; ?></option>
					<?php
				}
				?></select><br/><br/>
				<input type="submit" name="submit" value="Ajouter"/>
			</form>
			<?php
		}
		else if ($_GET['action'] == "set")
		{
			$con=mysqli_connect("$url","$user","$passwd", "$dbname");
			// Check connection
			if (mysqli_connect_errno())
				echo "Failed to connect to MySQL: " . mysqli_connect_error();
			$result = mysqli_query($con, "SELECT * FROM products");
			if ( false===$result )
				die("error: ".mysqli_error($con));
			while ($data = mysqli_fetch_assoc($result))
			{
				echo $data["title"];
				?>
				<a href="?action=modify&amp;id=<?php echo $data["id"];?>">Modifier</a>
				<a href="?action=del&amp;id=<?php echo $data["id"];?>">Supprimer</a><br/><br/>
				<?php
			}
			mysqli_close($con);
		}
		else if ($_GET['action'] == "del")
		{
			$con=mysqli_connect("$url","$user","$passwd", "$dbname");
			// Check connection
			if (mysqli_connect_errno())
				echo "Failed to connect to MySQL: " . mysqli_connect_error();
			$id = $_GET['id'];
			$result = mysqli_query($con, "DELETE FROM products WHERE id=$id");
			if ( false===$result )
				die("error: ".mysqli_error($con));
			mysqli_close($con);
		}
		else if ($_GET['action'] == "modify")
		{
			if (!isset($_GET["id"]))
				header("Location: admin.php");
			$id = $_GET["id"];
			if (isset($_POST['submit']))
			{	
				$title=$_POST["title"];
				$description = $_POST["description"];
				$price=$_POST["price"];
				if (!is_numeric($price))
					echo "Le prix doit etre numerique.";
				else
				{
					$con=mysqli_connect("$url","$user","$passwd", "$dbname");
					// Check connection
					if (mysqli_connect_errno())
						die("Failed to connect to MySQL: " . mysqli_connect_error());
					$result = mysqli_query($con, "UPDATE products SET title='$title', description='$description', price=$price WHERE id=$id");
					if ( false===$result )
						die ("error: ".mysqli_error($con));
					mysqli_close($con);
				}
				header("Location: admin.php?action=set");
			}

			$con=mysqli_connect("$url","$user","$passwd", "$dbname");
					// Check connection
			if (mysqli_connect_errno())
				echo "Failed to connect to MySQL: " . mysqli_connect_error();
			$result = mysqli_query($con, "SELECT * FROM products WHERE id=$id");
			if ( false===$result )
				printf("error: %s\n", mysqli_error($con));
			$data = mysqli_fetch_assoc($result);
			mysqli_close($con);
			?>
			<form action="" method="post">
				<h3> Titre du produit : </h3><input type="text" name="title" value='<?php echo $data['title'];?>'/>
				<h3> Description du produit : </h3><textarea name="description"><?php echo $data['description']; ?></textarea>
				<h3> Prix: </h3><input type="text" name="price" value='<?php echo $data['price'];?>'/>€<br/><br/>
				<h3> Image: </h3><img src="data:image/png;base64,<?php echo $data['img']?>"/><br/>

				<input type="file" name="img"/><br/>
				<h3> Categorie : </h3><select name="category">
				<?php
				$con=mysqli_connect("$url","$user","$passwd", "$dbname");
					// Check connection
				if (mysqli_connect_errno())
					echo "Failed to connect to MySQL: " . mysqli_connect_error();
				$result = mysqli_query($con, "SELECT * FROM category");
				if ( false===$result ) {
					printf("error: %s\n", mysqli_error($con));
				}
				while ($data = mysqli_fetch_assoc($result))
				{
					?>
					<option><?php echo $data["name"]; ?></option>
					<?php
				}
				?></select><br/><br/>
				<input type="submit" name="submit" value="Modifier"/>
			</form>
			<?php
		}
		else if ($_GET["action"]=="addcat")
		{
			if (isset($_POST["submit"]))
			{
				$name=$_POST["name"];
				if ($name)
				{
					$con=mysqli_connect("$url","$user","$passwd", "$dbname");
					// Check connection
					if (mysqli_connect_errno())
						echo "Failed to connect to MySQL: " . mysqli_connect_error();
					$result = mysqli_query($con, "INSERT INTO category (`id`, `name`) VALUES ('?', '$name')");
					if ( false===$result ) {
						printf("error: %s\n", mysqli_error($con));
					}
					mysqli_close($con);
				}
				else
				{
					echo "Veuillez remplir tout les champs";
				}

			}
			?>
			<form action="" method="post">
				<h3>Titre de la categorie : </h3><input type="text" name="name"/><br/><br/>
				<input type="submit" name="submit" value="Ajouter"/>
			</form>
			<?php	
		}
		else if ($_GET["action"]=="setcat")
		{
			$con=mysqli_connect("$url","$user","$passwd", "$dbname");
			// Check connection
			if (mysqli_connect_errno())
				echo "Failed to connect to MySQL: " . mysqli_connect_error();
			$result = mysqli_query($con, "SELECT * FROM category");
			if ( false===$result )
				die("error: ".mysqli_error($con));
			while ($data = mysqli_fetch_assoc($result))
			{
				echo $data["name"];
				?>
				<a href="?action=modifycat&amp;id=<?php echo $data["id"];?>">Modifier</a>
				<a href="?action=delcat&amp;id=<?php echo $data["id"];?>">Supprimer</a><br/><br/>
				<?php
			}
			mysqli_close($con);
		}		
		else if ($_GET["action"]=="modifycat")
		{
			if (!isset($_GET["id"]))
				header("Location: admin.php");
			$id = $_GET["id"];
			if (isset($_POST['submit']))
			{	
				$name=$_POST["name"];
				$con=mysqli_connect("$url","$user","$passwd", "$dbname");
				// Check connection
				if (mysqli_connect_errno())
					die("Failed to connect to MySQL: " . mysqli_connect_error());
				$result = mysqli_query($con, "UPDATE category SET name='$name' WHERE id=$id");
				if ( false===$result )
					die ("error: ".mysqli_error($con));	
				mysqli_close($con);
				header("Location: admin.php?action=setcat");
			}
			$con=mysqli_connect("$url","$user","$passwd", "$dbname");
					// Check connection
			if (mysqli_connect_errno())
				echo "Failed to connect to MySQL: " . mysqli_connect_error();
			$result = mysqli_query($con, "SELECT * FROM category WHERE id=$id");
			if ( false===$result )
				printf("error: %s\n", mysqli_error($con));
			$data = mysqli_fetch_assoc($result);
			mysqli_close($con);
			?>
			<form action="" method="post">
				<h3> Titre de la categorie : </h3><input type="text" name="name" value='<?php echo $data['name'];?>'/>
				<input type="submit" name="submit" value="Modifier"/>
			</form>
			<?php	
		}
		else if ($_GET["action"]=="delcat")
		{
			$con=mysqli_connect("$url","$user","$passwd", "$dbname");
			// Check connection
			if (mysqli_connect_errno())
				echo "Failed to connect to MySQL: " . mysqli_connect_error();
			$id = $_GET['id'];
			$result = mysqli_query($con, "DELETE FROM category WHERE id=$id");
			if ( false===$result )
				die("error: ".mysqli_error($con));
			mysqli_close($con);
			header("Location: admin.php?action=setcat");
		}
		else
		{
			die ("Une erreur s'est produite.");
		}
	}
}
else
{

	header("Location: ../index.php");
}
?>

