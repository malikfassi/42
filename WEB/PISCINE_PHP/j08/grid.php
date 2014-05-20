<?php

// Configuration de la grille

$grid_width  = 150; // largeur de la grille
$grid_height = 100; // hauteur de la grille
$cell_width  = 10; // largeur d'une cellule
$cell_height = 10; // hauteur d'une cellule
$gutter      = 1;  // espacement des cellules


class Cell
{

}

class Ship
{
	public $height;
	public $width;
	public $x;
	public $y;
	public $player;
	public $direction;

	public function __construct($kwargs)
	{
		if (array_key_exists('height', $kwargs) && array_key_exists('width', $kwargs) && array_key_exists('x', $kwargs)
			&& array_key_exists('y', $kwargs) && array_key_exists('player', $kwargs) && array_key_exists('direction', $kwargs))
		{
			$this->height = $kwargs["height"];
			$this->width = $kwargs["width"];
			$this->x = $kwargs["x"];
			$this->y = $kwargs["y"];
			$this->player = $kwargs["player"];
			$this->direction = $kwargs["direction"];
		}
	}
}

class	Board
{
	public $board;
	public $grid_height;
	public $grid_width;

	public function __construct($kwargs)
	{
		if (array_key_exists('height', $kwargs) && array_key_exists('width', $kwargs))
		{
			$this->grid_height = $kwargs['height'];
			$this->grid_width = $kwargs['width'];
			$this->board = array();
			$row = $this->grid_height;
			while ($row != 0)
			{
				$this->board[] = array();
				$col = $this->grid_width;
				while ($col != 0)
				{
					$this->board[$row][$col] = array(0, 0, 0);
					$col--;
				}
				$row--;
			}
		}
	}

	public function display()
	{
		$row = 0;
		while ($row != $this->grid_height)
		{
			$col = 0;
			print ('<div class="row">');
			while ($col != $this->grid_width)
			{
				$content = "white";
				if ($this->board[$row][$col] == 1)
					$content = "black";
				else if ($this->board[$row][$col] == 2)
					$content = "red";
				print ('<span class="cell" style="background-color:'.$content.'"></span>');
				$col++;
			}
			print('</div>');
			$row++;
		}
	}

	public function add_ship(Ship $ship)
	{
		$row = $ship->y;
		$end_r = $ship->y + $ship->height;
		if ($ship->direction == "up" || $ship->direction == "down")
			$end_r = $ship->y + $ship->width;
		$end_c = $ship->x + $ship->width;
		if ($ship->direction == "up" || $ship->direction == "down")
				$end_c = $ship->x + $ship->height;
		if ($ship->direction == "down")
		{
			$target_row = $end_r - 1;
			$target_col = $ship->x + $ship->width / 2;
		}
		else if ($ship->direction == "up")
		{
			$target_row = $ship->y;
			$target_col = $ship->x + $ship->width / 2;
		}
		else if ($ship->direction == "left")
		{
			$target_col = $ship->x;
			$target_row = $ship->y + $ship->height / 2;
		}
		else if ($ship->direction  == "right")
		{
			$target_col = $end_c - 1;
			$target_row = $ship->y + $ship->height / 2;
		}
		while ($row != $end_r)
		{
			$col = $ship->x;
			while ($col != $end_c)
			{
				$this->board[$row][$col] = $ship->player;
				if (($ship->direction == "down" && $row == $end_r - 1) || ($ship->direction == "up" && $row == $ship->y)
					|| ($ship->direction == "left" && $col == $ship->x) || ($ship->direction  == "right" && $col == $end_c - 1))
					$this->board[$row][$col] = $ship->player == 1 ? 2 : 1;
				if ($ship->direction == "down" && $col == $target_col && $row > $target_row)
				{
					if ($row <= $target_row + 30)
						$this->board[$row][$col] = -1;
					else if ($row <= $target_row + 60)
						$this->board[$row][$col] = -2;
					else if ($row <= $target_row + 90)
						$this->board[$row][$col] = -3;
				}
				if ($ship->direction == "down" && $col == $target_col && $row > $target_row)
				{
					if ($row <= $target_row + 30)
						$this->board[$row][$col] = -1;
					else if ($row <= $target_row + 60)
						$this->board[$row][$col] = -2;
					else if ($row <= $target_row + 90)
						$this->board[$row][$col] = -3;
				}
				$col++;
			}
			$row++;
		}
	}

	public function is_ok(Ship $ship, $length)
	{
		$new_x_top = $ship->x;
		if ($ship->direction == "right")
			$new_x_top += $length;
		else if ($ship->direction == "left")
			$new_x_top -= $length;
		$new_y_top = $ship->y;
		if ($ship->direction == "up")
			$new_y_top -= $length;
		else if ($ship->direction == "down")
			$new_y_top += $length;
		$new_x_bottom = $new_x_top + $ship->width - 1;
		if ($ship->direction == "up" || $ship->direction == "down")
			$new_x_bottom = $new_x_top + $ship->height - 1;
		$new_y_bottom = $new_y_top + $ship->height - 1;
		if ($ship->direction == "up" || $ship->direction == "down")
			$new_y_bottom = $new_y_top + $ship->width - 1;
		echo "new_x_bottom : ".$new_x_bottom."  new_y_bottom ".$new_y_bottom."</br>";
		echo "new_x_top : ".$new_x_top."  new_y_top ".$new_y_top."</br>";
		echo "x : ".$ship->x."  y ".$ship->y."</br>";
		echo "grid_width : ".$this->grid_width."  grid_height ".$this->grid_height."</br>";
		return (($new_x_top < $this->grid_width && $new_x_top >= 0 && $new_y_top < $this->grid_height
			&& $new_y_top >= 0 && $new_x_bottom < $this->grid_width && $new_x_bottom >= 0
			&& $new_y_bottom < $this->grid_height && $new_y_bottom >= 0)
			&& $this->is_empty($new_x_top, $new_y_top, $ship->height, $ship->width, $ship->x, $ship->y));
	}

	public function is_empty($new_x, $new_y, $height, $width, $x, $y)
	{
		$row = $new_y;
		$end_r = $new_y + $ship->height;
		if ($ship->direction == "up" || $ship->direction == "down")
			$end_r = $new_y + $ship->width;
		while ($row != $end_r)
		{
			$col = $new_x;
			$end_c = $new_x + $ship->width;
			if ($ship->direction == "up" || $ship->direction == "down")
				$end_c = $new_x + $ship->height;
			while ($col != $end_c)
			{
				if ($this->board[$row][$col] && !($row >= $y && $row < $end_r  && $col >= $x && $col < $end_c))
					return (0);
				$col++;
			}
			$row++;
		}
		return (1);
	}
	public function remove_ship(Ship $ship)
	{
		$row = $ship->y;
		$end_r = $ship->y + $ship->height;
		if ($ship->direction == "up" || $ship->direction == "down")
			$end_r = $ship->y + $ship->width;
		while ($row != $end_r)
		{
			$col = $ship->x;
			$end_c = $ship->x + $ship->width;
			if ($ship->direction == "up" || $ship->direction == "down")
				$end_c = $ship->x + $ship->height;
			while ($col != $end_c)
			{
				$this->board[$row][$col] = 0;
				$col++;
			}
			$row++;
		}
	}
	public function move(Ship $ship, $length)
	{
		if ($this->is_ok($ship, $length))
		{
			$new_x = $ship->x;
			$new_y = $ship->y;
			if ($ship->direction == "right")
				$new_x += $length;
			else if ($ship->direction == "left")
				$new_x -= $length;
			else if ($ship->direction == "up")
				$new_y -= $length;
			else if ($ship->direction == "down")
				$new_y += $length;
		}
		else
			return (0);
		$this->remove_ship($ship);
		$ship->x = $new_x;
		$ship->y = $new_y;
		$this->add_ship($ship);
	}
}

class Player {
	public $pp = 15;
	public $shipleft = 1;
	public $iswinner = False;
	public $ishisturn = False;
	public $playerid = 0;

	public function __construct($kwargs)
	{
		if (array_key_exists('playerid', $kwargs))
		{
			$this->playerid = $kwargs["playerid"];
			if (array_key_exists('ishisturn', $kwargs) && $kwargs['ishisturn'] == True){
				echo "C'est votre tour joueur" .  $this->playerid;
			}
			print(" hello player ". $this->playerid);
		}
	}


	public function getPP($playerid){
		$pp = 15;
	}
}

$board = new Board(array( 'height' => 100, 'width' => 150));
$ship = new Ship(array('height' => 4, 'width' =>4, 'x' => 1, 'y' => 2, 'player' => 1, "direction" => "right"));
$ship1 = new Ship(array('height' => 5, 'width' =>10, 'x' => 20, 'y' => 15, 'player' => 2, "direction" => "down"));

$board->add_ship($ship);
$board->add_ship($ship1);
//$board->remove_ship($ship1);

$playerone = new Player(array('playerid' => 1, 'ishisturn' => True));
$playertwo = new Player(array('playerid' => 2, 'ishisturn' => False));

?>

<!doctype html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Grid</title>
	<style type="text/css">
	body {
		background-color: #efefef;
	}

	.grid .row {
		margin-left: 1px;
	}

	.grid .row:after {
		content: " ";
		visibility: hidden;
		display: block;
		height: 0;
		clear: both;
	}

	.grid .cell {
		display: block;
		float: left;
		margin-left: <?php echo $gutter?>px;
		margin-bottom: <?php echo $gutter?>px;
		width: <?php echo $cell_width?>px;
		height: <?php echo $cell_height?>px;
		border: 1px solid #ccc;
		border-top: none;
		border-left: none;
		cursor: pointer;
		background: white;
	}
	 </style>
	</head>
<body>
<?php

$weapon_name = "default_weapon";
$dice_result = 0;
$player = 1;


if (isset($_POST["endturn"])) {
	$player = ($_POST["player"] == 1 ? 2 : 1);
}

if (isset($_POST["dice_submit"])) {
	$dice_result = rand(1, 6);
	$player = $_POST["player"];
}
if (isset($_POST["move"])) {
	$board->move($ship, $_POST["move"]);
}


?>


Tour de Joueur <?php echo $player; ?> <br />

		<form method="post" action="grid.php">
				Se deplacer de : <input type="text" size="2" name="move" />
				<input type="submit" name="submit" value="OK"/>
				<br/>
		</form>
		<form method="post" action="grid.php">
				Tirer avec <?php echo $weapon_name; ?> : <input type="submit" name="dice_submit" value="Lancer D6"/>
				<input type="text" size="1" value="<?php echo $dice_result; ?>" />
				<br/>
				<input type="submit" name="endturn" value="Fin du tour"/>
				<input type="hidden" name="player" value=" <?php echo $player; ?>" />
		</form>


	<div class="grid">
		<?php $board->display()?>
	</div>


</body>
</html>
<?php
/*
 *
$end_r = $ship->y + $ship->height;
if ($ship->direction == "up" || $ship->direction == "down")
	$end_r = $ship->y + $ship->width;
$end_c = $ship->x + $ship->width;
if ($ship->direction == "up" || $ship->direction == "down")
	$end_c = $ship->x + $ship->height;
$ship = $player1->get_ship();

if ($ship->direction == "down")
{
	$row = $end_r - 1;
	$col = $ship->x + $ship->width / 2;

}
else if ($ship->direction == "up")
{
	$row = $ship->y;
	$col = $ship->x + $ship->width / 2;
}
else if ($ship->direction == "left")
{
	$col = $ship->x;
	$row = $ship->y + $ship->height / 2;
}
else if ($ship->direction  == "right")
{
	$col = $end_c - 1;
	$row = $ship->y + $ship->height / 2;
}




 *
 */

?>
