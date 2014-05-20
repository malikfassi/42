<?php
session_start();
?>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<link rel="stylesheet" href="includes/style/style.css" type="text/css"/>
</head>
<header>
</br><h1>Poke-Rush</h1></br>
<ul class="menu">
<li><a href="index.php">Accueil</a></li>
<li><a href="boutique.php">Boutique</a></li>
<?PHP
if(!isset($_SESSION["username"]))
{
echo '<li><a href="inscription.php">Inscription</a></li>';
echo '<li><a href="connexion.php">Connexion</a></li>';
}
if(isset($_SESSION["username"]))
{
	echo '<li><a href="deconnexion.php">Deconnexion</a></li>';
}
?>
</ul>
</header>
</html>
