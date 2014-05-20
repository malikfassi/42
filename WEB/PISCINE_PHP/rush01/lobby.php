<?php
session_start();
if (isset($_POST['player']))
	$_SESSION['player'] = $_POST['player'];
$player = $_SESSION['player'];
include('connection.php');
$req = $bdd->prepare('SELECT * FROM party WHERE running=0 AND player < 4');
$req->execute();
$bol = 1;
$bol2 = 1;
while ($test = $req->fetch())
{
	$bol2 = 0;
	$id = $test['id'];
	$nb_player = $test['player'];
	$_SESSION['player1'] = $test['player_1_login'];
	$_SESSION['player2'] = $test['player_2_login'];
	$_SESSION['player3'] = $test['player_3_login'];
	$_SESSION['player4'] = $test['player_4_login'];
	$_SESSION['player1_obj'] = $test['player_1_obj'];
	$_SESSION['player2_obj'] = $test['player_2_obj'];
	$_SESSION['player3_obj'] = $test['player_3_obj'];
	$_SESSION['player4_obj'] = $test['player_4_obj'];
	if ($player === $test['player_1_login'] || $player === $test['player_2_login'] || $player === $test['player_3_login'] || $player === $test['player_4_login'])
	{
		$bol = 0 ;
		$_SESSION['player1'] = $test['player_1_login'];
		$_SESSION['player2'] = $test['player_2_login'];
		$_SESSION['player3'] = $test['player_3_login'];
		$_SESSION['player4'] = $test['player_4_login'];
		$_SESSION['player1_obj'] = $test['player_1_obj'];
		$_SESSION['player2_obj'] = $test['player_2_obj'];
		$_SESSION['player3_obj'] = $test['player_3_obj'];
		$_SESSION['player4_obj'] = $test['player_4_obj'];
		$id = $test['id'];
		$_SESSION['id_party'] = $id;
		$nb_player = $test['player'];
		break ;
	}
	$req->closeCursor();
}
if ($bol2 === 1 && !isset($_SESSION['id_party']))
{
	$req = $bdd->prepare('INSERT INTO party (`running`, `turn`, `player`) VALUES (0, 0, 0)');
	$req->execute();
	//   $req->closeCursor();
//	$req = 'SELECT id FROM party WHERE running=0 AND player < 4';
	$req = $bdd->prepare('SELECT * FROM party WHERE running=0 AND player < 4');
	$req->execute();
//    $req->closeCursor(); //nononononoonononono

	$bol = 1;
	while ($test = $req->fetch())
//    foreach ($bdd->query($req) as $test)
        $id = $test['id'];
	$nb_player = 0;

}
if ($bol === 1 && !isset($_SESSION['id_party']))
{
	$nb_player++;
	$_SESSION['player_id'] = $nb_player;
	$_SESSION['id_party'] = $id;
	$str = "player_".$nb_player."_login";
	$req = $bdd->prepare("UPDATE `party` SET `player`=".$nb_player." , `".$str."`='".$player."' where  id=".$id);
	$req->execute();
	$req->closeCursor();
}
else if (isset($_SESSION['id_party']))
{
	$req = 'SELECT * FROM party WHERE id='.$_SESSION['id_party'];
    $bol = 1;
    foreach ($bdd->query($req) as $test)
    {
        $nb_player = $test['player'];
        $_SESSION['player1'] = $test['player_1_login'];
		$_SESSION['player2'] = $test['player_2_login'];
		$_SESSION['player3'] = $test['player_3_login'];
		$_SESSION['player4'] = $test['player_4_login'];
		$_SESSION['player1_obj'] = $test['player_1_obj'];
		$_SESSION['player2_obj'] = $test['player_2_obj'];
		$_SESSION['player3_obj'] = $test['player_3_obj'];
		$_SESSION['player4_obj'] = $test['player_4_obj'];
    }
}
	$bdd = NULL;
?>
<html>
	<head>
		<link href="lobby.css" rel="stylesheet">
	</head>
	<body>
		<div id="principal">
			Let's go !
			<?php
			if ($nb_player == 1)
			{
				echo "Sorry $player you have to wait for another player ... Patiente";
				header("Refresh: 5; url=lobby.php");
				?>
				<div class="spinner">
				    <div class="piece a"> </div>
				    <div class="piece b"> </div>
				    <div class="piece c"> </div>
				    <div class="piece d"> </div>
				    <div class="piece e"> </div>
				    <div class="piece f"> </div>
				    <div class="piece g"> </div>
				    <div class="piece h"> </div>
				    <div class="piece i"> </div>
				    <div class="piece j"> </div>
				    <div class="piece k"> </div>
				    <div class="piece l"> </div>
				    <div class="piece m"> </div>
				    <div class="piece n"> </div>
				    <div class="piece o"> </div>
				    <div class="piece p"> </div>
				</div>
				<?php
					
			}
			else if ($nb_player > 1 && $nb_player <= 4)
			{
				echo "<form method='post' action='init_session.php' ><input type='submit' name='submit' value='PLAY !' id='button'></form><br/>";
				if ($_SESSION['player1'] != NULL || $_SESSION['player_id'] === 1)
				{
					if ($_SESSION['player_id'] === 1)
					$_SESSION['player1'] = $_SESSION['player'];
					echo "<span>Player 1: ".$_SESSION['player1'].".";
					if ($_SESSION['player1_obj'] != NULL)
						echo " Pret!";
					echo "</span><br/>";
				}
				if ($_SESSION['player2'] != NULL || $_SESSION['player_id'] === 2)
				{
					if ($_SESSION['player_id'] === 2)
					$_SESSION['player2'] = $_SESSION['player'];
					echo "<span>Player 2: ".$_SESSION['player2'].".";
					if ($_SESSION['player2_obj'] != NULL)
						echo " Pret!";
					echo "</span><br/>";
				}
				if ($_SESSION['player3'] != NULL || $_SESSION['player_id'] === 3)
				{
					if ($_SESSION['player_id'] === 3)
					$_SESSION['player3'] = $_SESSION['player'];
					echo "<span>Player 3: ".$_SESSION['player3'].".";
					if ($_SESSION['player3_obj'] != NULL)
						echo " Pret!";
					echo "</span><br/>";
				}
				if ($_SESSION['player4'] != NULL || $_SESSION['player_id'] === 4)
				{
					if ($_SESSION['player_id'] === 4)
					$_SESSION['player4'] = $_SESSION['player'];
					echo "<span>Player 4: ".$_SESSION['player4'].".";
					if ($_SESSION['player4_obj'] != NULL)
						echo " Pret!";
					echo "</span><br/>";
				}
			}
			else
			{
				echo "Sorry, too many players on our very popular game, come back later !";
				header("Refresh: 5; url=index.php");
			}
			?>
		</div>
	</body>
</html>