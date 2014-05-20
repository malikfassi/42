<?php

class Ship extends Pawn
{
	private $_shield = 0;
	private $_max_shield = 30;
	private $_speed = 0;
	private $_retspeed;
	private $_bonus_speed = 0;
	private $_power = 0;
	private $_bonus_weapon = 0;
	private $_orientation;
	private $_weapons;

	public function __construct(array $kwargs)
	{
		parent::__construct($kwargs);

		if (array_key_exists('speed', $kwargs))
			$this->setSpeed($kwargs['speed']);

		if (array_key_exists('max_shield', $kwargs))
			$this->_max_shield = intval($kwargs['max_shield']);

		if (array_key_exists('power', $kwargs))
			$this->setPower($kwargs['power']);

		if (array_key_exists('orientation', $kwargs))
			$this->setOrientation($kwargs['orientation']);

		$this->_weapons = array();

		if (array_key_exists('weapons', $kwargs))
			$this->setWeapons($kwargs['weapons']);
	}

	public static function doc()
	{
		return file_get_contents("./Ship.doc.txt");
	}

	public function setShield($shield)
	{
		$this->_shield += min($this->_max_shield, intval($shield));
	}
	public function getShield()
	{
		return $this->_shield;
	}
	public function setMax_shield( $max_shield )
	{
		$this->_max_shield = intval($max_shield);
	}

	public function setSpeed($speed)
	{
		$this->_speed = intval($speed);
	}
	public function getSpeed()
	{
		$this->_retspeed = $this->_speed + $this->_bonus_speed;
		$this->_bonus_speed = 0;
		return $this->_retspeed;
	}
	public function setBonus_speed( $bonus_speed )
	{
		$this->_bonus_speed = intval($bonus_speed);
	}

	public function setPower($pow)
	{
		$this->_power = intval($pow);
	}
	public function getPower()
	{
		return $this->_power;
	}

	public function setOrientation($direct)
	{
		$this->_orientation = $direct;
	}
	public function getOrientation()
	{
		return $this->_orientation;
	}

	public function setWeapons ( $new_weapon )
	{
		$this->_weapons[] = $new_weapon;
	}
	public function getWeapons ()
	{
		return $this->weapons;
	}
	public function setBonus_weapon ( $bonus_weapon)
	{
		$this->_bonus_weapon = intval($bonus_weapon);
	}
	public function getBonus_weapon ()
	{
		$ret = $this->_bonus_weapon;
		$this->_bonus_weapon = 0;
		return $ret;
	}
	public function	__destruct() {return;}

}

?>
