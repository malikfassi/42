#!/user/bin/php
<?PHP
echo "Entrez un nombre: ";
$handle = fopen("php://stdin", 'r');
$line = fgets($handle);
while ($line)
{
	$text = substr($line, 0, -1);
	if (is_numeric($text))
	{
		if ($text % 2 == 0)
			echo "Le chiffre ".$text." est Pair\n";
		else
			echo "Le chiffre ".$text." est Impair\n";
	}
	else
		echo "'".$text."' n'est pas un chiffre\n";
	echo "Entrez un nombre: ";
	$handle = fopen("php://stdin", 'r');
	$line = fgets($handle);
}
echo "^D\n";
?>
