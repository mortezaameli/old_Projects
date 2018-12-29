<?php
session_start();
ob_start();

include ("../conncet-db.php");

if(isset($_POST['login-submit']))
{
	$sql = sprintf("SELECT * FROM usertbl WHERE username='%s' and password='%s' and flag='1'", $_POST['username'], $_POST['password']);
	$result = mysqli_query($conn, $sql);
	
	$count = mysqli_num_rows($result);
	if($count > 0 )
	{
		$_SESSION['login'] = 1;
	}
}

mysqli_close($conn);
header("location:../../index.php");
?> 
