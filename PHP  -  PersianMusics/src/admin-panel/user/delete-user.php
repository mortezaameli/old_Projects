<?php
ob_start();
include ("../conncet-db.php");

$sql = sprintf("DELETE FROM usertbl WHERE id='%s'", $_GET['id']);
mysqli_query($conn, $sql);

mysqli_close($conn);
header("location:../manage-user.php");
?>