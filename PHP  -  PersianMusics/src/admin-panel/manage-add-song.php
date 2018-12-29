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
<title>افزودن موزیک</title>

<?php
include ("jdf.php");
include ("conncet-db.php");

if( isset($_POST['music-submit']) )
{
											/*image upload*/
	$target_dir = "upload/pic/";
	$target_file = $target_dir . $_FILES["image-up"]["name"];
	$image_path = $target_file;
	$uploadOk = 1;
	$imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);
	 
	// Check if file already exists
	if (file_exists($target_file))
	{
		echo "<script>alert('فایلی با همین نام وجود دارد')</script>";
		$uploadOk = 0;
	}
	// Check if $uploadOk is set to 0 by an error
	if ($uploadOk == 0)
	{
		echo "<script>alert('فایل آپلود نشد')</script>";
	}
	else // if everything is ok, try to upload file
	{
		if (move_uploaded_file($_FILES["image-up"]["tmp_name"], $target_file))
		{
			echo "<script>alert('فایل آپلود شد')</script>";
		}
		else
		{
			echo "<script>alert('فایل آپلود نشد')</script>";
		}
	}
	
											/*audio upload*/
	$target_dir = "upload/song/";
	$target_file = $target_dir . $_FILES["audio-up"]["name"];
	$audio_path = $target_file;
	$uploadOk = 1;
	$imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);
	// Check if file already exists
	if (file_exists($target_file))
	{
		echo "<script>alert('فایلی با همین نام وجود دارد')</script>";
		$uploadOk = 0;
	}
	// Check if $uploadOk is set to 0 by an error
	if ($uploadOk == 0)
	{
		echo "<script>alert('فایل آپلود نشد')</script>";
	}
	else // if everything is ok, try to upload file
	{
		if (move_uploaded_file($_FILES["audio-up"]["tmp_name"], $target_file))
		{
			echo "<script>alert('فایل آپلود شد')</script>";
		}
		else
		{
			echo "<script>alert('فایل آپلود نشد')</script>";
		}
	}
	
										/*insert in songtbl*/								
				
	$sql = sprintf("INSERT INTO `songtbl` (`id`, `name`, `songer`, `image_path`, `song_path`, `group`, `date`, `flag`) VALUES (NULL, '%s', '%s', '%s', '%s', '%s', '%s', '0');", $_POST['music-name'], $_POST['songer-name'], $image_path, $audio_path, $_POST['music-group'], jdate('H:i:s ,Y/n/j'));
	
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
    	<div id="add-musics-box">
        	<div id="add-musics-box-triangle"></div>
            <img class="exit-box-pic" src="icon/cross108.png" width="20" height="20" alt=""/>
            <form method="post" enctype="multipart/form-data">
            	<textarea id="misic-name-area" name="music-name" placeholder="نام موزیک..." autofocus></textarea>
                <textarea id="songer-name-area" name="songer-name" placeholder="نام خواننده..."></textarea>
                <textarea id="music-group-area" name="music-group" placeholder="دسته ی موزیک..."></textarea>
                <div class="fileUpload btn btn-primary">
                    <span>آپلود تصویر</span>
                    <input id="upload-image-Btn" type="file" class="upload" accept="image/*" name="image-up"/>
                </div>
                <input id="upload-image-File" placeholder="تصویر خود را آپلود کنید" disabled="disabled" />
                <br/>
                <div class="fileUpload btn btn-primary">
                    <span>آپلود موزیک</span>
                    <input id="upload-audio-Btn" type="file" class="upload" accept="audio/*" name="audio-up"/>
                </div>
                <input id="upload-audio-File" placeholder="موزیک خود را آپلود کنید" disabled="disabled" />
                <br />
                <input type="submit" name="music-submit" id="music-submit-btn" value="ارسال آهنگ">
            </form>    
        </div>
    </div>
</div>

</body>
</html>