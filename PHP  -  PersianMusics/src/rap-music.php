<?php
session_start();
ob_start();
?>
<?php
if(  isset($_POST['log-out']) )
{
	$_SESSION['login'] = NULL;
	//header("location:register.php");
}
?>
<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>پرشین موزیک</title>
<script src="js/jquery-2.1.4.min.js"></script>
<script src="js/script.js"></script>
<link rel="stylesheet" type="text/css" href="css/style.css" />
</head>

<body>

<?php
if( !isset($_SESSION['login']) )
{
	header("location:register.php");
}
?>

<div id="temp"></div>
<ul id="menu">
	<li><a href="index.php">خانه</a></li>
    <li><a href="pap-music.php">موسیقی پاپ</a></li>
    <li><a href="rap-music.php">موسیقی رپ</a></li>
    <li><a href="index.php">جدیدترین ها</a></li>
    <li>
    	<form method="post">
            <input id="log-out-btn" name="log-out" type="submit" value="خروج" />
		</form>
    </li>
</ul>

<img id = "cover" src="pic/Blue-Music-Background-1024x640.jpg" width="100%" height="240" alt=""/>
<a href="index123.php"><img src="pic/cooltext138300984070584.png"  alt="" width="400" height="43" id = "logo"/></a>
<div class="musics-box">
<div class="musics-header">دانلود آخرین آهنگ ها</div>
    <table border=0 cellspacing="0"> 
          
<?php
include ("admin-panel/conncet-db.php");
include ("admin-panel/jdf.php");

$rec_limit = 6;
//Get total number of records
$sql = "SELECT count(id) FROM songtbl where `flag`='1' and `group` = 'رپ'";
$retval = mysqli_query($conn, $sql);

$row = mysqli_fetch_array($retval, MYSQLI_NUM );
$rec_count = $row[0];
//Calculate page number and offset
if( !isset($_GET['page'] ) )
{
	$page = 1;
	$offset = 0;
}
else
{
	$page = $_GET['page'];
	$offset = $rec_limit * ($page-1) ;
}
//Fetch data from database
$left_rec = $rec_count - (($page-1) * $rec_limit);

$sql = "SELECT * FROM songtbl where `flag`='1' and `group` = 'رپ' ORDER BY `date` DESC LIMIT $offset, $rec_limit"; 
$retval = mysqli_query($conn, $sql);

if(mysqli_num_rows($retval) > 0)
{
	$count_td = 0;
	while( $row = mysqli_fetch_assoc($retval) )
	{
		if($count_td == 0)
		{
			echo '<tr>';
		}
		
		echo '
			<td>
				<div class="musics-pic">
					<img class="img-for-musics" src="admin-panel/'.$row['image_path'].'" alt=""/>
					<a class="song-link" href="admin-panel/'.$row['song_path'].'" download>*'.$row['name'].'*<br />*'.$row['songer'].'*</a>
					<audio controls preload="none" class="music-player">
						<source src="admin-panel/'.$row['song_path'].'" type="audio/mp3">    
					</audio>
				</div>
			</td>';
			
		$count_td ++;
		
		if($count_td == 3)
		{
			echo '</tr>';
			$count_td = 0;
		}	
	}
}

echo '</table>';

$host = "localhost";
$adrs = "http://" . $host . $_SERVER['PHP_SELF'];

if( $page == 1 )
{
	$page = $page + 1;
	echo "<a class=\"pagging\" href=\"$adrs?page=$page\">بعدی</a>";
}
else if( $page > 1 && $left_rec > $rec_limit)
{
	$last = $page - 1;
	$page = $page + 1; 
	echo "<a class=\"pagging\" href=\"$adrs?page=$last\">قبلی</a>";
	echo "<a class=\"pagging\" href=\"$adrs?page=$page\">بعدی</a>";
}
else if( $page > 1 && $left_rec == $rec_limit)
{
	$page = $page - 1;
	echo "<a class=\"pagging\" href=\"$adrs?page=$page\">قبلی</a>";
}

else if( $left_rec < $rec_limit )
{
	$last = $page - 1;
	echo "<a class=\"pagging\" href=\"$adrs?page=$last\">قبلی</a>";
}

mysqli_close($conn);
?>
         
</div>
<div class="news-box">
    <div class="news-header">لیست آخرین خبرها</div>
    
<?php
include ("admin-panel/conncet-db.php");

$rec_limit = 7;
//Get total number of records
$sql = "SELECT count(id) FROM newstbl";
$retval = mysqli_query($conn, $sql);

$row = mysqli_fetch_array($retval, MYSQLI_NUM );
$rec_count = $row[0];
//Calculate page number and offset
if( !isset($_GET['news_page'] ) )
{
	$page = 1;
	$offset = 0;
}
else
{
	$page = $_GET['news_page'];
	$offset = $rec_limit * ($page-1) ;
}
//Fetch data from database
$left_rec = $rec_count - (($page-1) * $rec_limit);

$sql = "SELECT * FROM newstbl where flag='1' ORDER BY  date DESC LIMIT $offset, $rec_limit";  
$retval = mysqli_query($conn, $sql);

if(mysqli_num_rows($retval) > 0)
{
	while( $row = mysqli_fetch_assoc($retval) )
	{
		echo '
		<div class="news-content">'.$row['title'].'
            <div class="news-text">'.$row['text'].'</div>
        	<img class="down-arrow" src="admin-panel/icon/down.png" width="12" height="12" alt=""/>
            <img class="up-arrow"src="admin-panel/icon/up.png" width="12" height="12" alt=""/>
        </div>';
	}
}

$host = "localhost";
$adrs = "http://" . $host . $_SERVER['PHP_SELF'];

if( $page == 1 )
{
	$page = $page + 1;
	echo "<a class=\"pagging\" href=\"$adrs?news_page=$page\">بعدی</a>";
}
else if( $page > 1 && $left_rec > $rec_limit)
{
	$last = $page - 1;
	$page = $page + 1; 
	echo "<a class=\"pagging\" href=\"$adrs?news_page=$last\">قبلی</a>";
	echo "<a class=\"pagging\" href=\"$adrs?news_page=$page\">بعدی</a>";
}
else if( $page > 1 && $left_rec == $rec_limit)
{
	$page = $page - 1;
	echo "<a class=\"pagging\" href=\"$adrs?news_page=$page\">قبلی</a>";
}
else if( $left_rec < $rec_limit )
{
	$last = $page - 1;
	echo "<a class=\"pagging\" href=\"$adrs?news_page=$last\">قبلی</a>";
}

mysqli_close($conn);
?>

</div>   
<div class="footer"></div>
    

</body>
</html>