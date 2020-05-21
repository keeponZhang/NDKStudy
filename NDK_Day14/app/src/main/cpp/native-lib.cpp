#include <jni.h>
#include <string>
#include <malloc.h>
#include "com_darren_ndk_day14_Parcel.h"
extern "C"
JNIEXPORT jstring

JNICALL
Java_com_darren_ndk_day14_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

// 结构体和对象 Parcel.cpp
class Parcel{
    char* mData;// char 1 共享内存的首地址
    int mDataPos = 0; // =0 结构体怎么说的？

public:
    Parcel(){
        mData = (char *) malloc(1024);
    }

    void writeInt(jint value) {
        *reinterpret_cast<int*>(mData+mDataPos) = value;// 0 4
        mDataPos += sizeof(int);
    }

    void setDataPosition(jint position) {
        mDataPos = position;
    }

    jint readInt() {
        int result = *reinterpret_cast<int*>(mData+mDataPos);// 0 -> 12
        mDataPos += sizeof(int);
        return result;
    }
};

JNIEXPORT jlong JNICALL Java_com_darren_ndk_day14_Parcel_nativeCreate
        (JNIEnv *, jobject){
    Parcel *parcel = new Parcel();
    return (jlong)parcel;
}

JNIEXPORT void JNICALL Java_com_darren_ndk_day14_Parcel_nativeWriteInt
        (JNIEnv *, jobject,jlong nativePtr,jint value){
    // 写
    Parcel* parcel = reinterpret_cast<Parcel*>(nativePtr);
    parcel->writeInt(value);
}

JNIEXPORT void JNICALL Java_com_darren_ndk_day14_Parcel_nativeSetDataPosition
        (JNIEnv *, jobject,jlong nativePtr,jint value){
    Parcel *parcel = (Parcel *) nativePtr;
    parcel->setDataPosition(value);
}

JNIEXPORT jint JNICALL Java_com_darren_ndk_day14_Parcel_nativeReadInt
        (JNIEnv *, jobject,jlong nativePtr){
    Parcel *parcel = (Parcel *) nativePtr;
    return parcel->readInt();
}
