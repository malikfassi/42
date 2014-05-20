<?PHP

class Targaryen
{
	public function resistsFire()
	{
		return False;
	}
	public function getBurned()
	{
		return (!$this->resistsFire()? "burns alive" : "emerges naked but unharmed");
	}
}

?>
