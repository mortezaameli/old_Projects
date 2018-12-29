$(document).ready(function() {
    $('#login-btn').click(function(){
		$("#register").slideUp(0);
		$("#login").slideToggle('slow');
  	});
	
	$('#register-btn').click(function(){
		$("#login").slideUp(0);
		$("#register").slideToggle('slow');
  	});
	///////////////////////////////////////////////////
	$(".musics-box .song-link").hide();
	$(".musics-pic").hover(function() {
		$(this).find(".song-link").fadeToggle(0);
	});
	///////////////////////////////////////////////////
	$(".news-content .down-arrow").click(function() {
		var x = $(this).parent(this);
		x.find(".news-text").slideToggle('fast');
		x.find(".down-arrow").hide(0);
		x.find(".up-arrow").show(0);
		
	});
	$(".news-content .up-arrow").click(function() {
		var x = $(this).parent(this);
		x.find(".news-text").slideToggle(400);
		x.find(".up-arrow").hide(0);
		x.find(".down-arrow").show(0);
		
	});
});