<script language="javascript">

var MAX_PP = <?php if ($_SESSION['order']) echo $_SESSION['ship_power']; else if ($_SESSION['mvt']) echo $_SESSION['ship_speed'];?>;

function incremente(val)
{
    if (val == 1)
        var iNumber = parseInt(document.getElementById("incrementation1" ).value);
    else if (val == 2)
        var iNumber = parseInt(document.getElementById("incrementation2" ).value);
    else if (val == 3)
        var iNumber = parseInt(document.getElementById("incrementation3" ).value);
    if (MAX_PP)
    {
        iNumber = iNumber+1;
        MAX_PP--;
    }
    if (val == 1)
        document.getElementById("incrementation1").value = iNumber;
    else if (val == 2)
        document.getElementById("incrementation2").value = iNumber;
    else if (val == 3)
        document.getElementById("incrementation3").value = iNumber;
    document.getElementById("PP").value = MAX_PP;
}

function desincremente(val)
{
    if (val == 1)
        var iNumber = parseInt(document.getElementById("incrementation1" ).value);
    else if (val == 2)
        var iNumber = parseInt(document.getElementById("incrementation2" ).value);
     else if (val == 3)
        var iNumber = parseInt(document.getElementById("incrementation3" ).value);
    if (iNumber != 0)
    {
        iNumber = iNumber-1;
        MAX_PP++;
    }
    if (val == 1)
      document.getElementById("incrementation1").value = iNumber;
    else if (val == 2)
      document.getElementById("incrementation2").value = iNumber;
    else if (val == 3)
      document.getElementById("incrementation3").value = iNumber;
    document.getElementById("PP").value = MAX_PP;
 }

function checkCheckBox()
{
    alert("sfgsdfghfhsjgfhfgsjfghsfghx");
    if (document.form.ship_to_play.checked == false)
    {
        alert('Vous devez cocher la case avant de continuer.');
        return false;
    }else{
        alert('Merci pour votre don');
    }
    return true;
}

</script>