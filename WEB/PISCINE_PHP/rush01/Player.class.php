<?php
require_once('Serial.trait.php');

final class Player {

	use Serial;

	private static	$nb = 0;
	private			$_name;
	public			$ships = array();

	public function	getName() {return $this->_name;}
	public function	getShips() {return $this->ships;}

	function	__construct($name, $array)
	{
		if (isset($name))
			$this->_name = $name;
		else
			$this->_name = "player".(self::$nb + 1);
		self::$nb++;
		$this->ships = $array;
	}

	public static function doc()
	{
		return file_get_contents("./Player.doc.txt");
	}

	function	__destruct() {return ($this->_name." is DEAD.");}
}

?>
