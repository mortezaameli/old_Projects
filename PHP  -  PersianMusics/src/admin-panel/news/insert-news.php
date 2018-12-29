<?php
ob_start();
include ("../jdf.php");
include ("../conncet-db.php");

if( isset($_POST['submit']) )
{
	$sql = sprintf("INSERT INTO `newstbl` (`id`, `title`, `text`, `group`, `date`, `flag`) VALUES (NULL, '%s', '%s', '%s', '%s', '0');", $_POST['news-title'], $_POST['news-text'], $_POST['news-group'], jdate('H:i:s ,Y/n/j'));
	mysqli_query($conn, $sql);	
}

mysqli_close($conn);

header("location:../manage-add-news.php");
?> 
