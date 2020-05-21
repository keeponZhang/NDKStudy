#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// 1.构造函数 
class Student
{
public:
	// 构造函数
	Student(){// 空参数构造函数
		cout << "空参数构造函数"<< endl;
	}

	// Student(char* name):age(0){// 一个参数构造函数, 相当于 this->age = 0
	//	cout << "一个参数构造函数" << endl;
	//	this->name = name;
		// this->age = 0;
	// }

	Student(char* name) :Student(name,0){// 调用两个参数的构造函数，注意：先会调用两个参数的构造函数，然后才会执行当前构造函数
		cout << "一个参数构造函数" << endl;
	}

	Student(char* name, int age){// 两个参数构造函数
		cout << "两个参数构造函数" << endl;
		this->name = (char*)malloc(sizeof(char)*100);
		strcpy(this->name,name);
		
		 //this->name = name;
		this->age = age;
	}

	// 2. 析构函数,如果有在对象内部开辟堆内存，可以在析构函数中释放内存
	~Student(){
		
		// 临终遗言，对象被回收的时候会被调用
		// 释放内存
		/*if (this->name != NULL){
			cout << "释放指针" << endl;
			free(this->name);
		   this->name = NULL;
		  
		}*/
		
		/*printf("%s\n", this->name);
		free(this->name);
		this->name = NULL;*/
		cout << "析构函数" << this->name << endl;
	}

	// 4.拷贝构造函数，对象会有一个默认的拷贝构造函数，用来对象之间的赋值
	Student(const Student& stu){// 常量的引用
		cout << "拷贝构造函数" << endl;
		 this->name = stu.name;// 浅拷贝
		// 如果动态开辟内存，一定要采用深拷贝
		/*this->name = (char*)malloc(sizeof(char)* 100);
		strcpy(this->name, stu.name);
	*/

		this->age = stu.age;
	}

private:
	int age;
	char* name;


public:
	int getAge(){
		return this->age;
	}

	char* getName(){
		return this->name;
	}

	void setAge(int age){
		this->age = age;
	}

	void setName(char* name){
		this->name = name;
	}
};


//void main(){
//	
//	// Student stu;// 1. 默认调用空参的构造函数
//	// stu.setAge(24);
//	// stu.setName("Darren");
//
//	// Student stu("Darren",24); // 2. 调用两个参数的构造函数
//
//	// 3. 用 new 关键字,返回的是一个 Student 的一级指针
//	// Student *stu = new Student("Darren",24);
//
//	// 4. 用 malloc 的方式，并没有调用空参的构造函数
//	// Student *stu = (Student*)malloc(sizeof(Student));
//	// stu->setAge(24);
//	// stu->setName("Darren");
//
//	// 构造函数相互调用
//	Student *stu = new Student("Darren");
//
//	cout << stu -> getName() << " , " << stu->getAge() << endl;
//
//	getchar();
//}


//void main(){
//
//	Student *stu = new Student("Darren");
//
//	cout << stu->getName() << " , " << stu->getAge() << endl;
//
//	free(stu);
//
//	// java 对象的被回收会调用什么方法？ android java 内存回收的时候（系统架构） 腾讯面试（笔试）
//
//	getchar();
//}

// 3. malloc、free、new、delete 区别
//void main(){
//	// Student stu;// 栈中开辟内存
//
//	// malloc、free、 new、delete 都是开辟和释放内存
//	// 1. malloc/free 他们是一套， new/delete 它们也是配套
//	// 2. malloc/free 不会去调用构造函数和析构函数
//	// Student *stu = (Student*)malloc(sizeof(Student));
//	// free(stu);
//	// 3. new/delete 会调用构造函数和析构函数
//	// Student *stu = new Student();
//	// delete(stu);
//	// 4. 如果用了 new ，那么一定要记得 delete（释放内存）
//
//	getchar();
//}


struct Person
{
	int age;
	char* name;
};

//void main(){
//	Person person1 = {24,"Darren"};
//
//	Person person2 = person1;// = 是赋值，把里面所有定义的属性赋值，c/c++ 编译器帮我们做的
//
//	cout << &person1 << " , " << &person2 << endl;
//
//	cout << person2.name << " , " << person2.age << endl;
//
//	getchar();
//}
//void main(){
//
//	Student *stu1 = new Student("Darren",24);
//
//	Student *stu2 = stu1;
//
//	stu2->setAge(26);
//
//	cout << stu1->getName() << " , " << stu1->getAge() << endl;
//
//	getchar();
//}


Student getStudent(char* name){
	Student stu(name);// 栈 ，方法执行完，这个对象会被回收，但是发现调用了拷贝构造函数
	;
	return stu;// 会返回一个新的 Student 对象，而栈内开辟的 stu 是会被回收
}


void printStudent(Student stu){// stu 是该方法栈中一个新的对象，拷贝构造函数赋值，方法执行完会调用析构函数
	cout << stu.getName() << " , " << stu.getAge() << endl;
	cout <<"printStudent,"<< &stu << endl;
}

void main(){
	// 1. = 会调用拷贝构造函数
	// Student stu1("Darren", 24);
	// Student stu2 = stu1; // = 是赋值，把里面所有定义的属性赋值，c/c++ 编译器帮我们做的，其实会调用对象的拷贝构造

	// Student stu2;// 声明变量，开辟变量内存
	// stu2 = stu1; // 这个不会去调用拷贝构造函数，但是会赋值 c 的类似

	// 2. 第二种场景 作为参数返回的时候会调用拷贝构造函数
	  getStudent("Jack");
	 //cout << &stu << endl;

	// 3. 第三种场景 作为参数传递的时候会调用拷贝构造函数
	// Student stu("Darren", 24);
	// printStudent(stu);

	// 知识的补充
	/*Student stu = getStudent("Jack");
	cout << &stu<< endl;
	 cout << stu.getName() << " , " << stu.getAge() << endl;*/
	/*Student stu = getStudent("Jack");
	cout <<"main地址:"<< &stu << endl;
	printStudent(stu);*/
	//cout << stu.getName() << " , " << stu.getAge() << endl;
	//delete(&stu);
	getchar();
}
// 1 ，2
