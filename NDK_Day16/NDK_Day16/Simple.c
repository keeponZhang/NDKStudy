#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 写一个打印数组的方法
//void print(int* arr,int length){
//	// 获取数组的大小
//	for (int i = 0; i < length; i++)
//	{
//		printf("%d  ",arr[i]);
//	}
//}
void print(int arr[]){
	// 获取数组的大小
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

typedef struct MyStruct Student;// 给 MyStruct 取一个别名叫做 Student

// int32_t ，可以对基本数据类型取别名
typedef int int32;


//void main(){
//	int a;// 告诉c和c++编译器开辟一块连续大小的 4 字节的内存空间
//	int arr[] = {1,2,3,4,5,6};
//
//	// 求数组的大小？
//	int size = sizeof(arr) / sizeof(int);
//
//	printf("size = %d\n",size);
//
//	print(arr);
//
//	getchar();
//}

//void main(){
//	int a;// 告诉c和c++编译器开辟一块连续大小的 4 字节的内存空间
//	int arr[] = { 1, 2, 3, 4, 5, 6 };// arr 数据类型的内存大小空间 24
//
//	a = 10;
//
//	// 12 , 16 , 12 , 36   36？
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
//	// 获取 Bitmap ，锁定画布 void**
//	// void number;// 错误 
//
//	// memcpy();// 拷贝内存，什么用 void* 
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
	char* buff = malloc(128); // char* buff char* 是四字节的数据类型，存的是堆区开辟的 128 个字节的首地址
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
	 /*0508 , 0496  a 的地址要大于 b 的地址 （debug）
	 016  , 020   a 的地址要小于 b 的地址 （release）
	 buffer 数据类型跟栈的开口方向无关（都是向上）*/

	char buff[10];
	//buff + 1 > buff;
	printf("%p , %p, %p, %p",&a,&b,buff,buff+1);

	int a = 100;
	int* ff = &a;// 虽说是 a 的地址，但是我也可以把 ff 看做一个数组

	 //char** 二维数组 char** 二级指针

	ff += 1;

	getchar();
}
// 理解指针的关键还是在于内存 ，指针的大小是 4 字节 int* double* 指针存放的是一块内存的地址 4 字节 ，但是也会有数据类型
