package com.darren.ocr;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

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

    public void cardOcr(View view) {
        String bankNumber = BankCardOcr.cardOcr(mCardBitmap);
        mCardNumberTv.setText(bankNumber);
    }
}
