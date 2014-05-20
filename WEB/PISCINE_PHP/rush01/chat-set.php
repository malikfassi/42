<?php

session_start();
date_default_timezone_set('Europe/Paris');

include('connection.php');

if (isset($_SESSION['player'], $_POST['text']))
{
	$req = $bdd->prepare('INSERT INTO t_chat (login, text, date) VALUES(?, ?, ?)');
//	$req->bindParam(1, $_POST['login']);
	$req->bindParam(1, $_SESSION['player']);
	$req->bindParam(2, $_POST['text']);
	$req->bindParam(3, date("Y-m-d H:i:s"));
	$req->execute();
}

$req->closeCursor();
$bdd = NULL;
?>
