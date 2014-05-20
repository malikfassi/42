<?PHP
class Color {
	public $red = 0;
	public $green = 0;
	public $blue = 0;
	public static $verbose = False;

	public static function doc()
	{
		echo file_get_contents("Color.doc.txt");
	}

	public function __construct(array $kwargs)
	{
		if (array_key_exists('rgb', $kwargs))
		{
			$this->red = $kwargs['rgb'] >> 16 & 0xFF;
			$this->green = $kwargs['rgb'] >> 8 & 0xFF;
			$this->blue = $kwargs['rgb'] & 0xFF;
		}
		else if (array_key_exists('red', $kwargs) && array_key_exists('green', $kwargs) && array_key_exists('blue', $kwargs))
		{
			$this->red = $kwargs['red'];
			$this->green = $kwargs['green'];
			$this->blue = $kwargs['blue'];
		}
		if (self::$verbose)
			print ($this." constructed.\n");
		return ;
	}

	public function __destruct()
	{
		if (self::$verbose)
			print ($this." destructed.\n");
		return ;
	}

	public function __ToString()
	{
		return (sprintf("Color( red: %3d, green: %3d, blue: %3d )", $this->red, $this->green, $this->blue));
	}
	
	public function add(Color $rhs)
	{
		return ( new Color(array( 'red' => $this->red + $rhs->red, 'green' => $this->green + $rhs->green, 'blue' => $this->blue + $rhs->blue)));
	}

	public function sub(Color $rhs)
	{
		return ( new Color(array( 'red' => $this->red - $rhs->red, 'green' => $this->green - $rhs->green, 'blue' => $this->blue - $rhs->blue)));
	}

	public function mult($f)
	{
		return ( new Color(array( 'red' => $this->red * $f, 'green' => $this->green * $f, 'blue' => $this->blue * $f)));
	}
}
?>
