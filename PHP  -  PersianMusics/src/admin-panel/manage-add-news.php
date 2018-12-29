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
<title>افزودن خبر</title>

<?php
include ("jdf.php");
include ("conncet-db.php");

if( isset($_POST['news-submit']) )
{
	$sql = sprintf("INSERT INTO `newstbl` (`id`, `title`, `text`, `group`, `date`, `flag`) VALUES (NULL, '%s', '%s', '%s', '%s', '0');", $_POST['news-title'], $_POST['news-text'], $_POST['news-group'], jdate('H:i:s ,Y/n/j'));
	mysqli_query($conn, $sql);
}

mysqli_close($conn);
?>

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

<div id="news-content">
	<div id="news-triangle"></div>
    <img class="exit-content-pic" src="icon/cross108.png" width="20" height="20" alt=""/>
    <div id="add-news-btn">
    	<a href="manage-add-news.php">خبر جدید</a>
    </div>
    <div id="display-news-btn">
    	<a href="manage-display-news.php">مشاهده اخبار</a>
    </div>
    <div class="clr" style="border:1px solid transparent;">
    	<div id="add-news-box">
        	<div id="add-news-box-triangle"></div>
            <img class="exit-box-pic" src="icon/cross108.png" width="20" height="20" alt=""/>
            <form method="post">
            	<textarea id="news-title-area" name="news-title" placeholder="تیتر خبر..." autofocus></textarea>
                <textarea id="news-text-area" name="news-text" placeholder="متن خبر..."></textarea>
                <textarea id="news-group-area" name="news-group" placeholder="دسته بندی خبر..."></textarea>
                <input type="submit" name="news-submit" id="news-submit-btn" value="ارسال خبر">
            </form>
        </div>
    </div>
</div>

</body>
</html>