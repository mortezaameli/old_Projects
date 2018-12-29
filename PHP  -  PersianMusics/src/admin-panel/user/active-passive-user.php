<?php
ob_start();
include ("../conncet-db.php");

$sql = sprintf("UPDATE `usertbl` SET `flag` = '%s' WHERE `usertbl`.`id` = %s", $_GET['flag'], $_GET['id']);

mysqli_query($conn, $sql);

mysqli_close($conn);
header("location:../manage-user.php");
?>