package com.example.ebook;

import android.net.Uri;
import android.os.Bundle;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.Intent;
import android.graphics.Typeface;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends Activity
{
    @Override
    protected void onCreate(Bundle savedInstanceState) 
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // --- SET RTL ---
        getWindow().getDecorView().setLayoutDirection(View.LAYOUT_DIRECTION_RTL);
        
        // --- SET FONT TO LOGO NAME ---
        Typeface b_Kaj_typeface = Typeface.createFromAsset(getAssets(), getString(R.string.logo_font_name));
        TextView text_logo = (TextView) findViewById(R.id.txtLogo);
        text_logo.setTypeface(b_Kaj_typeface);
    }
    
    
    public void onBtnTblOfContentClick( View v )
    {
    	Intent i = new Intent(this, TblOfContent.class);
    	startActivity(i);
    }
    
    
    public void onBtnFavoriteClick( View v )
    {
    	Intent i = new Intent(this, TblOfFavoriteBooks.class);
    	startActivity(i);
    }
    
    
    public void onBtnSearchClick( View v )
    {
    	Intent i = new Intent(this, Search.class);
    	startActivity(i);
    }
    
    
    public void onBtnSettingsClick( View v )
    {
    	
    }
    
    
    public void onBtnAboutMeClick( View v )
    {
    	showAlert( getString(R.string.about_me_title), getString(R.string.about_me_message), true );
    }
    
    
    public void onBtnWebsiteClick( View v )
    {
    	Uri uri = Uri.parse( getString(R.string.website_url) );
    	Intent intent = new Intent(Intent.ACTION_VIEW, uri);
    	startActivity(intent);
    }
    
    
    public void onBtnContactClick( View v )
    {
    	showAlert( getString(R.string.contact_me_title), getString(R.string.contact_me_message), true );
    }
    
    
    public void onBtnExitClick( View v )
    {
    	finish();
    }
    
    
    private void showAlert(String title, String message, boolean cancelable)
    {
    	AlertDialog.Builder _alert= new AlertDialog.Builder(this);
    	_alert.setTitle(title)
    		  .setMessage(message)
    		  .setCancelable(cancelable)
    		  .show();
    }
    
}
