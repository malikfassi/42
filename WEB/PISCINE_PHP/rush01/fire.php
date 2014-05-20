<?php

require_once("Pawn.class.php");
require_once("Ship.class.php");
require_once("Player.class.php");
require_once("Weapon.class.php");
require_once("get_board.php");
require_once("board.php");
require_once("play.php");
require_once('Serial.trait.php');

function	fire_in_the_hole($a, $b)
{
	$hit = array($b, $a);
    include('connection.php');
    $req = 'SELECT player_1_obj, player_2_obj, player_3_obj, player_4_obj FROM party WHERE `id`=1';
  //  $bol = 1;
	$players = array();
    foreach ($bdd->query($req) as $test)
    {
		if ($test['player_1_obj'] !== "")
			$players[] = $test['player_1_obj'];
		if ($test['player_2_obj'] !== "")
			$players[] = $test['player_2_obj'];
		if ($test['player_3_obj'] !== "")
			$players[] = $test['player_3_obj'];
		if ($test['player_4_obj'] !== "")
			$players[] = $test['player_4_obj'];
    }
	$bol = 1;
	foreach ($players as $key => $player)
	{
		foreach ($player->ships as &$ship)
		{
			if ($ship->is_take_damage($hit, -20))
			{
				echo $ship->getName()." => ".$ship->getHealth();
				$bol = 0;
				$str = "`player_".($key + 1)."_obj='".$player->getSerial()."'";
    			$req = $bdd->prepare("UPDATE `party` SET $str WHERE `id`=1");
 				$req->execute();
    			$req->closeCursor();
				$_SESSION['player_id_hit'] = $key + 1;
				$_SESSION['hit_obj'] = $player->getSerial();
				break;
			}
		}
		if (!$bol)
			break;
	}
}

function	down_fire($pos, $range, $tab, $player, $pa, $bol)
{
	$i = $pos[1] + 1;
	while ($tab[$i][$pos[0]] == $_SESSION['player_id'])
		$i++;
	while ($bol < $range && $i < 100 && $tab[$i][$pos[1]] == -1)
	{
		$i++;
		$bol++;
	}
	if ($bol < $range && $i < 100)
	{
		if ($tab[$i][$pos[0]] == 3 || ($tab[$i][$pos[0]] >= 24 && $tab[$i][$pos[0]] <= 29))
		{
			$pa->setHealth(-3);
			$_SESSION['asteroid'] = serialize($pa);
		}
		else
		{
			fire_in_the_hole($i, $pos[0]);
			$_SESSION['player_obj'] = $player->getSerial();
		}
	}
}

function	up_fire($pos, $range, $tab, $player, $pa, $bol)
{
	$i = $pos[1] - 1;
	while ($tab[$i][$pos[0]] == $_SESSION['player_id'])
		$i++;
	while ($bol < $range && $i >= 0 && $tab[$i][$pos[0]] == -1)
	{
		$i--;
		$bol++;
	}
	if ($bol < $range && $i >= 0)
	{
		if ($tab[$i][$pos[0]] == 3 || ($tab[$i][$pos[0]] >= 24 && $tab[$i][$pos[0]] <= 29))
		{
			$pa->setHealth(-3);
			$_SESSION['asteroid'] = serialize($pa);
		}
		else
		{
			fire_in_the_hole($i, $pos[0]);
			$_SESSION['player_obj'] = $player->getSerial();
		}
	}
}

function	right_fire($pos, $range, $tab, $player, $pa, $bol)
{
	$i = $pos[0] + 2;
	while ($tab[$pos[1]][$i] == $_SESSION['player_id'])
		$i++;
	while ($bol < $range && $i < 150 && $tab[$pos[1]][$i] == -1)
	{
		$i++;
		$bol++;
	}
	if ($bol < $range && $i < 150)
	{
		if ($tab[$pos[1]][$i] == 3 || ($tab[$pos[1]][$i] >= 24 && $tab[$pos[1]][$i] <= 29))
		{
			$pa->setHealth(-3);
			$_SESSION['asteroid'] = serialize($pa);
		}
		else
		{
			fire_in_the_hole($pos[1], $i);
			$_SESSION['player_obj'] = $player->getSerial();
		}
	}
}

function	left_fire($pos, $range, $tab, $player, $pa, $bol)
{
	$i = $pos[0] - 1;
	while ($tab[$pos[1]][$i] == $_SESSION['player_id'])
		$i--;
	while ($bol < $range && $i >= 0 && $tab[$pos[1]][$i] == -1)
	{
		$i--;
		$bol++;
	}
	if ($bol < $range && $i >= 0)
	{
		if ($tab[$pos[1]][$i] == 3 || ($tab[$pos[1]][$i] >= 24 && $tab[$pos[1]][$i] <= 29))
		{
			$pa->setHealth(-3);
			$_SESSION['asteroid'] = serialize($pa);
		}
		else
		{
			fire_in_the_hole($pos[1], $i);
			$_SESSION['player_obj'] = $player->getSerial();
		}
	}
}

function	make_fire()
{
	$player = unserialize($_SESSION['player_obj']);
	$pa = unserialize($_SESSION['asteroid']);
	$tab = get_board();
	$range = 35;
	$bol = 1;

	$pos = $player->ships[$_SESSION['index_ship']]->getPos();
	$or = $player->ships[$_SESSION['index_ship']]->getOrientation();

	if ($or == "right")
		right_fire($pos, $range, $tab, $player, $pa, $bol);
	else if ($or == "left")
		left_fire($pos, $range, $tab, $player, $pa, $bol);
	else if ($or == "up")
		up_fire($pos, $range, $tab, $player, $pa, $bol);
	else
		down_fire($pos, $range, $tab, $player, $pa, $bol);
}

?>
