package com.darren.ndk.day05;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ImageView;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.


    private ImageView mFaceImage;
    private Bitmap mFaceBitmap;
    private FaceDetection mFaceDetection;
    private File mCascadeFile;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mFaceImage = findViewById(R.id.face_image);
        mFaceBitmap = BitmapFactory.decodeResource(getResources(),R.drawable.face);
        mFaceImage.setImageBitmap(mFaceBitmap);

        copyCascadeFile();

        mFaceDetection = new FaceDetection();
        mFaceDetection.loadCascade(mCascadeFile.getAbsolutePath());
    }

    private void copyCascadeFile() {
        try {
            // load cascade file from application resources
            InputStream is = getResources().openRawResource(R.raw.lbpcascade_frontalface);
            File cascadeDir = getDir("cascade", Context.MODE_PRIVATE);
            mCascadeFile = new File(cascadeDir, "lbpcascade_frontalface.xml");
            if(mCascadeFile.exists()) return;
            FileOutputStream os = new FileOutputStream(mCascadeFile);

            byte[] buffer = new byte[4096];
            int bytesRead;
            while ((bytesRead = is.read(buffer)) != -1) {
                os.write(buffer, 0, bytesRead);
            }
            is.close();
            os.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void faceDetection(View view) {
        // 识别人脸，保存人脸特征信息
        mFaceDetection.faceDetectionSaveInfo(mFaceBitmap);
        mFaceImage.setImageBitmap(mFaceBitmap);
    }
}
