<?PHP
error_reporting(E_ALL);
if (!empty($_POST) && $_POST['submit'] == 'OK')
{
	if (!$_POST['login'] || !$_POST['passwd'] || !$_POST['passwd2'])
	{
		echo "Veuillez remplir tous les champs\n";
?>
	<br />
	<li><a href="index.php">retour au menu principal</a></li><br />
	<li><a href="inscription.php">recommencer inscription</a></li>
<?php
		exit;
	}
	if ($_POST['passwd2'] != $_POST['passwd'])
	{
		echo "erreur mot de passe\n\n";
?>
	<br />
	<li><a href="index.php">retour au menu principal</a></li><br />
	<li><a href="inscription.php">recommencer inscription</a></li>
<?php
		exit;
	}
	if (isset($_POST['login']))
	{
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
$result = mysqli_query($con, "INSERT INTO users(`id`, `name`, `password`) VALUES ('?', '$lg', '$hashpswd')");
if ( false===$result )
{
	die("error: ".mysqli_error($con));
}
session_start();
$_SESSION["username"] = $lg;
header("Location: index.php");
}
}
?>
