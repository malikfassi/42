<?PHP
require('includes/header.php');
require('includes/sidebar.php');
session_start();

?>
<h1>Bienvenue  <?php echo $_SESSION["username"]; ?></h1>
<?PHP
echo'<br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>';
require('includes/footer.php');
?>
