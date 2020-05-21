#include "com_darren_ndk_day13_Simple1.h"

JNIEXPORT void JNICALL Java_com_darren_ndk_day13_Simple1_callStaticMethod
(JNIEnv *env, jclass jclz){

	// 2.获取 methodId
	jmethodID j_mid = (*env)->GetStaticMethodID(env,jclz,"getUUID","()Ljava/lang/String;");
	// 1. 调用 getUUID 的方法 static 
	jstring j_uuid = (*env)->CallStaticObjectMethod(env, jclz,j_mid);

	// jstring -> c_str
	char* c_uuid = (*env)->GetStringUTFChars(env,j_uuid,NULL);
	
	// 回收，字符串回收 
	(*env)->ReleaseStringUTFChars(env,j_uuid,c_uuid);

	printf("c_uuid = %s",c_uuid);
}

JNIEXPORT jobject JNICALL Java_com_darren_ndk_day13_Simple1_createPoint
(JNIEnv *env, jclass jclz){
	// jclz -> Simple1

	// 获取 Point 的 class ,name = "全类名"
	jclass point_clz = (*env)->FindClass(env,"com/darren/ndk/day13/Point");
	// 构建 java 层的 Point 对象，构造函数的id , 构造方法（百度） <init>
	jmethodID j_mid = (*env)->GetMethodID(env,point_clz,"<init>","(II)V");

	jobject point = (*env)->NewObject(env, point_clz, j_mid,11,22);

	// 练习一下 y 重新付个值 ？调用 set 方法
	j_mid = (*env)->GetMethodID(env, point_clz,"setY","(I)V");
	/* va_list 集合
	void (JNICALL *CallVoidMethodV)
		(JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
	// jvalue
	void (JNICALL *CallVoidMethodA)
		(JNIEnv *env, jobject obj, jmethodID methodID, const jvalue * args);
	*/

	(*env)->CallVoidMethod(env, point,j_mid,33);

	// 作业：直接给属性赋值

	return point;
}

void main(){
	// 常量，不能去修改
	const int number = 100;
	// number = 200;

	int number1 = 100;
	int number2 = 200;

	// 常量指针
	// int const * n_p = &number2;
	// n_p = &number1;
	// printf("n_p = %p",n_p); // 地址是可以重新被赋值的
	// *n_p = 300; 值是不能改的

	// 指针常量
	int * const n_p = &number2;
	// n_p = &number1; 地址是不能被重新赋值
	*n_p = 300;
	printf("number2 = %d", number2);
	getchar();
}