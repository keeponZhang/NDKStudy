
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
//	// ֱ��ת��
//	// int number2 = number1;
//	// 1. ���ڻ�����������֮���ת�������intת����char
//	// int number2 = static_cast<int>(number1);
//	// cout << number2 << endl;
//	// 2. ������ת������һ�����ͣ��������νṹ�л����������֮��ָ������õ�ת��
//	 Student *stu = new Student("Darren",24); // jobejct -> objectArray
//	 //Person *person = stu;
//	 Person *person = static_cast<Person *>(stu);
//	 cout << person->name.c_str() << " , " << person->age << endl;
//
//	// ��������
//	//Person person = Person("Darren", 24);
//	// ת��Student
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
//	// ��������
//	Person *person = new Person("Darren", 24);
//	// ת��Student
//	// Student stu = person;
//	// Student *stu = static_cast<Student *>(person);
//
//	long mPtr = (long)person;
//	// �����ַ��࣬�������͵�ת��  long -> �����ָ��* �� �õ� reinterpret_cast
//	// �� static_cast �������� static_cast һ������ת���м̳й�ϵ������ reinterpret_cast Ҳ��ת���̳й�ϵ������
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

// �쳣�Ĵ���
//void main(){
//	// c++ �����Լ�һ���쳣����ϵ����Ҫȥǿ��
//	// ���� c++ �������κ��������� try{}catch(�������� ������){}
//	// throw ���쳣
//
//	 try{
//		int i = -1;
//
//		if (i == 0){
//			throw Exception("���쳣��");
//		}
//
//		if (i< 0){
//			throw 12.5f;
//		}
//	 }
//	catch (int number){
//		cout << "��׽���쳣" <<number << endl;
//	}
//	catch (Exception exception){
//		cout << "��׽���쳣:" << exception.what() << endl;
//	}
//	catch (...){
//		cout << "��׽�������쳣:" << endl;
//	}
//
//	getchar();
//}


void main(){
	// C++ STL(Standard Template Library) ׼ģ��� ������ + ������ + �㷨
	// 1. ����Ĺ���
	string str1 = "123";
	string str2("123");
	string str3(5, 'A');// 5 �� A = AAAAA
	string *str4 = new string("123");

	// cout << str1.c_str() <<endl;
	// cout << str2.c_str() << endl;
	// cout << str3.c_str() << endl;
	// cout << str4->c_str() << endl;

	// string �� char* �໥֮��ת�� c_str()
	// const char* c_str1 = str1.c_str();
	// cout << c_str1 << endl;

	// char* -> string
	char* c_str = "Darren";
	string str(c_str);// ����
	cout << str.c_str() << endl;

	getchar();
}


/*
��ҵ��һ��
3.3 string ����

3.3 ��ӣ�ɾ�����滻�����ң���Сдת��  �ο� c ����Щ����
*/

// ��ƵԴ�� grace 2746186102
