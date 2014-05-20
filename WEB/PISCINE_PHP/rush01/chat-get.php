<?php

include('connection.php');

$reponse = $bdd->query('SELECT * FROM t_chat ORDER BY id DESC LIMIT 10');

while ($donnees = $reponse->fetch())
{
	$color = ($donnees['id'] % 2 == 0 ? 'red' : 'green');
	echo '<p style="color: '.$color.'">
		<strong>' . htmlspecialchars($donnees['login']) . '</strong>
		('.htmlspecialchars($donnees['date']).') : 
		' . htmlspecialchars($donnees['text']) . '</p>';
}

$reponse->closeCursor();
$bdd = NULL;

?>
