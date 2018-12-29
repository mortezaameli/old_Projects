package com.example.ebook;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

public class Search extends Activity
{
	@Override
	protected void onCreate(Bundle savedInstanceState) 
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_search);
		
		// --- SET RTL ---
        getWindow().getDecorView().setLayoutDirection(View.LAYOUT_DIRECTION_RTL);
	}
}
