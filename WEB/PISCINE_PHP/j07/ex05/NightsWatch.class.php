<?PHP

class NightsWatch implements IFighter
{
	public function fight()
	{
	}

	public function recruit($arg)
	{
		if (get_class($arg) == "JonSnow")
			$arg->fight();
		else if (get_class($arg) == "SamwellTarly")
			$arg->fight();
	}
}

?>
