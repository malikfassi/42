<?php

final class Weapons
{
	private $_charges;
	private $_range;
	private $_area;

	public function __construct(array $kwargs)
	{
		if (array_key_exists('charges', $kwargs))
			$this->setCharges($kwargs['charges']);
		else
			$this->setCharges(0);

		if (array_key_exists('range', $kwargs))
			$this->_range = $kwargs['range'];
		else
			$this->_range = 0;

		if (array_key_exists('area', $kwargs))
			$this->_range = $kwargs['area'];
		else
			$this->_range = 0;
	}

	public static function doc()
	{
		return file_get_contents("./Weapon.doc.txt");
	}

	public function setCharges($charge)
	{
		$this->_charges = intval($charge);
	}
	public function getCharges()
	{
		return $this->_charges;
	}
}

?>
