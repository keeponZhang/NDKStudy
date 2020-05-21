package com.darren.ocr;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class MainActivity extends AppCompatActivity {
    private ImageView mCardIv;
    private Bitmap mCardBitmap;
    private TextView mCardNumberTv;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mCardIv = findViewById(R.id.card_iv);
        mCardNumberTv = findViewById(R.id.card_number_tv);
        mCardBitmap = BitmapFactory.decodeResource(getResources(),R.mipmap.card_n);
        mCardIv.setImageBitmap(mCardBitmap);
    }

	private static final String TAG = "MainActivity";
    public void cardOcr(View view) {
//	    saveBitmap();
        Log.e("TAG", "click cardOcr: " );
        String bankNumber = BankCardOcr.cardOcr(mCardBitmap);
        mCardNumberTv.setText(bankNumber);
    }
	public void saveBitmap() {
		String mPath = Environment.getExternalStorageDirectory().toString();
		Log.e(TAG, "保存图片"+mPath);
//		/storage/emulated/0
		File f = new File(mPath, "card.png");
		if (f.exists()) {
			f.delete();

		}




		try {
			f.createNewFile();
			FileOutputStream out = new FileOutputStream(f);
			mCardBitmap.compress(Bitmap.CompressFormat.PNG, 90, out);
			out.flush();
			out.close();
			Log.i("tag", "已经保存");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
