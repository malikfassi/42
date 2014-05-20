<?php
session_start();
global $show_form;
global $content;
global $submit;
global $error;
$error = "";
$file = 'db_config.php';
$show_form = TRUE;
$pass = (isset($_SESSION['pass'])) ? $_SESSION['pass'] : "";

if (isset($_POST['submit']))
{
    if ($_POST['submit'] == "configure" || ($_POST['submit'] == "recreate"))
    {
        if (isset($_POST['pass']))
        {
            $pass = $_POST['pass'];
            $_SESSION['pass'] = $pass;
        }
        else if (isset($_SESSION['pass']))
            $pass = $_SESSION['pass'];
        else
            $error = $error.'Please specify a valid password.<br>';
        if ($_POST['submit'] == "recreate")
            unlink($file);
        else if (file_exists($file))
        {
            $error = $error.'The file '.$file.' already exists.<br>-> Recreate will override your previous settings.<br>';
            $error = $error.'<input class="button" type="submit" name="submit" value="retry"><br><br>';
            $submit = "recreate";
            $show_form = FALSE;
        }
        if (isset($_POST['host']))
            $_SESSION['host'] = $_POST['host'];
        if (isset($_POST['user']))
            $_SESSION['user'] = $_POST['user'];
        if ($error == "")
        {
            $host = ( isset($_POST['host']) ) ? $_POST['host'] : "127.0.0.1";
            $user = ( isset($_POST['user']) ) ? $_POST['user'] : "root";
            $content = $content."<?php \n\$_host = '".$host."';\n\$_usr  = '".$user."';\n\$_pass = '".$pass."';\n?>";
            if (file_put_contents($file, $content) === FALSE)
            {
                $error = $error."Not able to create the ".$file." file.<br>";
                $submit = "retry";
            }
            else
            {
                $content = $file." successfully created.<br>-> click next to install the databases.<br>";
                $submit = "next";
                $show_form = FALSE;
            }
        }
    }
    else if (($_POST['submit'] == "next") || ($_POST['submit'] == "retry"))
    {
        if (!file_exists($file))
            $error = $error."The file ".$file." doesn't exists. Please restart the install from the begining.<br>";
        else
        {
            require_once $file;
            $link = mysqli_connect($_host, $_usr, $_pass);
            if (mysqli_connect_errno())
                $error = $error."Connection error : ".mysqli_connect_error()."<br>Verify the content of ".$file."<br>";
            else
            {
                $query_tab = file_get_contents('database/database.sql');
                $query_tab = explode(';', $query_tab);
                $query_tab = array_map('trim', $query_tab);
                $query_tab = array_filter($query_tab);
                $error = $error.'<div id="code"><a id="hide" href="#show" class="button">Hide SQL Query</a><a id="show" href="#code" class="button">Show SQL Query</a><pre id="code_content">';
                $no_error = TRUE;
                foreach ($query_tab as $query)
                {
                    $error = $error.$query.";";
                    if (mysqli_query($link, $query))
                        $error = $error."\n/* Query OK. */\n\n";
                    else
                    {
                        $error = $error."\n/* Error creating database:\n".mysqli_error($link)." \n*/\n\n";
                        $no_error = FALSE;
                    }
                }
                if ($no_error)
                {
                    $content = "Databases created successfully<br>";
                    $submit = "finish";
                }
                else
                {
                    $content = "Error during the installation.<br> -> Check the SQL Query log.<br>";
                    $submit = "retry";
                }
                $error = $error.'</pre></div>';
                $show_form = FALSE;
            }
        }
    }
    else if ($_POST['submit'] == 'finish')
    {
        session_destroy();
        header('Location: index.php');
        exit;
    }
}
if ($show_form)
{
    $content = "<label>Host<span class=\"small\">Usualy localhost</span></label>\n";
    $content = $content."<input type=\"text\" name=\"host\" value=\"127.0.0.1\" id=\"name\" onclick=\"select()\">\n";
    $content = $content."<label>Username<span class=\"small\">MySQL username</span></label>\n<";
    $content = $content."input type=\"text\" name=\"user\" value=\"root\" id=\"name\" onclick=\"select()\">\n";
    $content = $content."<label>Password<span class=\"small\">A super secure pass</span></label>\n";
    $content = $content."<input type=\"password\" name=\"pass\" required id=\"name\" value=\"".$pass."\" onclick=\"select()\">\n";
    $submit = "configure";
}
else if (isset($content))
    $content = '<div id="content">'.$content.'</div>';
$submit = '"'.$submit.'"';
?>
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
    <link rel="stylesheet" type="text/css" href="install_style.css">
    <title>Installation</title>
  </head>
  <body style="padding-top: 75px;">
  <div id="stylized" class="myform">
    <h1>Installation Script</h1>
  <div id="error" style="color:red;">
    <p id="lol">
    <?php echo $error; ?>
  </div>
    <form id="form" action="install.php" method="post">
      <?php echo $content; ?>
      <input class="button" type="submit" name="submit" value=<?php echo $submit; ?> >
      <div class="spacer"></div>
    </form>
  </div>
  </body>
</html>
