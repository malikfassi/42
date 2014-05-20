<?PHP
error_reporting(E_ALL);
session_start();
if (!empty($_POST) && $_POST['submit'] == 'OK')
{
	if (!isset($_POST['login']) || !isset($_POST['passwd']))
	{
		echo "Veuillez remplir tous les champs\n";
?>
	<br />

<?php
		exit;
	}
$array = explode("\n", file_get_contents("admin/user.conf"));
$url = $array[0];
$user = $array[1];
$passwd = $array[2];
$dbname = $array[3];
$con=mysqli_connect("$url","$user","$passwd", "$dbname");
// Check connection
if (mysqli_connect_errno())
	echo "Failed to connect to MySQL: " . mysqli_connect_error();
$hashpswd = hash("whirlpool", $_POST["passwd"]);
$lg=$_POST["login"];
$result = mysqli_query($con, "SELECT * FROM users WHERE name='$lg'");
$data = mysqli_fetch_assoc($result);
if ($data["password"] == $hashpswd)
{
	$_SESSION["username"]=$lg;
	header("Location: index.php");
}
else
{
	header("Location : verif.php");
}
?>
	<br />
<?PHP	echo "Connection failed\n<a href='inscription.php'>Retry</a>" ?>
<?php
		exit;
	}

