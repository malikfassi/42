<?php
$array = explode("\n", file_get_contents("admin/user.conf"));
$url = $array[0];
$user = $array[1];
$passwd = $array[2];
$dbname = $array[3];
require('includes/header.php');
require('includes/sidebar.php');
if (isset($_GET["show"]))
{
	$product = $_GET["show"];
	$con=mysqli_connect("$url","$user","$passwd", "$dbname");
	// Check connection
	if (mysqli_connect_errno())
		echo "Failed to connect to MySQL: " . mysqli_connect_error();
	$result = mysqli_query($con, "SELECT * FROM products WHERE id=$product");
	if ( false===$result )
		die("error: ".mysqli_error($con));
	$data = mysqli_fetch_assoc($result);
	?>
		</br></br>
		<div style="text-align:center;">		
		<a href="?show=<?php echo $data['id']?>"><img src="data:image/png;base64,<?php echo $data['img']?>"/></a>
		<h2><?php echo $data["title"];?></h2>
		<h5><?php echo $data["description"];?></h5>
		<h4><?php echo $data["price"];?>€</h4>
		</div>
		<?php
}
else if (isset($_GET["category"]))
{

	$con=mysqli_connect("$url","$user","$passwd", "$dbname");
// Check connection
	$category = $_GET["category"];
	if (mysqli_connect_errno())
		echo "Failed to connect to MySQL: " . mysqli_connect_error();
	$result = mysqli_query($con, "SELECT * FROM products WHERE category='$category'");
	if ( false===$result )
		die("error: ".mysqli_error($con));
	while ($data = mysqli_fetch_assoc($result))
	{
		?>
		</br></br>
		<div style="text-align:center;">		
		<a href="?show=<?php echo $data['id']?>"><img src="data:image/png;base64,<?php echo $data['img']?>"/></a>
		<h2><?php echo $data["title"];?></h2>
		<h5><?php echo $data["description"];?></h5>
		<h4><?php echo $data["price"];?>€</h4>
		</div>
		<?php
	}
	mysqli_close($con);
}
else
{
	$con=mysqli_connect("$url","$user","$passwd", "$dbname");
// Check connection
	if (mysqli_connect_errno())
		echo "Failed to connect to MySQL: " . mysqli_connect_error();
	$result = mysqli_query($con, "SELECT * FROM category");
	if ( false===$result )
		printf("error: %s\n", mysqli_error($con));
	while ($data=mysqli_fetch_assoc($result))
	{
		?>
		<a href="?category=<?php echo $data["name"];?>"><h3><?php echo $data["name"]?></h3></a>

		<?php

	}
	mysqli_close($con);
}
require('includes/footer.php');

?>