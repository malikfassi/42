 #!/usr/bin/php
<?PHP
function ft_split($arg1)
{
	$arg1 = preg_replace( '/\s+/', ' ', $arg1);
	$arg1 = trim($arg1);
	$arr = explode(' ', $arg1);
	sort($arr, SORT_STRING);
	return ($arr);
}
?>
