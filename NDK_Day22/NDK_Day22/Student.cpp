#include "Student.h"
#include <iostream>

// һ��һ����ʵ��
int Student::tag = 0;

// ���캯��
Student::Student(char* name) :Student(name,0){// :age(0) ��Ĭ��ֵ
	this->name = name;
}

Student::Student(char* name,int age){
	this->name = name;
	this->age = age;
}

// �����Ϳ������캯��
// ��������
Student::~Student(){
	
}
// �������캯��
Student::Student(const Student& stu){
	
}

// ��ͨ����
void Student::setAge(int age){
	this->age = age;
}

void Student::setName(char* name){
	this->name = name;
}

int Student::getAge(){
	return this->age;
}

char* Student::getName(){
	return this->name;
}

void Student::print() const{
	std::cout << this->name << " , " << this->age << std::endl;
}

// ��̬����Ԫ
void Student::changeTag(int tag_replace){
	tag = tag_replace;
}

// ʵ����Ԫ����
void changeAge(Student *stu, int age){
	stu->age = age;
}

