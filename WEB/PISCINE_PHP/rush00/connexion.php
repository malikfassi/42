<?PHP
require 'verif.php';
?>
<html>
	<body>
		<center><strong>Connexion :</strong></center>
		<br/>
		<br/>
		<center><form action="verif.php" method="post">
			Identifiant : <input type="text" name="login" value=""/><br />
			Mot de passe: <input type="password" name="passwd" value=""/><br />
			<input type="submit" name="submit" value="OK" />
		</form></center>
	</body>
</html>
