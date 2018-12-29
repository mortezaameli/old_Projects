package com.example.ebook;

import java.util.HashMap;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.webkit.WebView;
import android.widget.ImageView;
import android.widget.TextView;

public class BookContent extends Activity
{
	private DatabaseAdapter db;
	
	private HashMap<String, Object> book;
	
	private TextView title, author, date;
	private WebView content;
	private ImageView fav, visit;
	
	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_book_content);
		
		// --- SET RTL ---
        getWindow().getDecorView().setLayoutDirection(View.LAYOUT_DIRECTION_RTL);
        
		db = new DatabaseAdapter(getBaseContext());
		
		title = (TextView) findViewById(R.id.txtBookTitle);
		author = (TextView) findViewById(R.id.txtBookAuthor);
		date = (TextView) findViewById(R.id.txtBookDate);
		content = (WebView) findViewById(R.id.WebViewBookContent);
		fav = (ImageView) findViewById(R.id.imgFavorite);
		visit = (ImageView) findViewById(R.id.imgSee);
		Bundle data = getIntent().getExtras();
		
		db.open();
		book = db.getBookContent(data.getString("id"));
		db.close();
		
		title.setText(book.get("title").toString());
		author.setText(book.get("author").toString());
		date.setText(book.get("date").toString());
		
		String main_txt =
                "<html>" +
                    "<head><meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\" /><head>" +
                    "<body dir='rtl' style='font-size: 18px; text-align: justify;' >" +
                    book.get("content").toString() +
                    "</body>" +
                "</html>";
		
		content.loadData(main_txt, "text/html;charset='UTF-8'", "UTF-8");
		content.setBackgroundColor(0x00000000);
		
		fav.setImageResource(Integer.parseInt(book.get("fav_flag").toString()));
		visit.setImageResource(Integer.parseInt(book.get("see_flag").toString()));
	}
	
	
	public void onBtnBackClick(View v)
	{
		finish();
	}
	
	
	public void onShareTextClick(View v)
	{
		Intent i = new Intent(Intent.ACTION_SEND);
		i.setType("text/plain");
		i.putExtra(Intent.EXTRA_SUBJECT, "subject");
		i.putExtra(Intent.EXTRA_TEXT, book.get("content").toString());
		
		startActivity(Intent.createChooser(i, "sending"));
	}
	
	
	public void onImgFavoriteClick(View v)
	{
		db.open();
		
		int id = Integer.parseInt(book.get("id").toString());
		
		if(db.getBookFavoriteState(id) == 1)
		{
			db.setBookFavoriteState(id, 0);
			fav.setImageResource(R.drawable.not_favorite);
		}
		else
		{
			db.setBookFavoriteState(id, 1);
			fav.setImageResource(R.drawable.is_favorite);
		}
		
		db.close();
	}
	
	
	public void onImgSeeClick(View v)
	{
		db.open();
		
		int id = Integer.parseInt(book.get("id").toString());
		
		if(db.getBookVisitState(id) == 1)
		{
			db.setBookVisitState(id, 0);
			visit.setImageResource(R.drawable.not_see);
		}
		else
		{
			db.setBookVisitState(id, 1);
			visit.setImageResource(R.drawable.see);
		}
		
		db.close();
	}

}
