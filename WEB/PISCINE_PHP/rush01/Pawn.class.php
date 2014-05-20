<?php

require_once('Serial.trait.php');

class Pawn
{

	use Serial;

	protected $_id = 0;
	protected $_name;
	protected $_health = 0;
	protected $_dim;
	protected $_faction;
	protected $_pos;

	public function __construct(array $kwargs)
	{
		if (array_key_exists('id', $kwargs))
			$this->_id = intval($kwargs['id']);

		if (array_key_exists('name', $kwargs))
			$this->_name = $kwargs['name'];
		else
			$this->_name = "unknow";

		if (array_key_exists('health', $kwargs))
			$this->setHealth($kwargs['health']);
		else
			$this->setHealth(0);

		if (array_key_exists('dim', $kwargs))
			$this->_dim = $kwargs['dim'];
		else
			$this->_dim = array(0, 0);

		if (array_key_exists('faction', $kwargs))
			$this->_faction = $kwargs['faction'];
		else
			$this->_faction = "neutral";

		if (array_key_exists('pos', $kwargs))
			$this->setPos($kwargs['pos']);
		else
			$this->setPos(array(-1, -1));
	}

	public static function doc()
	{
		return file_get_contents("./Pawn.doc.txt");
	}

	public function is_take_damage($hit, $dmg)
	{
		if ($hit[0] >= $this->_pos[0] && $hit[0] <= $this->_pos[0] + $this->_dim[0] && $hit[1] >= $this->_pos[1] && $hit[1] <= $this->_pos[1] + $this->_dim[1])
		{
			$this->setHealth($dmg);
			return TRUE;
		}
		else
			return FALSE;
	}

	public function	getHealth() {return $this->_health;}
	public function	getPos() {return $this->_pos;}
	public function	getName() {return $this->_name;}
	public function	getId() {return $this->_id;}
	public function	getDim() {return $this->_dim;}

	public function	setHealth($heal) {$this->_health += intval($heal);}
	public function	setPos($pos) {$this->_pos = $pos;}
	public function	setDim($val) {$this->_dim = $val;}
	public function	setId($val) {$this->_id = intval($val);}

	public function	__destruct() {return;}
}

?>
