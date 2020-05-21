#include <iostream>
#include <stdarg.h>
using namespace std;
#include "Student.h"

// 1. ���Ա����

//void sum(int count,...){// int ... �� c++ ...
//	va_list vp;
//	// �ɱ������ʼ������count ��������￪ʼ
//	va_start(vp, count);
//
//	int number = va_arg(vp,int);
//	cout << number << endl;
//
//	// ��ȡ��һ��
//	number = va_arg(vp, int);
//	cout << number << endl;
//
//	// ��ȡ��һ�� ��������Ĭ���� 0
//	number = va_arg(vp, int);
//	cout << number << endl;
//}


int sum(int count, ...){// int ... �� c++ ...
	va_list vp;
	// �ɱ������ʼ������count ��������￪ʼ
	va_start(vp, count);

	int sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += va_arg(vp, int);
	}

	// ��β���ͷ��ڴ�
	va_end(vp);

	return sum;
}

//void main(){
//
//	int number = sum(5,1,2,4);
//
//	cout << number << endl;
//	
//	getchar();
//}


//class Student
//{
//public:
//	char* name;
//
//	int age;
//	// ��̬
//	static int tag;// ����
//
//	Student(){
//		tag = 12;
//	}
//
//public:
//	static void change(){
//		tag += 12;
//	}
//
//	void change1(){
//		this -> change();
//	}
//};

// ��̬������ c++ �б���Ҫ��ʼ������ʼ��������ôд
//int Student::tag = 12;

// ��̬ ����ֱ��������ȥ���� :: 
//      ��̬�����Ա���Ҫ��ʼ�� ��ʵ�֣�
//      ��̬�ķ���ֻ��ȥ������̬�����Ի��߷���

//void main(){
//	Student stu;
//
//	// stu.tag = 12;
//	// c++ ������̬�﷨ ::
//	// Student::tag += 12;
//	// Student::change();
//	stu.change1();
//
//	cout << Student::tag << endl;
//
//	getchar();
//}


// 3. ����Ĵ�С
class A
{
public:
	double b;
	int a;
	char c;
};

class B
{
public:
	double b;
	int a;
	char c;
	static double d;
};

class C
{
public:
	double b;
	int a;
	char c;
	C(int a){
		this->a = a;
	}
public:
	int getA(){
		return this->a;
	}
};

// 1. ����Ĵ�С��ṹ��ļ��㷽ʽ����
// 2. static ��̬�����ͷ�����û���㵽��Ĵ�С��
// 3. ջ���ѣ�ȫ�֣���̬���������ַ������������� ����Ĵ�Сֻ����ͨ�����й�ϵ
//void main(){
//	
//	cout << "A �Ĵ�С��" << sizeof(A) << endl;
//	cout << "B �Ĵ�С��" << sizeof(B) << endl;
//	cout << "C �Ĵ�С��" << sizeof(C) << endl;
//
//	C c1(12);
//	C c2(24);
//	cout << c1.getA() << endl;
//	cout << c2.getA() << endl;
//
//	getchar();
//}


// this ָ�룺����ǰ�Ķ�����Ϊ��ķ�������ڴ����������һ����ģ�����Ҫ�� this ������
//class Student
//{
//public:
//	char* name;
//
//	int age;
//
//public:
//	// this = const Student *const this
//	// ��һ�� const ������ָ�룬����ֵ�����޸�
//	// �ڶ��� const ��ָ�볣��������ָ��ĵ�ַ�����޸�
//	void change() const{// const ��() ֮����Ҫ�������� this �ؼ���
//		// this -> age += 12; // ���ܶ�������Խ����޸�
//		// this = (Student*)0x0012;
//	}
//
//	// this = Student *const this
//	void change1(){
//		// this = (Student*)0x0012;
//	}
//};

// 5. const ���κ���
//void main(){
//	Student stu;
//	stu.change();
//
//	cout << stu.age << endl;
//
//	getchar();
//}


// 6. ��Ԫ����
class Person
{
 private:
	 int age = 0;

public:
	// ������Լ�д���캯������ô��Ĭ�ϸ����޲εĹ��캯��
	Person(int age){
		this->age = age;
	}

	int getAge(){
		return this->age;
	}

	// ��Ԫ����������
	friend void friend_change(Person *person, int age);
};

// ��Ԫ������ʵ��
void friend_change(Person *person, int age){
	// �޸�һ�� age ��ֵ
	// ������ڲ����ܷ���˽������
	// ����÷�����������Ԫ������ô�ǿ������ⲿ������˽�����Ե�
	person->age = age;
}

//void main(){
//	
//	Person person = Person(24);
//
//	friend_change(&person,36);
//
//	cout << person.getAge() << endl;
//
//
//	getchar();
//}

// ��Ԫ��������ͨ����������
void main(){
	Student *stu = new Student("Darren",24);

	// Student::changeTag(36);

	changeAge(stu,36);
	stu->print();

	delete(stu);
	getchar();
}


// ��Ԫ��
class  ImageView
{
public: // B �� A ����Ԫ��
	friend class Class;
private:
	int a;
};

class Class
{
public:
	ImageView aObj;

	void changeA(int number){
		aObj.a = number;
	}

	int getA(){
		return aObj.a;
	}
};

//void main(){
//	Class b;
//	b.changeA(12);
//
//	cout << b.getA() << endl;
//
//	getchar();
//}