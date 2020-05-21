package com.darren.ndk.day14

/**
 * Created by hcDarren on 2018/4/22.
 */
public class Parcel{
    private var mNativePtr: Long = 0

    init {
        System.loadLibrary("native-lib")
        mNativePtr = nativeCreate()
    }

    fun writeInt(value: Int) {
        nativeWriteInt(mNativePtr, value)
    }

    fun setDataPosition(dataPost: Int) {
        nativeSetDataPosition(mNativePtr, dataPost)
    }
    fun readInt(): Int {
        return nativeReadInt(mNativePtr)
    }

    // C 层构建一个 Parcel.cpp 的对象，然后指针地址
    private external fun nativeCreate(): Long
    // 写 int
    private external fun nativeWriteInt(mNativePtr: Long, value: Int)
    // 写完之后重新设置偏移位置
    private external fun nativeSetDataPosition(mNativePtr: Long, dataPost: Int)
    // 读 int
    private external fun nativeReadInt(nativePtr: Long): Int
}