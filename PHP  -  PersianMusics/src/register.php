<?php
session_start();
ob_start();
?>
<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>ورود یا ثبت نام کاربران</title>
<script src="js/jquery-2.1.4.min.js"></script>
<script src="js/script.js"></script>
<link rel="stylesheet" type="text/css" href="css/style.css" />
</head>

<body>
<?php
if( isset($_SESSION['not-confirm-pass']) )
{
	echo '<script>alert("رمز عبور را درست وارد کنید");</script>';
}

if( isset($_SESSION['is-registered']) )
{
	echo '<script>alert("بعد از تایید مدیر سایت شما عضو سایت خواهید شد");</script>';
	$_SESSION['is-registered'] = NULL;
}
?>
<div id="temp"></div>
<ul id="menu">
    <li>
    	<span id="login-btn">ورود</span>
    	<div id="login">
           <div class="triangle"></div>
          <h1>فرم ورود به سایت</h1>
          <form method="post" action="admin-panel/user/check-user.php">
            <input name="username" type="text" placeholder="نام کاربری" />
            <input name="password" type="password" placeholder="رمز عبور" />
            <input name="login-submit" type="submit" value="ارسال" />
          </form>
        </div>
	</li>
    <li>
    	<span id="register-btn">ثبت نام</span>
    	<div id="register">
           <div class="triangle"></div>
          <h1>فرم ثبت نام سایت</h1>
          <form method="post" action="admin-panel/user/insert-user.php">
            <input name="username" type="text" placeholder="نام کاربری" />
            <input name="password" type="password" placeholder="رمز عبور" />
            <input name="confirm-password" type="password" placeholder="رمز عبور را دوباره وارد کنید" />
            <input name="register-submit" type="submit" value="ارسال" />
          </form>
        </div>
	</li>
</ul>
<!--div id = "banner">
    <img id = "cover" src="img/best-music-background_090305610.jpg" width="100%" height="500" alt=""/>
	<img id = "logo" src="img/cooltext134379043519588.png" width="476" height="100" alt=""/> 
</div-->


<div style="clear:both;">
	<div class="musics-box">
    	<div class="musics-header">دانلود آخرین آهنگ ها</div>
    </div>
    <div class="news-box">
    	<div class="news-header">لیست آخرین خبرها</div>
    </div>
</div>
</body>
</html>