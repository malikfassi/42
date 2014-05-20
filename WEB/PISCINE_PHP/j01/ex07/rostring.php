#!/usr/bin/php
<?PHP
function ft_split($arg1)
{
	$arg1 = preg_replace('/\s+/', ' ', $arg1);
	$arg1 = trim($arg1);
	$arr1 = explode(' ', $arg1);
	return ($arr1);
}

$arr = ft_split($argv[1]);
if ($arr)
{
	foreach(array_slice($arr, 1) as $elem)
	{
		echo $elem." ";
	}
	if ($arr[0])
	echo $arr[0]."\n";
}
?>
