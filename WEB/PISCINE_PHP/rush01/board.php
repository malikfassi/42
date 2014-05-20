<?php

require_once("Pawn.class.php");
require_once("Ship.class.php");
require_once("Player.class.php");
require_once("Weapon.class.php");
require_once("get_board.php");
require_once('Serial.trait.php');

function	make_select()
{
	$player = unserialize($_SESSION['player_obj']);
	$ships = $player->getShips();
	$print_ship = array();
	foreach ($ships as $ship)
		$print_ship[] = $ship->getName();
	$_SESSION['print_ship'] = $print_ship;
	$_SESSION['player_obj'] = $player->getSerial();
}

function	make_order($array)
{
	$player = unserialize($_SESSION['player_obj']);
	$ships = $player->getShips();
	foreach ($ships as $i => $ship)
	{
		if ($ship->getName() === $array['ship_to_play'])
		{
			$_SESSION['ship_power'] = $ship->getPower();
			$_SESSION['ship_to_play'] = $array['ship_to_play'];
			$_SESSION['index_ship'] = $i;
			$_SESSION['ship_orientation'] = $ship->getOrientation();
			break ;
		}
	}
	$_SESSION['player_obj'] = $player->getSerial();
}

function	make_mvt($array)
{
	$player = unserialize($_SESSION['player_obj']);
	$ships = $player->getShips();
	$ship = $ships[$_SESSION['index_ship']];
	if (isset($array['bonus_speed']))
		$ship->setBonus_speed($array['bonus_speed']);
	$_SESSION['ship_speed'] = $ship->getSpeed();
	if (isset($array['bonus_shield']))
		$ship->setShield($array['bonus_shield']);
	if (isset($array['bonus_weapon']))
		$ship->setBonus_Weapon($array['bonus_weapon']);
	$_SESSION['ship_mvt'] = $ship->getSpeed();
	$_SESSION['player_obj'] = $player->getSerial();
}

function	check_collision($grid, $x, $y, $dim, $id)
{
	$i = 0;
	$j = 0;
	while ($i < $dim[1])
	{
		while ($j < $dim[0])
		{
			if ($grid[$i + $y][$j + $x] !== -1 && $grid[$i + $y][$j + $x] !== $id / 10)
				return 1;
			$j++;
		}
		$j = 0;
		$i++;
	}
	return -1;
}

function	make_move($array)
{
	// $player = making($move, 0, NULL);
	$player = unserialize($_SESSION['player_obj']);
	$ships = $player->getShips();
	$ship = $ships[$_SESSION['index_ship']];
	$grid = get_board();
	// $grid = $_SESSION['board'];
	$pos = $ship->getPos();
	$dim = $ship->getDim();
	if (isset($array['ship_orientation']) && $array['ship_orientation'] === "left")
	{
		if ($ship->getOrientation() === "0deg")
			$ship->setOrientation("-90deg");
		else if ($ship->getOrientation() === "-90deg")
			$ship->setOrientation("180deg");
		else if ($ship->getOrientation() === "180deg")
			$ship->setOrientation("90deg");
		else if ($ship->getOrientation() === "90deg")
			$ship->setOrientation("0deg");
	}
	else if (isset($array['ship_orientation']) && $array['ship_orientation'] === "right")
	{
		if ($ship->getOrientation() === "0deg")
			$ship->setOrientation("90deg");
		else if ($ship->getOrientation() === "-90deg")
			$ship->setOrientation("0deg");
		else if ($ship->getOrientation() === "180deg")
			$ship->setOrientation("-90deg");
		else if ($ship->getOrientation() === "90deg")
			$ship->setOrientation("180deg");
	}
	if ($ship->getOrientation() === "90deg")
	{
		$y = $pos[1] + intval($array['deplacement']);
		$dim = array_reverse($dim);
		$ship->setDim($dim);
		if ($y < 100 && check_collision($grid, $pos[0], $y, $dim, $ship->getId()) === -1)
			$ship->setPos(array($pos[0], $y));
		else
			$ship->setHealth(-1000);
	}
	else if ($ship->getOrientation() === "-90deg")
	{
		$y = $pos[1] - intval($array['deplacement']);
		$dim = array_reverse($dim);
		$ship->setDim($dim);
		if ($y >= 0 && check_collision($grid, $pos[0], $y, $dim, $ship->getId()) === -1)
			$ship->setPos(array($pos[0], $y));
		else
			$ship->setHealth(-1000);
	}
	else if ($ship->getOrientation() === "0deg")
	{
		$y = $pos[0] + intval($array['deplacement']);
		if ($y < 150 && check_collision($grid, $y, $pos[1], $dim, $ship->getId()) === -1)
			$ship->setPos(array($y, $pos[1]));
		else
			$ship->setHealth(-1000);
	}
	else if ($ship->getOrientation() === "180deg")
	{
		$y = $pos[0] - intval($array['deplacement']);
		if ($y >=0 && check_collision($grid, $y, $pos[1], $dim, $ship->getId()) === -1)
			$ship->setPos(array($y, $pos[1]));
		else
			$ship->setHealth(-1000);
	}
	$_SESSION['player_obj'] = $player->getSerial();
	include('connection.php');
	$pl_serial = "player_".$_SESSION['player_id']."_obj='".$_SESSION['player_obj']."'";
	$req = "UPDATE `party` SET $pl_serial WHERE `id`=".$_SESSION['id_party']."";
	$bdd->exec($req);
}

?>
