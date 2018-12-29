<?php
session_start();
ob_start();
include ("../conncet-db.php");
if(isset($_POST['register-submit']))
{
	$un = $_POST['username'];
	$pw = $_POST['password'];
	$cpw= $_POST['confirm-password'];
	if($pw == $cpw)
	{
		$sql = sprintf("INSERT INTO `usertbl` (`id`, `username`, `password`, `flag`) VALUES (NULL, '%s', '%s', '0');", $un, $pw);
		mysqli_query($conn, $sql);
		mysqli_close($conn);
		$_SESSION['is-registered'] = 1;
		$_SESSION['not-confirm-pass'] = NULL;	
	}
	else
	{
		$_SESSION['not-confirm-pass'] = 1;
	}
}

header("location:../../index.php");

?> 
