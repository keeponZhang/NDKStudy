package com.darren.ndk.day03;

import android.Manifest;
import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;

import com.tbruyelle.rxpermissions2.RxPermissions;

import java.io.File;

import io.reactivex.Observable;
import io.reactivex.android.schedulers.AndroidSchedulers;
import io.reactivex.functions.Consumer;
import io.reactivex.functions.Function;
import io.reactivex.schedulers.Schedulers;

public class MainActivity extends AppCompatActivity {
    private File mInFile = new File(Environment.getExternalStorageDirectory(),"test.mp4");
    private File mOutFile = new File(Environment.getExternalStorageDirectory(),"out.mp4");

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // ffmpeg -i test.mp4 -b:v 1024k out.mp4
        // -b:v 码率是什么？ 码率越高视频越清晰，而且视频越大
        // 1M  1024K
        // test.mp4 需要压缩的视频路径
        // out.mp4 压缩后的路径


    }

    public void compressVideo(View view) {
        RxPermissions rxPermissions = new RxPermissions(this);
        rxPermissions.request(Manifest.permission.READ_EXTERNAL_STORAGE, Manifest.permission.WRITE_EXTERNAL_STORAGE)
                .subscribe(new Consumer<Boolean>() {
                    @Override
                    public void accept(Boolean aBoolean) throws Exception {
                        if(aBoolean){
                            compressVideo();
                        }
                    }
                });
    }

    private void compressVideo() {
        String[] compressCommand = {"ffmpeg","-i",mInFile.getAbsolutePath(),"-b:v","1024k",mOutFile.getAbsolutePath()};

        Observable.just(compressCommand)
                .map(new Function<String[], File>() {
                    @Override
                    public File apply(String[] compressCommand) throws Exception {
                        // 压缩是耗时的，子线程，处理权限
                        VideoCompress videoCompress = new VideoCompress();
                        videoCompress.compressVideo(compressCommand, new VideoCompress.CompressCallback() {
                            @Override
                            public void onCompress(int current, int total) {
                                Log.e("TAG","压缩进度："+current+"/"+total);
                            }
                        });
                        return mOutFile;
                    }
                }).subscribeOn(Schedulers.io())
                .observeOn(AndroidSchedulers.mainThread())
                .subscribe(new Consumer<File>() {
                    @Override
                    public void accept(File file) throws Exception {
                        // 压缩完成
                        Log.e("TAG","压缩完成");
                    }
                });
    }
}
