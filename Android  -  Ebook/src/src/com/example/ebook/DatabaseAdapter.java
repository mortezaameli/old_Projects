package com.example.ebook;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;

public class DatabaseAdapter 
{
    private SQLiteDatabase db;
    private DatabaseHelper DbHelper;
    
    private static String DB_TBL_BOOKS = "books";
    //private static String DB_TBL_SETTINGS = "settings";

    
    public DatabaseAdapter(Context context)
    {
        DbHelper = new DatabaseHelper(context);
    }

    
    public DatabaseAdapter createDatabase() throws SQLException
    {
        try
        {
            DbHelper.createDataBase();
        }
        catch (IOException mIOException)
        {
            throw new Error("UnableToCreateDatabase");
        }
        return this;
    }

    
    public DatabaseAdapter open() throws SQLException
    {
        try
        {
            DbHelper.open();
            DbHelper.close();
            db = DbHelper.getWritableDatabase();
        }
        catch (SQLException mSQLException)
        {
            throw mSQLException;
        }
        
        return this;
    }

    
    public void close()
    {
        DbHelper.close();
    }
    
    
    public boolean setBookVisitState(int id, int state) 
    {
		ContentValues cv = new ContentValues();
		
		cv.put("see_flag", state);
		
		long result = db.update(DB_TBL_BOOKS, cv, "id = ?", new String[] {String.valueOf(id)});
		
		if(result < 1 )
			return false;
		else
			return true;
	}
    
    
    public boolean setBookFavoriteState(int id, int state) 
    {
		ContentValues cv = new ContentValues();
		
		cv.put("fav_flag", state);
		
		long result = db.update(DB_TBL_BOOKS, cv, "id = ?", new String[] {String.valueOf(id)});
		
		if(result < 1 )
			return false;
		else
			return true;
	}
    
    
    public int getBookVisitState(int id)
    {
    	Cursor result = db.rawQuery("SELECT * FROM " + DB_TBL_BOOKS + " WHERE id = '" + id + "'", null);
    	result.moveToFirst();
    	
    	return Integer.parseInt(result.getString(6));
    }
    
    
    public int getBookFavoriteState(int id)
    {
    	Cursor result = db.rawQuery("SELECT * FROM " + DB_TBL_BOOKS + " WHERE id = '" + id + "'", null);
    	result.moveToFirst();
    	
    	return Integer.parseInt(result.getString(5));
    	
    	
    }
    
    
    public List< HashMap<String, Object> > getTableOfContent()
    {
    	Cursor result = db.rawQuery("SELECT * FROM "  + DB_TBL_BOOKS, null);
    	
    	List< HashMap<String, Object> > all_book = new ArrayList<HashMap<String,Object>>();
    	
    	while(result.moveToNext())
    	{
    		HashMap<String, Object> book = new HashMap<String, Object>();
    		
    		book.put("id", result.getString(0));
    		book.put("title", result.getString(1));
    		book.put("author", result.getString(3));
    		
    		if(result.getString(5).equals("1"))
    			book.put("fav_flag", R.drawable.is_favorite);
    		else
    			book.put("fav_flag", R.drawable.not_favorite);
    		
    		if(result.getString(6).equals("1"))
    			book.put("see_flag", R.drawable.see);
    		else
    			book.put("see_flag", R.drawable.not_see);
    		
    		all_book.add(book);
    	}
    	
    	return all_book;
    }
    
    
    public HashMap<String, Object> getBookContent(String id)
    {
    	Cursor result = db.rawQuery("SELECT * FROM " + DB_TBL_BOOKS + " WHERE id = '" + id + "'", null);
    	result.moveToFirst();
    	
    	HashMap<String, Object> book = new HashMap<String, Object>();
    	
    	book.put("id", result.getString(0));
    	book.put("title", result.getString(1));
    	book.put("content", result.getString(2));
    	book.put("author", result.getString(3));
    	book.put("date", result.getString(4));
    	
    	if(result.getString(5).equals("1"))
    		book.put("fav_flag", R.drawable.is_favorite);
    	else
    		book.put("fav_flag", R.drawable.not_favorite);
    	
    	if(result.getString(6).equals("1"))
    		book.put("see_flag", R.drawable.see);
    	else
    	{
    		if(setBookVisitState(Integer.parseInt(id), 1))
    			book.put("see_flag", R.drawable.see);
    		else
    			book.put("see_flag", R.drawable.not_see);
    	}
    	
    	return book;
    }
    
    
    public List< HashMap<String, Object> > getTableOfFavoriteContent()
    {
    	Cursor result = db.rawQuery("SELECT * FROM "  + DB_TBL_BOOKS + " WHERE fav_flag='1' ", null);
    	
    	List< HashMap<String, Object> > all_book = new ArrayList<HashMap<String,Object>>();
    	
    	while(result.moveToNext())
    	{
    		HashMap<String, Object> book = new HashMap<String, Object>();
    		
    		book.put("id", result.getString(0));
    		book.put("title", result.getString(1));
    		book.put("author", result.getString(3));
    		book.put("fav_flag", R.drawable.is_favorite);
    		
    		if(result.getString(6).equals("1"))
    			book.put("see_flag", R.drawable.see);
    		else
    			book.put("see_flag", R.drawable.not_see);
    		
    		all_book.add(book);
    	}
    	
    	return all_book;
    }
    
}
