
#include <iostream>

using namespace std;

class Person
{
public:
	string name;
	int age;

public:
	Person(string name, int age){
		this->name = name;
		this->age = age;
	}
};

class Student : public Person{
public:
	Student(string name, int age) : Person(name,age){
		
	}
};

class Worker : public Person
{

};

//void main(){
//	double number1 = 20.02;
//	// 直接转换
//	// int number2 = number1;
//	// 1. 用于基本数据类型之间的转换，如把int转换成char
//	// int number2 = static_cast<int>(number1);
//	// cout << number2 << endl;
//	// 2. 把类型转换成另一种类型，用于类层次结构中基类和派生类之间指针或引用的转换
//	 Student *stu = new Student("Darren",24); // jobejct -> objectArray
//	 //Person *person = stu;
//	 Person *person = static_cast<Person *>(stu);
//	 cout << person->name.c_str() << " , " << person->age << endl;
//
//	// 待会再试
//	//Person person = Person("Darren", 24);
//	// 转成Student
//	// Student stu = person;
//
//	//cout << person.name.c_str() << " , " << person.age << endl;
//
//	getchar();
//}


//void main(){
//
//	const Person *person = new Person("Darren", 24);
//
//	cout << person->name.c_str() << " , " << person->age << endl;
//
//	// person->age = 24;
//	// const_cast
//	Person * person1 = const_cast<Person *>(person);
//	person1->age = 25;
//	person1->name = "Jack";
//
//	cout << person->name.c_str() << " , " << person->age << endl;
//
//	getchar();
//}



// reinterpret_cast 
//void main(){
//	// 待会再试
//	Person *person = new Person("Darren", 24);
//	// 转成Student
//	// Student stu = person;
//	// Student *stu = static_cast<Student *>(person);
//
//	long mPtr = (long)person;
//	// 除了字符类，各种类型的转换  long -> 对象的指针* ， 用到 reinterpret_cast
//	// 与 static_cast 区别在于 static_cast 一般用于转换有继承关系的类型 reinterpret_cast 也能转换继承关系的类型
//	Student *stu = reinterpret_cast<Student *>(mPtr);
//	//Student *stu = static_cast<Student *>(mPtr);
//	cout << stu->name.c_str() << " , " << stu->age << endl;
//
//	getchar();
//}



// dynamic_cast
//void main(){
//	Student *stu = new Student("", 24);
//
//	Person *worker = dynamic_cast<Person *>(stu);
//
//	getchar();
//}



class Exception
{
public:
	string msg;

public:
	Exception(string msg){
		this->msg = msg;
	}

public:
	const char *what(){
		return this->msg.c_str();
	}

};

// 异常的处理
//void main(){
//	// c++ 中有自己一套异常的体系，不要去强记
//	// 但是 c++ 可以抛任何数据类型 try{}catch(数据类型 变量名){}
//	// throw 抛异常
//
//	 try{
//		int i = -1;
//
//		if (i == 0){
//			throw Exception("出异常了");
//		}
//
//		if (i< 0){
//			throw 12.5f;
//		}
//	 }
//	catch (int number){
//		cout << "捕捉到异常" <<number << endl;
//	}
//	catch (Exception exception){
//		cout << "捕捉到异常:" << exception.what() << endl;
//	}
//	catch (...){
//		cout << "捕捉到其他异常:" << endl;
//	}
//
//	getchar();
//}


void main(){
	// C++ STL(Standard Template Library) 准模板库 ：容器 + 迭代器 + 算法
	// 1. 对象的构建
	string str1 = "123";
	string str2("123");
	string str3(5, 'A');// 5 个 A = AAAAA
	string *str4 = new string("123");

	// cout << str1.c_str() <<endl;
	// cout << str2.c_str() << endl;
	// cout << str3.c_str() << endl;
	// cout << str4->c_str() << endl;

	// string 与 char* 相互之间转换 c_str()
	// const char* c_str1 = str1.c_str();
	// cout << c_str1 << endl;

	// char* -> string
	char* c_str = "Darren";
	string str(c_str);// 对象
	cout << str.c_str() << endl;

	getchar();
}


/*
作业过一遍
3.3 string 遍历

3.3 添加，删除，替换，查找，大小写转换  参考 c 的那些试题
*/

// 视频源码 grace 2746186102
