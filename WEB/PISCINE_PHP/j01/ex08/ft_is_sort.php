#!/usr/bin/php
<?PHP
function ft_is_sort($arr)
{
	$default = $arr;
	sort($arr);
	$flag = 1;
	foreach($arr as $key=>$value)
	{
		if ($value != $default[$key])
			$flag = 0;
	}
	return ($flag);
}
?>
