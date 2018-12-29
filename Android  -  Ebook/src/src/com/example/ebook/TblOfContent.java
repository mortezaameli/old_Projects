package com.example.ebook;

import java.util.HashMap;
import java.util.List;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.SimpleAdapter;

public class TblOfContent extends Activity
{
	private ListView contentListView;
	
	private List< HashMap<String, Object> > books_list;
	
	private DatabaseAdapter db;
	
	
	@Override
	protected void onCreate(Bundle savedInstanceState) 
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_tbl_of_content);
		
		// --- SET RTL ---
        getWindow().getDecorView().setLayoutDirection(View.LAYOUT_DIRECTION_RTL);
		
		contentListView = (ListView) findViewById(R.id.tblOfContent_listview);
		
		db = new DatabaseAdapter(getBaseContext());
		db.createDatabase();
		db.open();
		
		books_list = db.getTableOfContent();
		
		db.close();
		
		String[] from = { "title", "author", "fav_flag", "see_flag" };
		int[] to = { R.id.txtTitle, R.id.txtAuthor, R.id.setFav, R.id.setSee };
		
		SimpleAdapter adapter = new SimpleAdapter(getBaseContext(), books_list, R.layout.tbl_content_list_row, from, to);
		contentListView.setAdapter(adapter);
		
		contentListView.setOnItemClickListener(new AdapterView.OnItemClickListener() 
		{
			@Override
			public void onItemClick(AdapterView<?> parent, View view, int position, long id) 
			{
				Intent intent = new Intent(getBaseContext(), BookContent.class);
				String myID = books_list.get(position).get("id").toString();
				intent.putExtra("id", myID);
				startActivity(intent);
				
			}
		});
	}
	
	
	@Override
	protected void onResume() 
	{
		onCreate(getIntent().getExtras());
	}
	
	
	public void onBtnBackClick( View v )
	{
		finish();
	}
	
}
