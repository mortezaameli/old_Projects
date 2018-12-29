<?php
ob_start();
include ("../conncet-db.php");

$sql = sprintf("DELETE FROM newstbl WHERE id='%s'", $_GET['id']);
mysqli_query($conn, $sql);

mysqli_close($conn);
header("location:../manage-display-news.php");
?>