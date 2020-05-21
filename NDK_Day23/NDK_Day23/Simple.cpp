#include <iostream>

using namespace std;


class  Vector
{
public:
	Vector(int x, int y){
		this->x = x;
		this->y = y;
	}

	Vector(const Vector &vector){
		this->x = vector.x;
		this->y = vector.y;
		cout << "�������캯��" << endl;
	}
private:
	int x;
	int y;
	
	
public:
	int b;
	void setX(int x){
		this->x = x;
	}
	void setY(int y){
		this->y = y;
	}

	int getX(){
		return this->x;
	}
	int getY(){
		return this->y;
	}

	// ���ؼ��������
	// ΪʲôҪ�����ã�Ϊ�˷�ֹ�ظ���������
	// const �ؼ�������Ϊ�˷�ֹȥ�޸�ֵ
	Vector operator - (const Vector &vector){
		int x = this->x - vector.x;
		int y = this->y - vector.y;
		Vector res(x, y);
		return res;// �����鷵������
	}
	Vector operator + (const Vector &vector){
		int x = this->x + vector.b;
		int y = this->y + vector.y;
		Vector res(x,y);
		return res;
	}
	// �����������
	void operator ++ (){// ++X
		this->x = this->x++;
		this->y = this->y++;
	}

	void operator ++ (int){// X++
		this->x = this->x++;
		this->y = this->y++;
	}
	
	// �Լ�
	// ��������
	friend ostream & operator << (ostream &_Ostr, const Vector &vector){
		_Ostr << vector.x << "," << vector.y << endl;
		return _Ostr;
	}

	// ���������
	bool operator == (const Vector &vector){
		return (this->x == vector.x && this->y == vector.y);
	}

	// ���������
	
};

// ������������棬һ���������Ƕ������������
// �������� + ��operator +
Vector operator + ( Vector vector1,  Vector vector2){
	int x = vector1.getX() + vector2.getX();
	int y = vector1.getY() + vector2.getY();
	Vector vector(x,y);
	return vector;
}

//void main(){
//	Vector vector1(3, 4);
//	Vector vector2(2, 3);
//
//	// java �� string + string 
//
//	 //char* str = "123" + "456";
//
//	// ��������� +
//	 Vector vector = vector1 - vector2;
//
//	// Vector vector(1, 2);
//	// vector++;
//	// ++vector;
//
//	 cout << vector.getX() << " , " << vector.getY() << endl;
//	// cout << vector << vector;
//	bool isEqual = vector1 == vector2;
//	cout << isEqual << endl;
//
//	// �������ؼ��������� Person
//
//	getchar();
//}


// ���������
class Array
{
public:
	Array(){
		printf("�޲ι��캯��%p\n", this);
	}
	Array(int size){
		printf("���캯��%p\n", this);
		this->size = size;
		this->array = (int*)malloc(sizeof(int)*size);
	}
	~Array(){
		
		if (this->array){
			free(this->array);
			printf("��������ָNULL %p\n",this);
			this->array = NULL;
		}
	}

	Array(const Array& array){
		this->size = array.size;
		//this->array = array.array;
		

		
		this->array = (int*)malloc(sizeof(int)*array.size);
		
		// ֵ�ĸ�ֵ
		for (int i = 0; i < array.size; i++)
		{
			this -> array[i] = array.array[i];
		}
		printf("�������캯��%p\n", this->array);
		printf("�������캯��%p\n", this);
	}

private:
	int size;
	int* array;

public:
	void set(int index,int value){
		array[index] = value;
	}

	int get(int index){
		return this->array[index];
	}

	int getSize(){
		return this->size;
	}

	// ������[]
	int operator[](int index){
		//return this->array[index]+1;
		return  *(array+index) + 1;

	}
};

void printfArray(Array array){
	printf("printfArray%d\n", array);
	for (int i = 0; i < array.getSize(); i++)
	{
		cout << array[i] << endl;
	}
	
}
class A{
private:
	int age;
public:
	A():A(10){
		
	}
	A(int age){
		this->age = age;
		printf("A���캯��");
	}
};
//void main(){
//	A a;
//	printf("test%d\n", a);
//
//
//	Array *array = new Array(5);
//	printf("main%p\n", array);
//	
//	array->set(0,0);
//	array->set(1, 1);
//	array->set(2, 2);
//
//	printfArray(*array);
//
//	delete(array);
//	getchar();
//}


//class Person{
//	// �������η�
//public:// ������ʹ��
//	// protected ����������ʹ�� ��Ĭ�ϣ�
//	// public ���������κεط�������
//	char* name;
//	int age;
//
//public:
//	Person(char* name,int age){
//		this->name = name;
//		this->age = age;
//		cout << "Person ���캯��" << endl;
//	}
//
//public:
//	void print(){
//		cout << this->name << " , " << this->age << endl;
//	}
//};

// ��̳� �﷨ : 
// ��̳����η� public
//class Student : public Person
//{
//public:
//	// : Person(name,age) ���ù��캯����ʼ�����������
//	Student(char* name,int age):Person(name,age){// ���ø��๹�캯��
//		cout << "Student ���캯��" << endl;
//	}
//	
//	void test(){
//		print();
//	}
//};

//void main(){
//	Student stu("Darren",24);
//
//	stu.name = "Jack";
//
//	getchar();
//}


// ��ʼ������
class Person{
	// �������η�
public:// ������ʹ��
	// protected ����������ʹ�� ��Ĭ�ϣ�
	// public ���������κεط�������
	char* name;
	int age;

public:
	Person(char* name, int age){
		this->name = name;
		this->age = age;
		cout << "Person ���캯��" << endl;
	}

public:
	void print(){
		cout << this->name << " , " << this->age << endl;
	}
};


class Student : public Person
{
private:
	 //Teacher*  teacher = new Teacher("keepon", 21);
	char* course;
public:
	// : Person(name,age) ���ù��캯����ʼ�����������
	// ������Ը������ʼ�����ԣ������Ը���������Խ��г�ʼ������ , ��������
	Student(char* name, int age, char* course) :Person(name, age), course(course){// ���ø��๹�캯��
		cout << "Student ���캯��" << endl;
		course = "��ѧ";
	}

	void print(){
		cout << "course: " << course << endl;
	}
};

class Teacher: public Person
{
public:
	Teacher(char*name,int age):Person(name,age){
		
	}
};

void main(){
	Student stu("Darren",24,"����");
	stu.print();
	getchar();
}