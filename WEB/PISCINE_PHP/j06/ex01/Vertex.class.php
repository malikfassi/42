<?PHP
require_once("Color.class.php");
class Vertex {
	private $_x;
	private $_y;
	private $_z;
	private $_w = 1.0;
	private $_color;
	public static $verbose = False;

	public static function doc()
	{
		echo file_get_contents("Vertex.doc.txt");
	}

	public function __construct(array $kwargs)
	{
		if (array_key_exists('x', $kwargs) && array_key_exists('y', $kwargs) && array_key_exists('z', $kwargs))
		{
			$this->_x = $kwargs['x'];
			$this->_y = $kwargs['y'];
			$this->_z = $kwargs['z'];
		}
		if (array_key_exists('color', $kwargs))
			$this->_color = $kwargs['color'];
		else
			$this->_color = new Color(array ('red' => 255, 'green' => 255, 'blue' => 255));
		if (array_key_exists('w', $kwargs))
			$this->_w = $kwargs['w'];
		if (self::$verbose)
			print ($this." constructed\n");
		return ;
	}

	public function __destruct()
	{
		if (self::$verbose)
			print ($this." destructed\n");
		return ;
	}

	public function __ToString()
	{
		$res = sprintf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f", $this->_x, $this->_y, $this->_z, $this->_w);
		if (self::$verbose)
		$res = $res.", ".$this->_color;
		$res = $res." )";
		return ($res);
	}

	public function getX()
	{
		return ($this->_x);
	}

	public function getY()
	{
		return ($this->_y);
	}

	public function getZ()
	{
		return ($this->_z);
	}

	public function getW()
	{
		return ($this->_w);
	}

	public function getColor()
	{
		return ($this->_color);
	}

	public function setX($x)
	{
		$this->_x = $x;
	}

	public function setY($y)
	{
		$this->_y = $y;
	}
	public function setZ($z)
	{
		$this->_z = $z;
	}
	public function setW($w)
	{
		$this->_w = $w;
	}
	public function setColor($color)
	{
		$this->_color = $color;
	}
}
?>
