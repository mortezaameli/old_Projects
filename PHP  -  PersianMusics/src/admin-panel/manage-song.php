<?php
session_start();
ob_start();

if( !isset($_SESSION['admin']) )
{
	header("location:is-admin.php");
}
?>
<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>مدیرت موزیک ها</title>

<script src="js/jquery-2.1.4.min.js"></script>
<script src="js/script.js"></script>
<link rel="stylesheet" type="text/css" href="css/style.css">

</head>

<body>

<div id="header">
	<a id="link-site" href="../index.php" target="_blank">پرشین موزیک</a>
</div>

<div id="menu-bar">
	<ul>
    	<li id="news-btn">
        	<a href="manage-news.php">خبر</a>
        	<img src="icon/documents7 (2).png" width="20" height="20" alt=""/>
        </li>
        <li id="musics-btn">
        	<a href="manage-song.php">آهنگ</a>
            <img src="icon/quaver3(2).png" width="20" height="20" alt=""/>
        </li>
        <li id="user-btn">
        	<a href="manage-user.php">کاربران</a>
            <img src="icon/network60 (2).png" width="20" height="20" alt=""/>
        </li>
    </ul>
</div>

<div id="musics-content" style="height:500px;">
	<div id="musics-triangle"></div>
    <img class="exit-content-pic" src="icon/cross108.png" width="20" height="20" alt=""/>
    <div id="add-musics-btn">
    	<a href="manage-add-song.php">آهنگ جدید</a>
    </div>
    <div id="display-musics-btn">
    	<a href="manage-display-song.php">مشاهده آهنگ ها</a>
    </div>
</div>

</body>
</html>