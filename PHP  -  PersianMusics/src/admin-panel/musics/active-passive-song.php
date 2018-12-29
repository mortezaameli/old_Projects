<?php
ob_start();
include ("../conncet-db.php");
include ("../jdf.php");

$sql = sprintf("UPDATE `songtbl` SET `date` = '%s', `flag` = '%s' WHERE `songtbl`.`id` = %s", jdate('H:i:s ,Y/n/j'), $_GET['flag'], $_GET['id']);

mysqli_query($conn, $sql);

mysqli_close($conn);
header("location:../manage-display-song.php");
?>