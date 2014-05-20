<?PHP
error_reporting(E_ALL);
if (!empty($_POST) && $_POST['submit'] == 'OK')
{
	if (!$_POST['login'] || !$_POST['passwd'])
	{
		echo "ERROR\n";
		exit(0);
	}
	if (!file_exists("../private/"))
	{
		mkdir("../private");
	}
	if (file_exists("../private/passwd"))
		$arr = unserialize(file_get_contents("../private/passwd"));
	if (isset($arr[$_POST['login']]))
	{
		echo "ERROR\n";
		exit(0);
	}
	$arr[$_POST['login']] = hash('whirlpool', $_POST['passwd']);
	$string = serialize($arr);
	file_put_contents("../private/passwd", $string);
	echo "OK\n";
}
?>
