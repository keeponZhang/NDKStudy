#include "Student.h"

// дʵ�� ,����������һ������
void Student::setAge(int age){// ʵ�� Student �� setAge ����
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