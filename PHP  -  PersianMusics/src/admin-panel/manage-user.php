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
<title>مدیریت کاربران</title>
<?php
include ("conncet-db.php");
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

<div id="user-content" style="height:950px;">
	<div id="user-triangle"></div>
    <img class="exit-content-pic" src="icon/cross108.png" width="20" height="20" alt=""/>
    <div id="display-user-box">
    	<table class="display-table" cellspacing="0">
            <tr>
              <td>شناسه</td>
              <td>نام کاربری</td>
              <td>رمز عبور</td>
              <td>وضعیت کاربر</td>
              <td>حذف</td>
            </tr>
<?php
$sql = sprintf("select * from usertbl");
$result = mysqli_query($conn, $sql);

if( mysqli_num_rows($result) > 0 )
{
	while( $row = mysqli_fetch_assoc($result) )
	{
		if( $row['flag'] == 1 )
		{
			$x = "<a id=\"is-active-user\" href = user/active-passive-user.php?id=".$row['id']."&flag=0>فعال</a>";
		}
		elseif( $row['flag'] == 0)
		{
			$x = "<a id=\"is-passive-user\" href = user/active-passive-user.php?id=".$row['id']."&flag=1>غیر فعال</a>";
		}
		$d = "<a id=\"delete-user-label\" href = user/delete-user.php?id=".$row['id'].">حذف</a>";
		
		echo '
		 <tr>
		  <td>'.$row['id'].'</td>
		  <td>'.$row['username'].'</td>
		  <td>'.$row['password'].'</td>
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

</body>
</html>