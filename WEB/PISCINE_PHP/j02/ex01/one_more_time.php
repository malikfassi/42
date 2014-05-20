#!/usr/bin/php
<?PHP
$arr = explode(' ', $argv[1]);
$days = array("lundi", "Lundi", "mardi", "Mardi", "mercredi", "Mercredi", 
	"jeudi", "Jeudi", "vendredi", "Vendredi", "samedi", "Samedi", "dimanche", 
	"Dimanche");
$months = array("janvier" => 1, "Janvier" => 1, "fevrier" => 2, "Fevrier" => 2,
   	"mars" => 3, "Mars" => 3, "avril" => 4, "Avril" => 4, "mai" => 5,"Mai" => 5,
	"juin" => 6, "Juin" => 6, "juillet" => 7, "Juillet" => 7, "aout" => 8,
	"Aout" => 8, "septembre" => 9, "Septembre" => 9, "octobre" => 10,
	"Octobre" => 10, "novembre" => 11, "Novembre" => 11, "decembre" => 12,
	"Decembre" => 12);
$time = explode(':', $arr[4]);
if (preg_match("/^(mardi|Mardi|Lundi|lundi|mercredi|Mercredi|Jeudi|jeudi|Vendredi|vendredi|Samedi|samedi|Dimanche|dimanche)\s(\d{1,2})\s(Novembre|novembre|janvier|Janvier|Fevrier|fevrier|mars|Mars|Avril|avril|mai|Mai|juin|Juin|Juillet|juillet|aout|Aout|Septembre|septembre|octobre|Octobre|decembre|Decembre)\s(\d{4})\s(\d{2}):(\d{2}):(\d{2})$/", $argv[1]) && checkdate($months[$arr[2]], $arr[1], $arr[3]) && $time[0] < 24 && $time[1] < 60 && $time[2] < 60)
{
	date_default_timezone_set("Europe/Paris");
	echo mktime($time[0], $time[1], $time[2], $months[$arr[2]], $arr[1], $arr[3])."\n";
}
else
{
	echo "Wrong Format\n";
}
?>
