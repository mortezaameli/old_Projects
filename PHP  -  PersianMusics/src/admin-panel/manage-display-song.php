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
<title>نمایش موزیک ها</title>
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

<div id="musics-content">
	<div id="musics-triangle"></div>
    <img class="exit-content-pic" src="icon/cross108.png" width="20" height="20" alt=""/>
    <div id="add-musics-btn">
    	<a href="manage-add-song.php">آهنگ جدید</a>
    </div>
    <div id="display-musics-btn">
    	<a href="manage-display-song.php">مشاهده آهنگ ها</a>
    </div>
    <div class="clr" style="border:1px solid transparent;">
    	<div id="display-musics-box">
        	<div id="display-musics-box-triangle"></div>
            <img class="exit-box-pic" src="icon/cross108.png" width="20" height="20" alt=""/>
            <table class="display-table" cellspacing="0">
                <tr>
                  <td>شناسه</td>
                  <td>نام آهنگ</td>
                  <td>خواننده</td>
                  <td>وضعیت تایید</td>
                  <td>حذف</td>
                </tr>
<?php
include ("jdf.php");
include ("conncet-db.php");

$sql = sprintf("select * from songtbl");
$result = mysqli_query($conn, $sql);

if( mysqli_num_rows($result) > 0 )
{
	while( $row = mysqli_fetch_assoc($result) )
	{
		if( $row['flag'] == 1 )
		{
			$x = "<a id=\"is-active-song\" href = musics/active-passive-song.php?id=".$row['id']."&flag=0>تایید شده</a>";
		}
		elseif( $row['flag'] == 0)
		{
			$x = "<a id=\"is-passive-song\" href = musics/active-passive-song.php?id=".$row['id']."&flag=1>تایید نشده</a>";
		}
		$d = "<a id=\"delete-song-label\" href = musics/delete-song.php?id=".$row['id'].">حذف</a>";
		
		echo '
		 <tr>
		  <td>'.$row['id'].'</td>
		  <td>'.$row['name'].'</td>
		  <td>'.$row['songer'].'</td>
		  <td>'.$x.'</td>
		  <td>'.$d.'</td>
		</tr>';
	}
}

mysqli_close($conn);
?>
			</table>
        </div>
    </div>
</div>

</body>
</html>