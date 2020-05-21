#include "com_darren_day15_Simple1.h"
#include <stdlib.h>

int compare(const jint *number1, const jint *number2){
	return *number1 - *number2;
}

// ȫ�ֱ���
jstring globalStr;

JNIEXPORT void JNICALL Java_com_darren_day15_Simple1_sort
(JNIEnv * env, jclass jclz, jintArray jarray){

	// �� jarray �������� ��sort��
	jint* intArray = (*env)->GetIntArrayElements(env,jarray,NULL);

	int length = (*env)->GetArrayLength(env,jarray);

	// ��һ��������void* ������׵�ַ
	// �ڶ�������������Ĵ�С����
	// ����������������Ԫ���������͵Ĵ�С
	// ���ĸ������������һ���ȽϷ���ָ�루Comparable��
	qsort(intArray, length, sizeof(int), compare);

	// ͬ����������ݸ� java ���� intArray ������ jarray �����Լ򵥵����Ϊ copy
	// 0 : ��Ҫͬ�����ݸ� jarray ,��Ҫ�ͷ� intArray
	// JNI_COMMIT:  ��ͬ�����ݸ� jarray �����ǲ����ͷ� intArray
	// JNI_ABORT: ��ͬ�����ݸ� jarray �����ǻ��ͷ� intArray
	(*env)->ReleaseIntArrayElements(env,jarray,intArray,JNI_ABORT);
}

JNIEXPORT void JNICALL Java_com_darren_day15_Simple1_localRef
(JNIEnv *env, jclass jclz){
	// �� native �㹹���� Java �����㲻���˸���ô����
	// native �㿪�ٵ��ڴ���˭�������ܿ��ٶ��

	// �ַ�����ȡ��String ����
	jclass str_clz = (*env)->FindClass(env,"java/lang/String");
	jmethodID init_mid = (*env)->GetMethodID(env,str_clz,"<init>","()V");
	jobject j_str = (*env)->NewObject(env, str_clz, init_mid);

	// ���� 100 �д���

	// jobject ��Ҫ��ʹ���ˣ�Ҫ���� javaGC ��Դ��
	(*env)->DeleteLocalRef(env,j_str);

	// ɾ���˾Ͳ�����ʹ���ˣ�C �� C++ ����Ҫ�Լ��ͷ��ڴ棨��̬���ٵĲ���Ҫ����̬���ٵ���Ҫ��

}

JNIEXPORT void JNICALL Java_com_darren_day15_Simple1_saveGlobalRef
(JNIEnv *env, jclass jclz, jstring str){
	// ����ȫ�ֱ���������������Ҫ�õ�
	globalStr = (*env)->NewGlobalRef(env, str);

	// NewWeakGlobalRef (java �е������ú���) �޷���֤����Ϊ��
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
	// name���� ��ֵ����
	// static jfieldID f_id = NULL;// �ֲ����棬��������ᱻ��ε��ã�����Ҫ������ȥ��ȡ jfieldID  OpenCV WebRtc
	if (f_id == NULL){
		f_id = (*env)->GetStaticFieldID(env, jclz, "name", "Ljava/lang/String;");
	}else{
		printf("fieldID is not null\n");
	}
	(*env)->SetStaticObjectField(env, jclz, f_id, name);
}*/

// ȫ�־�̬���棬�ڹ��캯���г�ʼ����ʱ���ȥ����
static jfieldID f_name_id = NULL;
static jfieldID f_name1_id = NULL;
static jfieldID f_name2_id = NULL;



JNIEXPORT void JNICALL Java_com_darren_day15_Simple1_staticLocalCache
(JNIEnv *env, jclass jclz, jstring name){
	// �����������ᷴ���ı����ã���ô���ᷴ����ȥ��ȡ jfieldID
	(*env)->SetStaticObjectField(env, jclz, f_name_id, name);
}

JNIEXPORT void JNICALL Java_com_darren_day15_Simple1_initStaticCache
(JNIEnv *env, jclass jclz){
	// ��ʼ��ȫ�־�̬����
	f_name_id = (*env)->GetStaticFieldID(env, jclz, "name", "Ljava/lang/String;");
	f_name1_id = (*env)->GetStaticFieldID(env, jclz, "name1", "Ljava/lang/String;");
	f_name2_id = (*env)->GetStaticFieldID(env, jclz, "name2", "Ljava/lang/String;");
}

JNIEXPORT void JNICALL Java_com_darren_day15_Simple1_exception
(JNIEnv *env, jclass jclz){
	
	// ����������� ��name ��ֵ name3
	jfieldID f_id = (*env)->GetStaticFieldID(env, jclz, "name3", "Ljava/lang/String;");

	// �ü��ַ�ʽ
	// 1. ���ȴ�ʩ ��name3 ���� name
	// 1.1 ��û���쳣
	jthrowable throwable = (*env)->ExceptionOccurred(env);
	/*if (throwable){
		// ���ȴ�ʩ���Ȱ��쳣���
		printf("���쳣");
		// ����쳣
		(*env)->ExceptionClear(env);
		// ���»�ȡ name ����
		f_id = (*env)->GetStaticFieldID(env, jclz, "name", "Ljava/lang/String;");
	}*/

	// 2. ��� java ����һ���쳣
	if (throwable){
		// ����쳣
		(*env)->ExceptionClear(env);
		// Throw ��һ�� java �� Throwable ����
		jclass no_such_clz = (*env)->FindClass(env,"java/lang/NoSuchFieldException");
		(*env)->ThrowNew(env, no_such_clz,"NoSuchFieldException name3");

		return;// �ǵ� return
	}

	jstring name = (*env)->NewStringUTF(env, "Darren");
	(*env)->SetStaticObjectField(env, jclz, f_id, name);
}
