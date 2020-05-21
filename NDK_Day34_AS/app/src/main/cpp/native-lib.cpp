#include <jni.h>
#include <string>
#include "LinkedList.hpp"
#include <android/log.h>

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_ndk_day34_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    // 测试代码
    /*LinkedList<int> linkedList;

    time_t start = clock();
    for (int i = 0; i < 5; ++i) {
        linkedList.push(i);
    }
    time_t end = clock();

    for (int i = 0; i < linkedList.size(); ++i) {
        __android_log_print(ANDROID_LOG_ERROR,"TAG","%d",linkedList.get(i));
    }*/

    // __android_log_print(ANDROID_LOG_ERROR, "TAG", "%d", (end - start) / CLOCKS_PER_SEC);

    LinkedList<int> linkedList;
    linkedList.push(0);
    linkedList.push(1);
    linkedList.push(2);
    linkedList.push(3);
    linkedList.push(4);
    linkedList.push(5);

    /*linkedList.insert(0,-1);
    linkedList.insert(linkedList.size(),3);
    linkedList.insert(2,22);

    linkedList.remove(0);
    linkedList.remove(linkedList.size()-1);
    linkedList.remove(2);*/

    for (int i = 0; i < linkedList.size(); ++i) {
        __android_log_print(ANDROID_LOG_ERROR,"TAG","%d",linkedList.get(i));
    }

    return env->NewStringUTF(hello.c_str());
}
