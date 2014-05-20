<?php

include('db_config.php');

try
    {
        $bdd = new PDO('mysql:host=localhost;port=8080;dbname=game', $_usr, $_pass);
    }
    catch(Exception $e)
    {
        die('Erreur : '.$e->getMessage());
    }

?>