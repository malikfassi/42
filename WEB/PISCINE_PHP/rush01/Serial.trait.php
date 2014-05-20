<?php

trait Serial
{
	public function getSerial()
	{
		return serialize($this);
	}
}

?>
