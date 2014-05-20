<link rel="stylesheet" href="includes/style/style.css" type="text/css"/>
<div class="sidebar">
<h4>Derniers articles</h4>
<?php
$array = explode("\n", file_get_contents("admin/user.conf"));
$url = $array[0];
$user = $array[1];
$passwd = $array[2];
$dbname = $array[3];
$con=mysqli_connect("$url","$user","$passwd", "$dbname");
// Check connection
if (mysqli_connect_errno())
	echo "Failed to connect to MySQL: " . mysqli_connect_error();
$result = mysqli_query($con, "SELECT * FROM products ORDER BY id DESC LIMIT 0,3");
if ( false===$result )
	die("error: ".mysqli_error($con));
while ($data = mysqli_fetch_assoc($result))
{
		?>
		<div style="text-align:center;">
		<a href="?show=<?php echo $data['id']?>"><img style="height:100px; width: 100px"	 src="data:image/png;base64,<?php echo $data['img']?>"/></a>
		<h2><?php echo $data["title"];?></h2>
		<h5><?php echo $data["description"];?></h5>
		<h4><?php echo $data["price"];?>€</h4><br/>
		</div>
		<?php
}
mysqli_close($con);
?>
</div>
