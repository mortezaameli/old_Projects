package com.example.ebook;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import android.content.Context;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DatabaseHelper extends SQLiteOpenHelper
{
	private Context main_context;

    private static String DB_PATH;
    private static String DB_NAME = "ebook_db.db";
    private static int DB_VERSION = 1;

    private SQLiteDatabase db;

    
	public DatabaseHelper(Context context) 
	{
		super(context, DB_NAME, null, DB_VERSION);
		main_context = context;
		//DB_PATH = main_context.getCacheDir().getPath() + "/" + DB_NAME;
		if(android.os.Build.VERSION.SDK_INT >= 17)
		{
			DB_PATH = context.getApplicationInfo().dataDir + "/databases/";
		}
		else
        {
           DB_PATH = context.getFilesDir().getParent() + "/databases/";
        }
	}

	
	@Override
	public void onCreate(SQLiteDatabase sq) 
	{
		/* do nothing */
	}

	
	@Override
	public void onUpgrade(SQLiteDatabase sq, int oldVersion, int newVersion) 
	{
		/* do nothing */
	}
	
	
	public void createDataBase() throws IOException
    {
        //If the database does not exist, copy it from the assets.
        if(!dbExists())
        {
            this.getReadableDatabase();
            this.close();
            try
            {
                //Copy the database from assests
                copyDB();
            }
            catch (IOException mIOException)
            {
                throw new Error("ErrorCopyingDataBase");
            }
        }
    }
	
	
	private boolean dbExists()
	{
		File f = new File(DB_PATH + DB_NAME);
		return f.exists();
	}

	
	private void copyDB() throws IOException
	{
		InputStream in = main_context.getAssets().open(DB_NAME);
		OutputStream out = new FileOutputStream(DB_PATH + DB_NAME);
		
		
		byte[] buffer = new byte[1024];
		int byteCount;
		
		while( (byteCount = in.read(buffer)) > 0 )
		{
			out.write(buffer, 0, byteCount);
		}
		
		out.flush();
		out.close();
		in.close();
	}
	
	
	public boolean open() throws SQLException
	{
		db = SQLiteDatabase.openDatabase(DB_PATH + DB_NAME, null, SQLiteDatabase.CREATE_IF_NECESSARY);
		return db != null;
	}
	
	
	@Override
	public synchronized void close() 
	{
		if(db != null)
			db.close();
		super.close();
	}
	
}
