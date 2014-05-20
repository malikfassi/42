<?

echo "Entrez l'url : (par exemple : j04.local.42.fr) : ";
$handle = fopen("php://stdin", "r");
$line  = fgets($handle);
$text = substr($line, 0, -1);
$url = $text;
echo "Entrez le nom d'utilisateur de la DB (default: root) :";
$handle = fopen("php://stdin", "r");
$line  = fgets($handle);
$text = substr($line, 0, -1);
$user = $text;
echo "Entrez votre mot de passe : ";
$handle = fopen("php://stdin", "r");
$line  = fgets($handle);
$text = substr($line, 0, -1);
$mdp = $text;
echo "Entrez le nom de la DB : ";
$handle = fopen("php://stdin", "r");
$line  = fgets($handle);
$text = substr($line, 0, -1);
$dbname = $text;
$con=mysqli_connect("$url","$user","$mdp");
//Check connection
if (mysqli_connect_errno())
{
	die ("Failed to connect to MySQL: " . mysqli_connect_error());
}
// Create database
$sql="CREATE DATABASE ".$dbname;
if (mysqli_query($con,$sql))
{
	echo "Database my_db created successfully\n";
}
else
{
	 die ("Error creating database: " . mysqli_error($con));
}

$sql="CREATE TABLE products(
	id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
	title VARCHAR(255) NOT NULL COLLATE utf8_unicode_ci,
	price INT NOT NULL,
	description TEXT NOT NULL COLLATE utf8_unicode_ci,
	category VARCHAR(255) NOT NULL COLLATE utf8_unicode_ci,
	img TEXT NOT NULL)
";


$con=mysqli_connect("$url","$user","$mdp", "$dbname");
//Check connection
if (mysqli_connect_errno())
{
	echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
if (mysqli_query($con,$sql))
{
	echo "table products created successfully\n";
}
else
{
	echo "Error creating database: " . mysqli_error($con);
}
$sql="CREATE TABLE category(
	id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
	name VARCHAR(255) NOT NULL COLLATE utf8_unicode_ci)";
$con=mysqli_connect("$url","$user","$mdp", "$dbname");
//Check connection
if (mysqli_connect_errno())
{
	echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
if (mysqli_query($con,$sql))
{
	echo "table category created successfully\n";
}
else
{
	echo "Error creating database: " . mysqli_error($con);
}

$sql="CREATE TABLE users(
	id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
	name VARCHAR(255) NOT NULL COLLATE utf8_unicode_ci,
	password VARCHAR(255) NOT NULL COLLATE utf8_unicode_ci)";
$con=mysqli_connect("$url","$user","$mdp", "$dbname");
//Check connection
if (mysqli_connect_errno())
{
	echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
if (mysqli_query($con,$sql))
{
	echo "table users created successfully\n";
}
else
{
	echo "Error creating database: " . mysqli_error($con);
}

$con=mysqli_connect("$url","$user","$mdp", "$dbname");
$category = "balls";
$result = mysqli_query($con, "INSERT INTO category (`id`, `name`) VALUES ('?', '$category')");
if ( false===$result ) {
	printf("error: %s\n", mysqli_error($con));
}

$con=mysqli_connect("$url","$user","$mdp", "$dbname");
//Check connection
if (mysqli_connect_errno())
{
	echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
$title = "pokeball";
$price = 10;
$description = "oh, This is a pokeball.";
$img = base64_encode(file_get_contents("admin/imgs/pokeball.jpg"));
$result = mysqli_query($con, "INSERT INTO products (`id`, `title`, `price`, `description`, `category`, `img`) VALUES ('?', '$title', $price, '$description', '$category', '$img')");

if ( false===$result ) {
	printf("error: %s\n", mysqli_error($con));
}
$con=mysqli_connect("$url","$user","$mdp", "$dbname");
$category = "pokemon";
$result = mysqli_query($con, "INSERT INTO category (`id`, `name`) VALUES ('?', '$category')");
if ( false===$result ) {
	printf("error: %s\n", mysqli_error($con));
}
$con=mysqli_connect("$url","$user","$mdp", "$dbname");
//Check connection
if (mysqli_connect_errno())
{
	echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
$title = "pikachu";
$price = 10000;
$description = "pika pika";
$img = base64_encode(file_get_contents("admin/imgs/pikachu.jpg"));
$result = mysqli_query($con, "INSERT INTO products (`id`, `title`, `price`, `description`, `category`, `img`) VALUES ('?', '$title', $price, '$description', '$category', '$img')");

if ( false===$result ) {
	printf("error: %s\n", mysqli_error($con));
}
mysqli_close($con);
file_put_contents("admin/user.conf", $url."\n".$user."\n".$mdp."\n".$dbname);

?>	
