#include <stdlib.h>
#include <stdio.h>
// ����һ���ṹ��ָ��ı���
typedef const struct JNINativeInterface *JNIEnv;
// ģ��һ���ṹ��
struct JNINativeInterface{
	// �ṹ��ķ���ָ��
	char*(*NewStringUTF)(JNIEnv*,char*);
};

char* NewStringUTF(JNIEnv* env, char* c_str){
	// c_str -> jstring
	return c_str;
}

char* Java_com_darren_getSingnaturePassword(JNIEnv * env){
	// JNIEnv * ��ʵ�Ѿ���һ������ָ���ˣ����� -> ���õ�����±�����һ��ָ�� *ȡֵ 
	return (*env)->NewStringUTF(env, "940223");
}

void main(){

	// ���� JNIEnv* ����
	struct JNINativeInterface nativeInterface;
	// ���ṹ����ָ����и���(ʵ��)
	nativeInterface.NewStringUTF = NewStringUTF;

	// ���� Java_com_darren_ndk12_NdkSimple_getSingnaturePassword �Ĳ����� JNIEnv*
	JNIEnv env = &nativeInterface;// һ��ָ��
	JNIEnv* jniEnv = &env;// ����ָ��

	// �� jniEnv ���󴫸� Java_com_darren_ndk12_NdkSimple_getSingnaturePassword
	char* jstring = Java_com_darren_getSingnaturePassword(jniEnv);

	// jstring ͨ�� JNIEnv ���� java ��
	printf("jstring = %s",jstring);

	getchar();
}
