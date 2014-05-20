<?php

//session_start();

require_once("board.php");
require_once("fire.php");

function end_turn()
{

		if ($_SESSION['select'])
		{
			$_SESSION['select'] = 0;
			$_SESSION['order'] = 1;
		}
		else if ($_SESSION['order'])
		{
			$_SESSION['order'] = 0;
			$_SESSION['mvt'] = 1;
		}
		else if ($_SESSION['mvt'])
		{
			$_SESSION['mvt'] = 0;
			$_SESSION['make_move'] = 1;
		}
		else if ($_SESSION['make_move'])
		{
			$_SESSION['make_move'] = 0;
			$_SESSION['fire'] = 1;
		}
		else
		{
			$_SESSION['fire'] = 0;
			$_SESSION['select'] = 1;
			include('connection.php');
			$req = $bdd->prepare("UPDATE `party` SET turn = (turn % player) + 1  where id=".$_SESSION['id_party']);
			$req->execute();
			$req->closeCursor();
		}
}

function	kill_ship()
{

    include('connection.php');

    $req = "SELECT player_1_obj, player_2_obj, player_3_obj, player_4_obj, asteroid FROM party WHERE `id`=".$_SESSION['id_party']."";
	$pl = array();
	foreach ($bdd->query($req) as $test)
	{
		if ($test['player_1_obj'] !== "")
		{
			$player = unserialize($test['player_1_obj']);
			foreach ($player->getShips() as $i => $ship)
			{
				if ($ship->getHealth() <= 0)
				{
					$player->ships[$i]->__destruct();
					unset($player->ships[$i]);
					$player->ships = array_filter($player->ships);
				}
			}
		}
		if ($test['player_2_obj'] !== "")
		{
			$player = unserialize($test['player_2_obj']);
			foreach ($player->getShips() as $i => $ship)
			{
				if ($ship->getHealth() <= 0)
				{
					$player->ships[$i]->__destruct();
					unset($player->ships[$i]);
					$player->ships = array_filter($player->ships);
				}
			}
		}
		if ($test['player_3_obj'] !== "")
		{
			$player = unserialize($test['player_3_obj']);
			foreach ($player->getShips() as $i => $ship)
			{
				if ($ship->getHealth() <= 0)
				{
					$player->ships[$i]->__destruct();
					unset($player->ships[$i]);
					$player->ships = array_filter($player->ships);
				}
			}
		}
		if ($test['player_4_obj'] !== "")
		{
			$player = unserialize($test['player_4_obj']);
			foreach ($player->getShips() as $i => $ship)
			{
				if ($ship->getHealth() <= 0)
				{
					$player->ships[$i]->__destruct();
					unset($player->ships[$i]);
					$player->ships = array_filter($player->ships);
				}
			}
		}
		if ($test['asteroid'] !== "")
		{
			$as = unserialize($test['asteroid']);
		}
	}

}

function	turn()
{

	if ($_SESSION['select'])
	{
		include('connection.php');
		$req = "SELECT player_1_obj, player_2_obj, player_3_obj, player_4_obj, asteroid FROM party WHERE `id`=".$_SESSION['id_party']."";
		$pl = array();
		foreach ($bdd->query($req) as $test)
		{
			if ($test['player_1_obj'] !== "" && intval($_SESSION['player_id']) === 1)
				$_SESSION['player_obj'] = $test['player_1_obj'];
			if ($test['player_2_obj'] !== "" && intval($_SESSION['player_id']) === 2)
				$_SESSION['player_obj'] = $test['player_2_obj'];
			if ($test['player_3_obj'] !== "" && intval($_SESSION['player_id']) === 3)
				$_SESSION['player_obj'] = $test['player_3_obj'];
			if ($test['player_4_obj'] !== "" && intval($_SESSION['player_id']) === 4)
				$_SESSION['player_obj'] = $test['player_4_obj'];
			if ($test['asteroid'] !== "")
				$_SESSION['asteroid'] = $test['asteroid'];
		}
		make_select();
	}
	else if ($_SESSION['order'])
	{
//			$move = 1;
		make_order($_POST);
	}
	else if ($_SESSION['mvt'])
	{
//			$move = 1;
		make_mvt($_POST);
	}
	else if ($_SESSION['make_move'])
	{
//			$move = 1;
		make_move($_POST);
	}
	else
	{
//			$move = 1;
		make_fire();
	}
	if (kill_ship()) //a checker7
	{
		$_SESSION['select'] = 1;
		$_SESSION['order'] = 0;
		$_SESSION['mvt'] = 0;
		$_SESSION['make_move'] = 0;
		$_SESSION['fire'] = 0;

		include('connection.php');

		$req = $bdd->prepare("UPDATE `party` SET turn = (turn % player) + 1  where id=".$_SESSION['id_party']);
		$req->execute();
		$req->closeCursor();

	}
}

?>
