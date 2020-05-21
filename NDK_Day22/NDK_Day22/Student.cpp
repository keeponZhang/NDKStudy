#include "Student.h"
#include <iostream>

// 一个一个来实现
int Student::tag = 0;

// 构造函数
Student::Student(char* name) :Student(name,0){// :age(0) 赋默认值
	this->name = name;
}

Student::Student(char* name,int age){
	this->name = name;
	this->age = age;
}

// 析构和拷贝构造函数
// 析构函数
Student::~Student(){
	
}
// 拷贝构造函数
Student::Student(const Student& stu){
	
}

// 普通方法
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

// 静态和友元
void Student::changeTag(int tag_replace){
	tag = tag_replace;
}

// 实现友元方法
void changeAge(Student *stu, int age){
	stu->age = age;
}

