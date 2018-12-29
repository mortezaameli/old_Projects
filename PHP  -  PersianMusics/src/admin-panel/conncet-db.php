<?php

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "musicsDB";

// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);

//set utf8
$q = "SET character_set_results = 'utf8', character_set_client = 'utf8', character_set_connection = 'utf8', character_set_database = 'utf8', character_set_server = 'utf8'";
mysqli_query($conn, $q);

?>