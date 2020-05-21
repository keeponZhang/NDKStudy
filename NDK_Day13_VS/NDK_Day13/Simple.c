#include "com_darren_ndk_day13_Simple1.h"

JNIEXPORT void JNICALL Java_com_darren_ndk_day13_Simple1_callStaticMethod
(JNIEnv *env, jclass jclz){

	// 2.��ȡ methodId
	jmethodID j_mid = (*env)->GetStaticMethodID(env,jclz,"getUUID","()Ljava/lang/String;");
	// 1. ���� getUUID �ķ��� static 
	jstring j_uuid = (*env)->CallStaticObjectMethod(env, jclz,j_mid);

	// jstring -> c_str
	char* c_uuid = (*env)->GetStringUTFChars(env,j_uuid,NULL);
	
	// ���գ��ַ������� 
	(*env)->ReleaseStringUTFChars(env,j_uuid,c_uuid);

	printf("c_uuid = %s",c_uuid);
}

JNIEXPORT jobject JNICALL Java_com_darren_ndk_day13_Simple1_createPoint
(JNIEnv *env, jclass jclz){
	// jclz -> Simple1

	// ��ȡ Point �� class ,name = "ȫ����"
	jclass point_clz = (*env)->FindClass(env,"com/darren/ndk/day13/Point");
	// ���� java ��� Point ���󣬹��캯����id , ���췽�����ٶȣ� <init>
	jmethodID j_mid = (*env)->GetMethodID(env,point_clz,"<init>","(II)V");

	jobject point = (*env)->NewObject(env, point_clz, j_mid,11,22);

	// ��ϰһ�� y ���¸���ֵ ������ set ����
	j_mid = (*env)->GetMethodID(env, point_clz,"setY","(I)V");
	/* va_list ����
	void (JNICALL *CallVoidMethodV)
		(JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
	// jvalue
	void (JNICALL *CallVoidMethodA)
		(JNIEnv *env, jobject obj, jmethodID methodID, const jvalue * args);
	*/

	(*env)->CallVoidMethod(env, point,j_mid,33);

	// ��ҵ��ֱ�Ӹ����Ը�ֵ

	return point;
}

void main(){
	// ����������ȥ�޸�
	const int number = 100;
	// number = 200;

	int number1 = 100;
	int number2 = 200;

	// ����ָ��
	// int const * n_p = &number2;
	// n_p = &number1;
	// printf("n_p = %p",n_p); // ��ַ�ǿ������±���ֵ��
	// *n_p = 300; ֵ�ǲ��ܸĵ�

	// ָ�볣��
	int * const n_p = &number2;
	// n_p = &number1; ��ַ�ǲ��ܱ����¸�ֵ
	*n_p = 300;
	printf("number2 = %d", number2);
	getchar();
}