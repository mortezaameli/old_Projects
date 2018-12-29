$(document).ready(function() {
	
	/*Show click content and hide other useless content*/
    /*$("#news-btn").click(function() {
		$("#musics-content").hide(0);
		$("#group-content").hide(0);
		$("#user-content").hide(0);
		$("#news-content").slideDown(500);
	});
	
	$("#musics-btn").click(function() {
		$("#news-content").hide(0);
		$("#group-content").hide(0);
		$("#user-content").hide(0);
		$("#musics-content").slideDown(500);
		
	});
	
	$("#group-btn").click(function() {
		$("#news-content").hide(0);
		$("#musics-content").hide(0);
		$("#user-content").hide(0);
		$("#group-content").slideDown(500);
	});
	
	$("#user-btn").click(function() {
		$("#news-content").hide(0);
		$("#musics-content").hide(0);
		$("#group-content").hide(0);
		$("#user-content").slideDown(500);
	});*/
	
	/*Exit for click on the X in main content*/
	$(".exit-content-pic").click(function() {
		$("#news-content").hide(0);
		$("#musics-content").hide(0);
		$("#group-content").hide(0);
		$("#user-content").hide(0);
	});
	
	/*Exit for click on the X in sub-content*/
	$(".exit-box-pic").click(function() {
		$("#add-news-box").hide(0);
		$("#display-news-box").hide(0);
		$("#add-musics-box").hide(0);
		$("#display-musics-box").hide(0);
	});
	
	/*Show click content and hide other useless sub-content FOR News*/
	/*$("#add-news-btn").click(function() {
		$("#display-news-box").hide(0);
		$("#add-news-box").slideDown(300);
	});
	
	$("#display-news-btn").click(function() {
		$("#add-news-box").hide(0);
		$("#display-news-box").slideDown(300);
	});*/
	
	/*Show click content and hide other useless sub-content FOR Musics*/
	/*$("#add-musics-btn").click(function() {
		$("#display-musics-box").hide(0);
		$("#add-musics-box").slideDown(300);
	});
	
	$("#display-musics-btn").click(function() {
		$("#add-musics-box").hide(0);
		$("#display-musics-box").slideDown(300);
	});*/
	
	/*news-submit-btn*/
	/*$("#news-submit-btn").click(function() {
		alert('خبر ارسال شد');
	});*/
	
	/*image and audiofile upload btn*/
	document.getElementById("upload-image-Btn").onchange = function () {
    document.getElementById("upload-image-File").value = this.value;
	};
	
	document.getElementById("upload-audio-Btn").onchange = function () {
    document.getElementById("upload-audio-File").value = this.value;
	};
	
	
});