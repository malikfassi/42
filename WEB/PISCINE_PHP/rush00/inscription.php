<?PHP
require 'create.php';
?>
<html>
	<body>
		<center><strong>Inscription :</strong></center>
		<br/>
		<br/>
		<center><form action="create.php" method="post">
			Identifiant : <input type="text" name="login" value=""/><br />
			Mot de passe: <input type="password" name="passwd" value=""/><br />
			Confirmez Mot de passe : <input type="password" name="passwd2" value=""/><br />
			<input type="submit" name="submit" value="OK" />
		</form></center>
	</body>
</html>
