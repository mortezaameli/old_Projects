<?php
session_start();
ob_start();
include ("conncet-db.php");

if(isset($_POST['admin-submit']))
{
	$sql = sprintf("SELECT * FROM admintbl WHERE username='%s' and password='%s'", $_POST['username'], $_POST['password']);
	$result = mysqli_query($conn, $sql);
	
	$count = mysqli_num_rows($result);
	if($count > 0 )
	{
		$_SESSION['admin'] = 1;
		header("location:manage.php");
	}
}
mysqli_close($conn);
?>
<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>فرم ورود مدیر</title>
<style type="text/css">
body
{
	background-color:#EEE;
	margin:0;
	padding:0;
}
#header
{
	width:100%;
	height:80px;
	text-align:center;
	font-family:'B koodak', tahoma;
	font-size:36px;
	color:#444;
	line-height:80px;
	background-color:#DDD;
	border-bottom:1px solid #CCC;
	box-shadow:0px 0px 5px #000;
	text-shadow:0px 0px 1px #000;
}
#admin-form
{
	width:350px;
	border:1px solid #CCC;
	box-shadow:0px 0px 5px #000;
	margin:auto;
	margin-top:200px;
	
}
table
{
	margin:auto;
	font-size:16px;
	color:#444;
	text-shadow:0px 0px 1px #000;
}
table td
{
	padding:10px;
}

table td input
{
	height:20px;
	font-size:16px;
	color:#222;
	box-shadow:0px 0px 5px #000;
}

table th
{
	padding-top:20px;
	padding-bottom:20px;
}

table th input
{
	width:60px;
	padding:3px;
	color:#111;
	font-family:'B koodak', tahoma;
	border:1px solid #CCC;
	box-shadow:0px 0px 5px #000;
}

</style>
</head>

<body>
<div id="header">برای مدیرت سایت وارد شوید</div>
<div id="admin-form">
    <form method="post">
    	<table border="0">
        	<tr>
            	<td>UserName :</td>
                <td><input type="text" name="username" placeholder="Username" autofocus /></td>
            </tr>
            <tr>
            	<td>Password &nbsp;&nbsp;:</td>
                <td><input type="password" name="password" placeholder="Password" /><br /></td>
            </tr> 
            <tr>
            	<th colspan="2"><input type="submit" name="admin-submit" value="ارسال" /></th>
            </tr>
        </table>
    </form>
</div>
</body>

</html>

