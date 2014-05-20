<?php
session_start();
$user = "rush";
$password2 ="rush";
if(isset($_POST["submit"]))
{
	$username = $_POST["username"];
	$password = $_POST["password"];
	if ($username && $password)
	{
		if ($username == $user && $password2 == $password)
		{
			$_SESSION["username"]=$username;
			header("Location: admin.php");
		}
		else
		{
			echo "Identifiants errone";
		}
	}
	else
	{
		echo "Veuillez remplir tous les champs !";
	}
}
?>
<link rel="stylesheet" href="../style/style.css" type="text/css"/>
<meta charset="utf-8">

<h1> Administration - Connexion</h1>
<form action="" method="POST">

<h3>Username :</h3><input type="text" name="username"/><br/><br/>
<h3>Mot-de-passe :</h3><input type="password" name="password"/><br/><br/>
<input type="submit" name="submit"/><br/><br/>

</form>