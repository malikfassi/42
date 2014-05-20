<?PHP
require_once("Vertex.class.php");
class Vertex {
	private $_x;
	private $_y;
	private $_z;
	private $_w = 0.0;
	private $_orig;
	private $_dest;
	public static $verbose = False;

	public static function doc()
	{
		echo file_get_contents("Vertex.doc.txt");
	}

	public function __construct(array $kwargs)
	{
		if (array_key_exists('dest', $kwargs))
		{
		}
		if (array_key_exists('orig', $kwargs))

		
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
	public function sub(Vector $rhs)
	{
		return ();
	}
	public function normalize()
	{
	}
	public function magnitude()
	{
	}
}
?>
~
~
~
~
~
~
~
