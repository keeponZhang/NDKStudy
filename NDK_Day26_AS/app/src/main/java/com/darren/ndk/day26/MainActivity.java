package com.darren.ndk.day26;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Person[] persons1 = new Person[10];
        for (int i = 0; i < persons1.length; i++) {
            persons1[i] = new Person("Darren", 24 + i);
        }

        // java 层赋值
        Person[] newPersons = new Person[10];
        /*
        for (int i = 0; i < newPersons.length; i++) {
            newPersons[i] = persons1[i];
        }*/

        try {
            arraycopy(persons1, 0, newPersons, 0, 10);
        } catch (Exception e) {
            e.printStackTrace();
        }


        for (int i = 0; i < newPersons.length; i++) {
            Log.e("TAG", newPersons[i].toString());
        }
    }

    public static native void arraycopy(Object src, int srcPos,
                                        Object dest, int destPos,
                                        int length);
}
