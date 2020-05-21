package com.darren.ndk.day14;

import android.os.Parcel;
import android.os.Parcelable;

/**
 * Created by hcDarren on 2018/4/22.
 */

public class Student implements Parcelable{
    protected Student(Parcel in) { // gg
        in.readString();
        in.readInt();// char*
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeInt(12);
        dest.writeString("Darren");
    }

    @Override
    public int describeContents() {
        return 0;
    }

    public static final Creator<Student> CREATOR = new Creator<Student>() {
        @Override
        public Student createFromParcel(Parcel in) {
            return new Student(in);
        }

        @Override
        public Student[] newArray(int size) {
            return new Student[size];
        }
    };
}
