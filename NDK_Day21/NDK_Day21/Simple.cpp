#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// 1.���캯�� 
class Student
{
public:
	// ���캯��
	Student(){// �ղ������캯��
		cout << "�ղ������캯��"<< endl;
	}

	// Student(char* name):age(0){// һ���������캯��, �൱�� this->age = 0
	//	cout << "һ���������캯��" << endl;
	//	this->name = name;
		// this->age = 0;
	// }

	Student(char* name) :Student(name,0){// �������������Ĺ��캯����ע�⣺�Ȼ�������������Ĺ��캯����Ȼ��Ż�ִ�е�ǰ���캯��
		cout << "һ���������캯��" << endl;
	}

	Student(char* name, int age){// �����������캯��
		cout << "�����������캯��" << endl;
		this->name = (char*)malloc(sizeof(char)*100);
		strcpy(this->name,name);
		
		 //this->name = name;
		this->age = age;
	}

	// 2. ��������,������ڶ����ڲ����ٶ��ڴ棬�����������������ͷ��ڴ�
	~Student(){
		
		// �������ԣ����󱻻��յ�ʱ��ᱻ����
		// �ͷ��ڴ�
		/*if (this->name != NULL){
			cout << "�ͷ�ָ��" << endl;
			free(this->name);
		   this->name = NULL;
		  
		}*/
		
		/*printf("%s\n", this->name);
		free(this->name);
		this->name = NULL;*/
		cout << "��������" << this->name << endl;
	}

	// 4.�������캯�����������һ��Ĭ�ϵĿ������캯������������֮��ĸ�ֵ
	Student(const Student& stu){// ����������
		cout << "�������캯��" << endl;
		 this->name = stu.name;// ǳ����
		// �����̬�����ڴ棬һ��Ҫ�������
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
//	// Student stu;// 1. Ĭ�ϵ��ÿղεĹ��캯��
//	// stu.setAge(24);
//	// stu.setName("Darren");
//
//	// Student stu("Darren",24); // 2. �������������Ĺ��캯��
//
//	// 3. �� new �ؼ���,���ص���һ�� Student ��һ��ָ��
//	// Student *stu = new Student("Darren",24);
//
//	// 4. �� malloc �ķ�ʽ����û�е��ÿղεĹ��캯��
//	// Student *stu = (Student*)malloc(sizeof(Student));
//	// stu->setAge(24);
//	// stu->setName("Darren");
//
//	// ���캯���໥����
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
//	// java ����ı����ջ����ʲô������ android java �ڴ���յ�ʱ��ϵͳ�ܹ��� ��Ѷ���ԣ����ԣ�
//
//	getchar();
//}

// 3. malloc��free��new��delete ����
//void main(){
//	// Student stu;// ջ�п����ڴ�
//
//	// malloc��free�� new��delete ���ǿ��ٺ��ͷ��ڴ�
//	// 1. malloc/free ������һ�ף� new/delete ����Ҳ������
//	// 2. malloc/free ����ȥ���ù��캯������������
//	// Student *stu = (Student*)malloc(sizeof(Student));
//	// free(stu);
//	// 3. new/delete ����ù��캯������������
//	// Student *stu = new Student();
//	// delete(stu);
//	// 4. ������� new ����ôһ��Ҫ�ǵ� delete���ͷ��ڴ棩
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
//	Person person2 = person1;// = �Ǹ�ֵ�����������ж�������Ը�ֵ��c/c++ ����������������
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
	Student stu(name);// ջ ������ִ���꣬�������ᱻ���գ����Ƿ��ֵ����˿������캯��
	;
	return stu;// �᷵��һ���µ� Student ���󣬶�ջ�ڿ��ٵ� stu �ǻᱻ����
}


void printStudent(Student stu){// stu �Ǹ÷���ջ��һ���µĶ��󣬿������캯����ֵ������ִ����������������
	cout << stu.getName() << " , " << stu.getAge() << endl;
	cout <<"printStudent,"<< &stu << endl;
}

void main(){
	// 1. = ����ÿ������캯��
	// Student stu1("Darren", 24);
	// Student stu2 = stu1; // = �Ǹ�ֵ�����������ж�������Ը�ֵ��c/c++ ���������������ģ���ʵ����ö���Ŀ�������

	// Student stu2;// �������������ٱ����ڴ�
	// stu2 = stu1; // �������ȥ���ÿ������캯�������ǻḳֵ c ������

	// 2. �ڶ��ֳ��� ��Ϊ�������ص�ʱ�����ÿ������캯��
	  getStudent("Jack");
	 //cout << &stu << endl;

	// 3. �����ֳ��� ��Ϊ�������ݵ�ʱ�����ÿ������캯��
	// Student stu("Darren", 24);
	// printStudent(stu);

	// ֪ʶ�Ĳ���
	/*Student stu = getStudent("Jack");
	cout << &stu<< endl;
	 cout << stu.getName() << " , " << stu.getAge() << endl;*/
	/*Student stu = getStudent("Jack");
	cout <<"main��ַ:"<< &stu << endl;
	printStudent(stu);*/
	//cout << stu.getName() << " , " << stu.getAge() << endl;
	//delete(&stu);
	getchar();
}
// 1 ��2
