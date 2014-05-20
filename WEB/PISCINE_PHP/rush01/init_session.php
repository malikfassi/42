<?php
session_start();


require_once("get_board.php");
require_once("Pawn.class.php");
require_once("Ship.class.php");
require_once("Player.class.php");
require_once("Weapon.class.php");
require_once("Serial.trait.php");

var_dump($_SESSION);

if (!isset($_SESSION['init_game']))
	die ("FATAL ERROR" . PHP_EOL);
else
{
	if ($_SESSION['init_game'] === 1)
	{
		if ($_POST['submit'] === "PLAY !" && $_SESSION['player'] !== "")
		{
			$army = array();
			$asteroids = array();

			if ($_SESSION['player_id'] === 1)
			{
				$army[] = new Ship (array ('id' => 10, 'name' => "Wrath of the Empire", 'health' => 25, 'dim' => array(10, 5), 'faction' => $_SESSION['player'], 'pos' => array(1, 2), 'speed' => 25, 'max_shield' => 10, 'power' => 15, 'orientation' => '0deg'));
				$army[] = new Ship (array ('id' => 11, 'name' => "Star of Galaxy", 'health' => 8, 'dim' => array(5, 3), 'faction' => $_SESSION['player'], 'pos' => array(1, 20), 'speed' => 8, 'max_shield' => 10, 'power' => 5, 'orientation' => '0deg'));
				$army[] = new Ship (array ('id' => 12, 'name' => "Blood Angels", 'health' => 15, 'dim' => array(7, 4), 'faction' => $_SESSION['player'], 'pos' => array(1, 10), 'speed' => 15, 'max_shield' => 10, 'power' => 10, 'orientation' => '0deg'));
				$army[] = new Ship (array ('id' => 13, 'name' => "Ultramarines", 'health' => 8, 'dim' => array(5, 3), 'faction' => $_SESSION['player'], 'pos' => array(15, 2), 'speed' => 8, 'max_shield' => 10, 'power' => 5, 'orientation' => '0deg'));
				$asteroids[] = new Pawn (array ('id' => 26, 'name' => "Asteroid 1", 'health' => 100, 'dim' => array(9, 9), 'pos' => array(45, 10)));
				$asteroids[] = new Pawn (array ('id' => 27, 'name' => "Asteroid 2", 'health' => 100, 'dim' => array(5, 5), 'pos' => array(100, 20)));
				$asteroids[] = new Pawn (array ('id' => 28, 'name' => "Asteroid 3", 'health' => 100, 'dim' => array(5, 5), 'pos' => array(75, 50)));
				$asteroids[] = new Pawn (array ('id' => 29, 'name' => "Asteroid 4", 'health' => 100, 'dim' => array(5, 5), 'pos' => array(45, 70)));
				$asteroids[] = new Pawn (array ('id' => 30, 'name' => "Asteroid 5", 'health' => 100, 'dim' => array(5, 5), 'pos' => array(40, 50)));
				$asteroids[] = new Pawn (array ('id' => 31, 'name' => "Asteroid 6", 'health' => 100, 'dim' => array(9, 9), 'pos' => array(100, 80)));
			}
			else if ($_SESSION['player_id'] === 2)
			{
				$army[] = new Ship (array ('id' => 18, 'name' => "Rabbi Jacob", 'health' => 20, 'dim' => array(5, 3), 'faction' => $_SESSION['player'], 'pos' => array(125, 2), 'speed' => 10, 'max_shield' => 10, 'power' => 5, 'orientation' => '180deg'));
				$army[] = new Ship (array ('id' => 19, 'name' => "Israel Battleship", 'health' => 20, 'dim' => array(7, 4), 'faction' => $_SESSION['player'], 'pos' => array(140, 15), 'speed' => 10, 'max_shield' => 10, 'power' => 10, 'orientation' => '180deg'));
				$army[] = new Ship (array ('id' => 20, 'name' => "Shabbat Shalom", 'health' => 20, 'dim' => array(5, 3), 'faction' => $_SESSION['player'], 'pos' => array(140, 25), 'speed' => 10, 'max_shield' => 10, 'power' => 5, 'orientation' => '180deg'));
				$army[] = new Ship (array ('id' => 21, 'name' => "Jew Counter-Attacks", 'health' => 20, 'dim' => array(10, 5), 'faction' => $_SESSION['player'], 'pos' => array(135, 2), 'speed' => 10, 'max_shield' => 10, 'power' => 15, 'orientation' => '180deg'));
			}
			else if ($_SESSION['player_id'] === 3)
			{
				$army[] = new Ship (array ('id' => 14, 'name' => "Dreadclaw", 'health' => 20, 'dim' => array(5, 3), 'faction' => $_SESSION['player'], 'pos' => array(1, 65), 'speed' => 10, 'max_shield' => 10, 'power' => 5, 'orientation' => '0deg'));
				$army[] = new Ship (array ('id' => 15, 'name' => "Storm Bird", 'health' => 20, 'dim' => array(7, 4), 'faction' => $_SESSION['player'], 'pos' => array(1, 75), 'speed' => 10, 'max_shield' => 10, 'power' => 10, 'orientation' => '0deg'));
				$army[] = new Ship (array ('id' => 16, 'name' => "Vengeful Spirit", 'health' => 20, 'dim' => array(5, 3), 'faction' => $_SESSION['player'], 'pos' => array(15, 85), 'speed' => 10, 'max_shield' => 10, 'power' => 5, 'orientation' => '0deg'));
				$army[] = new Ship (array ('id' => 17, 'name' => "Drone Tsahal", 'health' => 20, 'dim' => array(10, 5), 'faction' => $_SESSION['player'], 'pos' =>array(1, 85), 'speed' => 10, 'max_shield' => 10, 'power' => 15, 'orientation' => '0deg'));
			}
			else if ($_SESSION['player_id'] === 4)
			{
				$army[] = new Ship (array ('id' => 22, 'name' => "David's Death Star", 'health' => 20, 'dim' => array(5, 3), 'faction' => $_SESSION['player'], 'pos' => array(140, 65), 'speed' => 10, 'max_shield' => 10, 'power' => 5, 'orientation' => '180deg'));
				$army[] = new Ship (array ('id' => 23, 'name' => "David petit gros", 'health' => 20, 'dim' => array(7, 4), 'faction' => $_SESSION['player'], 'pos' => array(125, 85), 'speed' => 10, 'max_shield' => 10, 'power' => 10, 'orientation' => '180deg'));
				$army[] = new Ship (array ('id' => 24, 'name' => "Alexis bouffon", 'health' => 20, 'dim' => array(10, 5), 'faction' => $_SESSION['player'], 'pos' => array(135, 85), 'speed' => 10, 'max_shield' => 10, 'power' => 15, 'orientation' => '180deg'));
				$army[] = new Ship (array ('id' => 25, 'name' => "Martin le chauve", 'health' => 20, 'dim' => array(5, 3), 'faction' => $_SESSION['player'], 'pos' => array(140, 75), 'speed' => 10, 'max_shield' => 10, 'power' => 5, 'orientation' => '180deg'));
			}


			$player =  new Player ($_SESSION['player'], $army);
			$player = $player->getSerial();
			$asteroid = serialize($asteroids);
			include('connection.php');
			$str = "player_".$_SESSION['player_id']."_obj";
			$id_party = $_SESSION['id_party'];
			if ($_SESSION['player_id'] === 1)
				$test = "UPDATE party SET asteroid='".$asteroid."' , ".$str."='".$player."', turn=1, running=1 where id=".$id_party.';';
			else
				$test = "UPDATE party SET ".$str."='".$player."' , turn=1 where id=".$id_party.';';
			$bdd->exec($test);
			//$req = $bdd->prepare($test);
			//$req->execute();
			//$req->closeCursor();
			$_SESSION['select'] = 1;
			$_SESSION['order'] = 0;
			$_SESSION['mvt'] = 0;
			$_SESSION['fire'] = 0;
			$_SESSION['move'] = 0;
			$_SESSION['col'] = 0;
			$_SESSION['first'] = 1;
//			$_SESSION['board'] = get_board(unserialize($_SESSION['player_1']), unserialize($_SESSION['player_2']), unserialize($_SESSION['asteroid']));
		}

		header('Location: loading.php');
	}
}


?>
