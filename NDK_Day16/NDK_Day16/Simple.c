#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// дһ����ӡ����ķ���
//void print(int* arr,int length){
//	// ��ȡ����Ĵ�С
//	for (int i = 0; i < length; i++)
//	{
//		printf("%d  ",arr[i]);
//	}
//}
void print(int arr[]){
	// ��ȡ����Ĵ�С
	int length = sizeof(arr) / sizeof(int);
	printf("length = %d\n", length);
	for (int i = 0; i < length; i++)
	{
		printf("%d  ", arr[i]);
	}
}

struct MyStruct
{
	char* name;
};

typedef struct MyStruct Student;// �� MyStruct ȡһ���������� Student

// int32_t �����ԶԻ�����������ȡ����
typedef int int32;


//void main(){
//	int a;// ����c��c++����������һ��������С�� 4 �ֽڵ��ڴ�ռ�
//	int arr[] = {1,2,3,4,5,6};
//
//	// ������Ĵ�С��
//	int size = sizeof(arr) / sizeof(int);
//
//	printf("size = %d\n",size);
//
//	print(arr);
//
//	getchar();
//}

//void main(){
//	int a;// ����c��c++����������һ��������С�� 4 �ֽڵ��ڴ�ռ�
//	int arr[] = { 1, 2, 3, 4, 5, 6 };// arr �������͵��ڴ��С�ռ� 24
//
//	a = 10;
//
//	// 12 , 16 , 12 , 36   36��
//	printf("%p, %p, %p ,%p", arr, arr+1, &arr, &arr+1);
//
//
//	getchar();
//}

//void main(){
//	Student stu = { "Darren" };
//
//	int32 number1 = 100;
//
//	printf("number1 = %d",number1);
//
//	// ��ȡ Bitmap ���������� void**
//	// void number;// ���� 
//
//	// memcpy();// �����ڴ棬ʲô�� void* 
//
//	getchar();
//}


char* getStr1(){
	char* str = "12345";
	return str;
}

char* getStr2(){
	char* str = "12345";
	return str;
}

char* getStr3(){
	char buff[128];

	strcpy(buff,"12345");

	return buff;
}

char* getStr4(){
	char* buff = malloc(128); // char* buff char* �����ֽڵ��������ͣ�����Ƕ������ٵ� 128 ���ֽڵ��׵�ַ
	strcpy(buff, "12345");

	return buff;
}

//void main(){
//
//	char* str1 = NULL;
//
//	char* str2 = NULL;
//
//	str1 = getStr1();
//
//	str2 = getStr2();
//
//	char* str3 = getStr3();
//
//	char* str4 = getStr4();
//
//	printf("%d , %d, %s, %s",str1,str2,str3,str4);// str3 = 12345
//
//	getchar();
//}



void main(){  
	int a = 10;

	int b = 10;
	 /*0508 , 0496  a �ĵ�ַҪ���� b �ĵ�ַ ��debug��
	 016  , 020   a �ĵ�ַҪС�� b �ĵ�ַ ��release��
	 buffer �������͸�ջ�Ŀ��ڷ����޹أ��������ϣ�*/

	char buff[10];
	//buff + 1 > buff;
	printf("%p , %p, %p, %p",&a,&b,buff,buff+1);

	int a = 100;
	int* ff = &a;// ��˵�� a �ĵ�ַ��������Ҳ���԰� ff ����һ������

	 //char** ��ά���� char** ����ָ��

	ff += 1;

	getchar();
}
// ���ָ��Ĺؼ����������ڴ� ��ָ��Ĵ�С�� 4 �ֽ� int* double* ָ���ŵ���һ���ڴ�ĵ�ַ 4 �ֽ� ������Ҳ������������
