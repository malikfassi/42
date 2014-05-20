#!/usr/bin/php
<?PHP
$arr = array();
function ft_split($arg1)
{
	$arg1 = preg_replace( '/\s+/', ' ', $arg1);
	$arg1 = trim($arg1);
	$arr1 = explode(' ', $arg1);
	return ($arr1);
}
foreach (array_slice($argv, 1) as $elem)
{
	$arr = array_merge($arr, ft_split($elem));
}
sort($arr, SORT_STRING);
foreach($arr as $elem)
	echo $elem."\n";
?>
