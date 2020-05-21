
// ʵ�����ǵ� native ����
#include "com_darren_ndk12_NdkSimple.h"
#include "com_darren_ndk12_NdkSimple1.h"

// JNIEXPORT JNI һ���ؼ��֣������٣�������ͨ���������Ϊ�÷������Ա��ⲿ����
// jstring : ���� java �е� String 
// JNICALL: Ҳ��һ���ؼ��֣������ٵ� jni call
// JNIEnv: ����� c �� java �໥���õ����������� function ����
// jobject: java���������Ķ��󣬾��Ǳ���Ŀ�� JniSimple java ����
// jclass: java���������� class ���󣬾��Ǳ���Ŀ�е� JniSimple.class 
JNIEXPORT jstring JNICALL Java_com_darren_ndk12_NdkSimple_getSingnaturePassword
(JNIEnv * env, jobject jobj){
	// JNIEnv * ��ʵ�Ѿ���һ������ָ���ˣ����� -> ���õ�����±�����һ��ָ�� *ȡֵ 
	return (*env)->NewStringUTF(env,"940223");
}

JNIEXPORT void JNICALL Java_com_darren_ndk12_NdkSimple1_changeName
(JNIEnv *env, jobject jobj){
	// ��ȡ name ����Ȼ���޸�Ϊ Jack

	// 3.��ȡ jclass 
	jclass j_clz = (*env)->GetObjectClass(env, jobj);
	// ��ȡ jfieldId (JNIEnv *env, jclass clazz, const char *name, const char *sig)
	// name ��ȡ�ĸ����Ե������� 
	// 2.sig ���Ե�ǩ��
	//jfieldID(JNICALL *GetFieldID)
	//	(JNIEnv *env, jclass clazz, const char *name, const char *sig);
	jfieldID j_fid = (*env)->GetFieldID(env, j_clz, "name", "Ljava/lang/String;");
	// 1.��ȡ name ���Ե�ֵ
	jstring j_str = (*env)->GetObjectField(env, jobj, j_fid);

	// ��ӡ�ַ��� jstring -> c_str
	char* c_str = (*env)->GetStringUTFChars(env,j_str,NULL);

	printf("name is %s",c_str);

	// �޸ĳ� jack
	jstring jackName = (*env)->NewStringUTF(env,"Jack");
	/*void (JNICALL *SetObjectField)
		(JNIEnv *env, jobject obj, jfieldID fieldID, jobject val);*/
	(*env)->SetObjectField(env, jobj, j_fid, jackName);

}

JNIEXPORT void JNICALL Java_com_darren_ndk12_NdkSimple1_changeAge
(JNIEnv * env, jclass jcls){
	// ���Ȼ�ȡԭ����

	jfieldID j_fid = (*env)->GetStaticFieldID(env,jcls,"age","I");
	// Static ��ȡ��̬��
	jint age = (*env)->GetStaticIntField(env, jcls, j_fid);

	// jint -> int
	age += 12;

	// �����µ� age ����
	(*env)->SetStaticIntField(env,jcls,j_fid,age);
}


JNIEXPORT void JNICALL Java_com_darren_ndk12_NdkSimple1_callAddMathod
(JNIEnv *env, jobject jobj){
	
	jclass j_clz = (*env)->GetObjectClass(env,jobj);
	// ��ȡ methodid 
	jmethodID j_mid = (*env)->GetMethodID(env, j_clz, "add", "(II)I");
	// ȥ���� java �ķ���
	jint sum = (*env)->CallIntMethod(env, jobj, j_mid,2,3);

	printf("sum = %d",sum);
}


JNIEXPORT jstring JNICALL Java_com_darren_ndk12_NdkSimple2_getkeepon
(JNIEnv * env, jclass jcls){}