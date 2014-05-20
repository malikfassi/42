<?php
session_start();

foreach ($_SESSION as $key => $value)
{
	if ($key !== "init_game")
		unset($_SESSION[$key]);
}
$_SESSION['init_game'] = 1;
?>

<html>
<head>
	<link href="style.css" rel="stylesheet">
	<STYLE type="text/css">
		body{
			background-image: url("http://www.letstalkabout.co.uk/wp-content/uploads/2013/11/warhammer-wallpaper-08.jpg");
		}
  	</STYLE>
</head>
<body>
	<div id="form_info">
	    <form method="post" action="lobby.php">
	    	<div id="player1">
		    	PLAYER :
				<input type="text" value="" name="player" required>
			</div>
	    	<input type="submit" name="submit" value="PLAY !" id="button">
	    </form>
    </div>
</body>
</html>
