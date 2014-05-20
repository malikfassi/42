<?PHP

class Tyrion
{
	public function sleepWith($arg)
	{
		if (get_class($arg) == "Jaime")
			print ("Not even if I'm drunk !\n");
		else if (get_class($arg) == "Sansa")
			print ("Let's do this.\n");
		else
			print ("Not even if I'm drunk !\n");
	}
}
?>
