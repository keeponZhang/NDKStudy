#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream> // c++�İ�
#include "Student.h"

using namespace std; // �����Ŀռ䣬java�е��ಿ��


// 1. c++ �����п��Ի�� c ���룬c++ ����д c ���룬Ҳ���Ե���
// 2. c++ �������Java����c �������
// 3. �ܶ�Ŀ�Դ��ܴ󲿷ֶ��� c++ д�� ���󲿷ֻ��� c++ ��
//void main(){
//
//// printf("Hello World");// c �Ĵ�ӡ
//
//// c++ ��ӡ  opencv   << ����������
//std::cout << "Hello World!" << std::endl;
//
//getchar();
//}


//void main(){
//	const int number = 10;
//
//	// number = 20;
//
//	 int* numberP = &number;// ����ͨ����ַȥ�޸�ֵ������ĳЩ������������ͨ��������Ҳ�����޸�ֵ
//	// c ���ܹ��޸ĵģ��� c �п���˵��һ��α����
//
//	// *numberP = 20;
//
//	// printf("%d", number);
//
//	getchar();
//}


// 3.����
void swap(int* number1,int* number2){
	int temp = 0;
	temp = *number1;
	*number1 = *number2;
	*number2 = temp;
}


void swap(int &number1, int &number2){// ����
	cout << "swap number1�ĵ�ַ" << &number1 << endl;

	int temp = 0;
	temp = number1;
	number1 = number2;
	number2 = temp;
}

//void main(){
//	int a = 10;
//
//	// int b = a; // �����ַ��һ��
//	int &b = a; // ��aָ����ڴ�ȡ����һ������ b
//
//	b = 20;
//
//	cout << "a�ĵ�ַ" << &a << endl;
//	cout<< "b�ĵ�ַ" << &b << endl;
//	cout << "a��ֵ" << a << endl;
//	cout << "a��ֵ" << b << endl;
//
//	// ����ֵ
//	int number1 = 10;
//	int number2 = 20;
//
//	// ���ã� ����ģ��ֵ�Ŀ�����������ʵ�ǵ�ַ��ֵ �����Կ���ͬһ���ڴ������һ������
//	cout << "main number1�ĵ�ַ" << &number1 << endl;
//
//	swap(number1,number2);
//
//	cout << "number1 = " << number1 << " , number2 = " << number2 << endl;
//
//	getchar();
//}


// ��������
typedef struct 
{
	char name[20];
	int age;
}Student;

void insertStu(const Student &stu){// stu ����� ��������
	// �����޸� stu ��ֵ
	// strcpy(stu.name,"Jack");

	// �ͱ����ֻ��
	cout << stu.name << "," << stu.age << endl;
}

//void main(){
//	Student stu = {"Darren",20};
//
//	insertStu(stu);
//
//	getchar();
//}


// 1.�������غ�Ĭ�ϲ���
int add(int number1, int number2 = 200, bool cache= 0){ // number2 = 200 Ĭ�ϵĲ��� kotlin ����
	return number1 + number2;
}

// ����	1	error C2084: ������int add(int,int)����������  c ��������������
int add(int number1, int number2, int number3){
	return number1 + number2 + number3;
}

//void main(){
//
//	int number1 = 100;
//	int number2 = 200;
//	int sum = add(number1,200);
//
//	// bool ����
//	bool cache = -100;// 0 �� !0 
//
//	if (cache){
//		cout << "true" << endl;
//	}else
//	{
//		cout << "false" << endl;
//	}
//	// printf("sum = %d", sum);
//
//	getchar();
//}

// 0 1 2  , 0 ��ӡ�� 1 �ϴ�����̨�� 2 ���˺ͷ�����
void printLog(char* content,int){// �Լ�ƽ̨��ӡ����Ʒ˵���¸��汾����Ҫ�ϴ���������������ҲҪ��һ��
	cout << content << endl;
	// ������ �п���
}


//void main(){
//	// new ��new ��������һ��ָ��
//	Student *stu = new Student();
//
//	printLog("xxxx",0);// 100 
//
//	printLog("xxxx", 1);// 100 
//
//	printLog("xxxx", 2);// 100 
//
//	stu -> setName("Darren");
//	stu -> age = 24;
//
//	cout << stu -> getName() << " , " << stu -> getAge() << endl;
//
//	getchar();
//}

// ���䣺���������У���Ҫ��ֱ��д���������� Student.cpp ��һ�������� Student.cpp 
// ������һ�� so �⣬����Ҫ��һ��ͷ�ļ�


