<?PHP
class Jaime
{
	public function sleepWith($arg)
	{
		if (get_class($arg) == "Tyrion")
			print ("Not even if I'm drunk !\n");
		else if (get_class($arg) == "Sansa")
			print ("Let's do this.\n");
		else
			print ("With pleasure, but only in a tower in Winterfell, then.\n");
	}
}
?>
