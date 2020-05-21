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
		cout << "拷贝构造函数" << endl;
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

	// 重载减号运算符
	// 为什么要用引用，为了防止重复创建对象
	// const 关键常量，为了防止去修改值
	Vector operator - (const Vector &vector){
		int x = this->x - vector.x;
		int y = this->y - vector.y;
		Vector res(x, y);
		return res;// 不建议返回引用
	}
	Vector operator + (const Vector &vector){
		int x = this->x + vector.b;
		int y = this->y + vector.y;
		Vector res(x,y);
		return res;
	}
	// 自增减运算符
	void operator ++ (){// ++X
		this->x = this->x++;
		this->y = this->y++;
	}

	void operator ++ (int){// X++
		this->x = this->x++;
		this->y = this->y++;
	}
	
	// 自减
	// 输出运算符
	friend ostream & operator << (ostream &_Ostr, const Vector &vector){
		_Ostr << vector.x << "," << vector.y << endl;
		return _Ostr;
	}

	// 条件运算符
	bool operator == (const Vector &vector){
		return (this->x == vector.x && this->y == vector.y);
	}

	// 括号运算符
	
};

// 定义在类的外面，一般来讲我们定义在类的里面
// 重载运算 + ：operator +
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
//	// java 中 string + string 
//
//	 //char* str = "123" + "456";
//
//	// 重载运算符 +
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
//	// 可以重载加其他对象 Person
//
//	getchar();
//}


// 括号运算符
class Array
{
public:
	Array(){
		printf("无参构造函数%p\n", this);
	}
	Array(int size){
		printf("构造函数%p\n", this);
		this->size = size;
		this->array = (int*)malloc(sizeof(int)*size);
	}
	~Array(){
		
		if (this->array){
			free(this->array);
			printf("析构函数指NULL %p\n",this);
			this->array = NULL;
		}
	}

	Array(const Array& array){
		this->size = array.size;
		//this->array = array.array;
		

		
		this->array = (int*)malloc(sizeof(int)*array.size);
		
		// 值的赋值
		for (int i = 0; i < array.size; i++)
		{
			this -> array[i] = array.array[i];
		}
		printf("拷贝构造函数%p\n", this->array);
		printf("拷贝构造函数%p\n", this);
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

	// 操作符[]
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
		printf("A构造函数");
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
//	// 变量修饰符
//public:// 本类中使用
//	// protected ：子类中能使用 （默认）
//	// public ：公开，任何地方都可以
//	char* name;
//	int age;
//
//public:
//	Person(char* name,int age){
//		this->name = name;
//		this->age = age;
//		cout << "Person 构造函数" << endl;
//	}
//
//public:
//	void print(){
//		cout << this->name << " , " << this->age << endl;
//	}
//};

// 类继承 语法 : 
// 类继承修饰符 public
//class Student : public Person
//{
//public:
//	// : Person(name,age) 调用构造函数初始化父类的属性
//	Student(char* name,int age):Person(name,age){// 调用父类构造函数
//		cout << "Student 构造函数" << endl;
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


// 初始化属性
class Person{
	// 变量修饰符
public:// 本类中使用
	// protected ：子类中能使用 （默认）
	// public ：公开，任何地方都可以
	char* name;
	int age;

public:
	Person(char* name, int age){
		this->name = name;
		this->age = age;
		cout << "Person 构造函数" << endl;
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
	// : Person(name,age) 调用构造函数初始化父类的属性
	// 不光可以给父类初始化属性，还可以给本类的属性进行初始化，用 , 隔开即可
	Student(char* name, int age, char* course) :Person(name, age), course(course){// 调用父类构造函数
		cout << "Student 构造函数" << endl;
		course = "数学";
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
	Student stu("Darren",24,"语文");
	stu.print();
	getchar();
}