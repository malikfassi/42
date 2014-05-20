<?PHP
if (!session_start())
{
	echo "ERROR: couldn't start a session";
	exit(0);
}
if (!empty($_GET) && $_GET['submit'] == 'OK')
{
	$_SESSION['login'] = $_GET['login'];
	$_SESSION['passwd'] = $_GET['passwd'];
}
$user = '';
$pass = '';
if(isset($_SESSION['login']))
	$user = $_SESSION['login'];
if (isset($_SESSION['passwd']))
	$pass = $_SESSION['passwd'];
echo '<html>
<body>
<form action="index.php" method="get">
	Identifiant : <input type="text" name="login" value="'.$user.'"/>
	<br />
	Mot de passe: <input type="password" name="passwd" value="'.$pass.'"/>
	<input type="submit" name="submit" value="OK" />
</form>
</body></html>'."\n";
?>
