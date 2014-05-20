<?php

require_once("Pawn.class.php");
require_once("Ship.class.php");
require_once("Player.class.php");
require_once("Weapon.class.php");

function get_board()
{
	include('connection.php');
	$req = "SELECT player_1_obj, player_2_obj, player_3_obj, player_4_obj, asteroid FROM party WHERE id=".$_SESSION['id_party']."";
	$pl = array();
	$asteroid = array();
	foreach ($bdd->query($req) as $test)
	{
		if ($test['player_1_obj'] !== "")
			$pl[] = unserialize($test['player_1_obj']);
		if ($test['player_2_obj'] !== "")
			$pl[] = unserialize($test['player_2_obj']);
		if ($test['player_3_obj'] !== "")
			$pl[] = unserialize($test['player_3_obj']);
		if ($test['player_4_obj'] !== "")
			$pl[] = unserialize($test['player_4_obj']);
		if ($test['asteroid'] !== "")
			$asteroid = unserialize($test['asteroid']);
	}
	$board = array_fill(0, 100, array_fill(0, 150, -1));
	foreach ($pl as $key => $player)
	{
		foreach ($player->getShips() as $pl)
		{
			$i = 0;
			$j = 1;
			$tab = $pl->getPos();
			$dim = $pl->getDim();
			$board[$tab[1]][$tab[0]] = array($pl->getId(), $pl->getOrientation(), $pl->getHealth());
			while ($i < $dim[1])
			{
				while ($j < $dim[0])
				{
					$board[$tab[1] + $i][$tab[0] + $j] = $pl->getId() * 10;
					$j++;
				}
				$j = 0;
				$i++;
			}
		}
	}
	foreach ($asteroid as $ast)
	{
		$i = 0;
		$j = 1;
		$tab = $ast->getPos();
		$dim = $ast->getDim();
		$board[$tab[1]][$tab[0]] = $ast->getId();
		while ($i < $dim[1])
		{
			while ($j < $dim[0])
			{
				$board[$tab[1] + $i][$tab[0] + $j] = 5;
				$j++;
			}
			$j = 0;
			$i++;
		}
	}
	return $board;
}

?>
