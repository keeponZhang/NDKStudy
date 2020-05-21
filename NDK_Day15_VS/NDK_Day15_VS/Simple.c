#include "com_darren_day15_Simple1.h"
#include <stdlib.h>

int compare(const jint *number1, const jint *number2){
	return *number1 - *number2;
}

// 全局变量
jstring globalStr;

JNIEXPORT void JNICALL Java_com_darren_day15_Simple1_sort
(JNIEnv * env, jclass jclz, jintArray jarray){

	// 对 jarray 进行排序 （sort）
	jint* intArray = (*env)->GetIntArrayElements(env,jarray,NULL);

	int length = (*env)->GetArrayLength(env,jarray);

	// 第一个参数：void* 数组的首地址
	// 第二个参数：数组的大小长度
	// 第三个参数：数组元素数据类型的大小
	// 第四个参数：数组的一个比较方法指针（Comparable）
	qsort(intArray, length, sizeof(int), compare);

	// 同步数组的数据给 java 数组 intArray 并不是 jarray ，可以简单的理解为 copy
	// 0 : 既要同步数据给 jarray ,又要释放 intArray
	// JNI_COMMIT:  会同步数据给 jarray ，但是不会释放 intArray
	// JNI_ABORT: 不同步数据给 jarray ，但是会释放 intArray
	(*env)->ReleaseIntArrayElements(env,jarray,intArray,JNI_ABORT);
}

JNIEXPORT void JNICALL Java_com_darren_day15_Simple1_localRef
(JNIEnv *env, jclass jclz){
	// 在 native 层构建的 Java 对象，你不用了该怎么管理？
	// native 层开辟的内存由谁管理，你能开辟多大

	// 字符串截取，String 对象
	jclass str_clz = (*env)->FindClass(env,"java/lang/String");
	jmethodID init_mid = (*env)->GetMethodID(env,str_clz,"<init>","()V");
	jobject j_str = (*env)->NewObject(env, str_clz, init_mid);

	// 还有 100 行代码

	// jobject 不要再使用了，要回收 javaGC 的源码
	(*env)->DeleteLocalRef(env,j_str);

	// 删除了就不能再使用了，C 和 C++ 都需要自己释放内存（静态开辟的不需要，动态开辟的需要）

}

JNIEXPORT void JNICALL Java_com_darren_day15_Simple1_saveGlobalRef
(JNIEnv *env, jclass jclz, jstring str){
	// 保存全局变量，其他方法需要用到
	globalStr = (*env)->NewGlobalRef(env, str);

	// NewWeakGlobalRef (java 中的软引用很像) 无法保证对象不为空
}

JNIEXPORT jstring JNICALL Java_com_darren_day15_Simple1_getGlobalRef
(JNIEnv *env, jclass jclz){
	return globalStr;
}

JNIEXPORT void JNICALL Java_com_darren_day15_Simple1_delteGlobalRef
(JNIEnv *env, jclass jclz){
	(*env)->DeleteGlobalRef(env,globalStr);
}

/*JNIEXPORT void JNICALL Java_com_darren_day15_Simple1_staticLocalCache
(JNIEnv *env, jclass jclz, jstring name){
	// name属性 赋值操作
	// static jfieldID f_id = NULL;// 局部缓存，这个方法会被多次调用，不需要反复的去获取 jfieldID  OpenCV WebRtc
	if (f_id == NULL){
		f_id = (*env)->GetStaticFieldID(env, jclz, "name", "Ljava/lang/String;");
	}else{
		printf("fieldID is not null\n");
	}
	(*env)->SetStaticObjectField(env, jclz, f_id, name);
}*/

// 全局静态缓存，在构造函数中初始化的时候会去缓存
static jfieldID f_name_id = NULL;
static jfieldID f_name1_id = NULL;
static jfieldID f_name2_id = NULL;



JNIEXPORT void JNICALL Java_com_darren_day15_Simple1_staticLocalCache
(JNIEnv *env, jclass jclz, jstring name){
	// 如果这个方法会反复的被调用，那么不会反复的去获取 jfieldID
	(*env)->SetStaticObjectField(env, jclz, f_name_id, name);
}

JNIEXPORT void JNICALL Java_com_darren_day15_Simple1_initStaticCache
(JNIEnv *env, jclass jclz){
	// 初始化全局静态缓存
	f_name_id = (*env)->GetStaticFieldID(env, jclz, "name", "Ljava/lang/String;");
	f_name1_id = (*env)->GetStaticFieldID(env, jclz, "name1", "Ljava/lang/String;");
	f_name2_id = (*env)->GetStaticFieldID(env, jclz, "name2", "Ljava/lang/String;");
}

JNIEXPORT void JNICALL Java_com_darren_day15_Simple1_exception
(JNIEnv *env, jclass jclz){
	
	// 假设现在想给 ，name 赋值 name3
	jfieldID f_id = (*env)->GetStaticFieldID(env, jclz, "name3", "Ljava/lang/String;");

	// 好几种方式
	// 1. 补救措施 ，name3 我拿 name
	// 1.1 有没有异常
	jthrowable throwable = (*env)->ExceptionOccurred(env);
	/*if (throwable){
		// 补救措施，先把异常清除
		printf("有异常");
		// 清除异常
		(*env)->ExceptionClear(env);
		// 重新获取 name 属性
		f_id = (*env)->GetStaticFieldID(env, jclz, "name", "Ljava/lang/String;");
	}*/

	// 2. 想给 java 层抛一个异常
	if (throwable){
		// 清除异常
		(*env)->ExceptionClear(env);
		// Throw 抛一个 java 的 Throwable 对象
		jclass no_such_clz = (*env)->FindClass(env,"java/lang/NoSuchFieldException");
		(*env)->ThrowNew(env, no_such_clz,"NoSuchFieldException name3");

		return;// 记得 return
	}

	jstring name = (*env)->NewStringUTF(env, "Darren");
	(*env)->SetStaticObjectField(env, jclz, f_id, name);
}
