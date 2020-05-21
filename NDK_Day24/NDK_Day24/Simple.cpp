#include <iostream>

using namespace std;

// 1. 属性初始化

//class Person
//{
//protected:
//char* name;
//int age;
//public:
//Person(char* name, int age){
//this->name = name;
//this->age = age;
//}
//};
//
//class Course
//{
//private:// java String
//string name;
//public:
//Course(string name){
//this->name = name;
//}
//
//public:
//string _name(){
//return this->name;
//}
//};
//
//class Student : public Person
//{
//private:
//// char* courseName;
//Course course;
//public:
//Student(char* name, int age, string courseName) : Person(name, age), course(courseName){ // 初始化父类的属性
//// this->courseName = courseName;
//}
//
//void print(){
//cout << name << "," << age << "," << course._name().c_str() << endl;
//}
//};
//
//void main(){
//	Student *stu = new Student("keepon", 26, "math");
//	stu->print();
//	delete stu;
//	getchar();
//}



// 2. 多继承，在 java 里面是不允许多继承 ， c++ 是可以的，但是你也不能有二义性（歧义）

//class Person{
//private:
//	char * name;
//	int age;
//public:
//	Person(char * name){
//		this->name = name;
//	}
//
//	char* _name(){
//		return this->name;
//	}
//	int _age(){
//		return this->age;
//	}
//};
//
//class Child
//{
//	int age;
//public:
//	Child(int age){
//		this->age = age;
//	}
//
//	int _age(){
//		return this->age;
//	}
//};
//
//class Student : public Person, public Child // 多继承 , 并没有实现
//{
//public:
//	Student(char* name,int age):Person(name),Child(age){
//		
//	}
//};
//void main(){
//	Student *stu = new Student("keepon", 26);
//	cout<<stu->_age();
//	delete stu;
//	getchar();
//}

// 2.2 虚继承 （二义性）
//class A{
//public:
//	char* name="keepon";
//public:
//	A(){
//
//	}
//	A(char*name){
//		this->name = name;
//	}
//
//};
//
//class B : virtual public A{ // 确保继承过来的相同属性或者函数，只存在一份拷贝
//public:
//	
//	B(){
//
//	}
//	B(char* name):A(name){
//		
//	}
//};
//
//class C :virtual public A{
//public:
//	C(){
//
//	}
//	C(char* name) :A(name){
//
//	}
//};
//
//class D : public B ,public C
//{
//	
//
//};
//void main(){
//	D d ;
//	cout<<d.name;
//	
//	getchar();
//}


// 3. c++ 中的多态
//class Activity
//{
//public:
//	virtual void onCreate(){ // 支持多态，虚函数
//		cout << "Activity 中的 onCreate" << endl;
//	}
//};
//
//class MainActivity : public Activity
//{
//public:
//	void onCreate(){
//		cout << "MainActivity 中的 onCreate" << endl;
//	}
//};
//
//class WelcomeActivity : public Activity
//{
//public:
//	void onCreate(){
//		cout << "WelcomeActivity 中的 onCreate" << endl;
//	}
//};
//
//void startActivity(Activity* activity){
//	activity->onCreate();
//}
//
//void main(){
//	Activity *activity1 = new MainActivity();// 父类 = new 子类对象
//	Activity *activity2 = new WelcomeActivity();
//
//	// activity->onCreate();
//	// c++ 中的多态是怎样的，默认情况下不存在
//	// 父类指向子类的引用，重写 ，里氏替换原则 
//	// 程序在编译期间并不知晓运行的状态（我需要运行那个函数），只要在真正运行的过程中才会去找需要运行的方法
//	// 解释一下 java 中的多态 20K
//	startActivity(activity1);
//	startActivity(activity2);
//
//	// c++ 多态：动态多态(子父类)，静态多态（函数的重载）（编译过程确定性的区别）
//	//（一嗨租车）5 轮， 2 轮（万科），4 轮
//
//	getchar();
//}


//// java 中类似的 抽象类，接口 纯虚函数
//class BaseActivity // 跟 java 中的抽象类一个概念
//{
	//public:
	//	//void onCreate(){// 普通函数
	//	//	initView();
	//	//	initData();
	//	//}
	//	void onReusme(){// 普通函数
	//		cout << "BaseActivity onReusme" << endl;
	//	}
	//	// 子类必须要实现 
	//	//virtual void initData() = 0;// 虚函数，没有实现的，类似于 java 中的抽象方法，如果子类不实现会报错
	//
	//	//virtual void initView() = 0;
	//
	//	virtual void initData(){
	//		cout << "BaseActivity initData" << endl;
	//	};//  会报错
	//	virtual void initView()=0;//virtual void initView();(会报错，virtual实现必须有实现或者=0）；
	//};

	//void BaseActivity::initData(){
	//	cout << "BaseActivity initData" << endl;
	//}
	//void BaseActivity::initView(){
	//	cout << "BaseActivity initView" << endl;
	//}

	// 如果不实现父类的纯虚函数，那么 MainActivity 也会变成抽象类，抽象类不允许实例化
	//class MainActivity : public BaseActivity 
	//{
	//public:
	//	
	//	
	//	 void onReusme(){
	//		cout << "MainActivity initView" << endl;
	//	}
	//	virtual void initData(){
	//		cout << "MainActivity initData" << endl;
	//	}
	//	virtual void initView(){
	//		cout << "MainActivity initView" << endl;
	//	}
	//};
	//
	//void main(){
	//	
	//	BaseActivity *m_a = new MainActivity();
	//
	//	m_a->initView();
	//
	//	getchar();
	//}

	//class CBase
	//{
	//public:
	//	virtual void my(int a){
	//		cout << "父类" << endl;
	//	}
	//};
	//class CDerivedA : public CBase
	//{
	//public:
	//	int my(float a){
	//		cout << "子类" << endl;//第一种情况，函数名，返回类型，参数都相同
	//		return 2;
	//	}
	//};
	//int main()
	//{
	//	CDerivedA *ptr = new CDerivedA();
	//	int b=ptr->my(5.0);
	//	system("pause");
	//	return 0;
	//}


	//class CBase
	//{
	//public:
	//	void  my(int a, int b){
	//		cout << "父类" << endl;
	//	}
	//};
	//class CDerivedA : public CBase
	//{
	//public:
	//	void my(int a){
	//		cout << "子类" << endl;//参数个数不同
	//	}
	//};
	//int main()
	//{
	//	CDerivedA ptr;
	//	ptr.my(5);//（1）给出一个参数
	//	ptr.my(5, 5);//（2）给出两个参数，此时会报错，函数不接受两个参数。说明这个时候，子类并没有继承到父类void my(int a,int b)函数。
	//	system("pause");
	//	return 0;
	//}



	//class CBase
	//{
	//public:
	//	void  my(int a, int b){
	//		cout << "父类" << endl;
	//	}
	//	virtual void Walk(){ cout << "CBase:Walk" << endl; }
	//};
	//class CDerivedA : public CBase
	//{
	//public:
	//	void my(int a){
	//		cout << "子类" << endl;
	//	}
	//	void  Walk(){ cout << "CDerivedA:Walk" << endl; }//重定义类型与原来的类型不同
	//};
	//int main()
	//{
	//	CDerivedA ptr;
	//	ptr.Walk();
	//	system("pause");
	//	return 0;
	//}



	//子类不能重载父类函数。即，重载发生在同一个类里面
	//class CBase
	//{
	//public:
	//	void  my(int a, int b){
	//		cout << "父类" << endl;
	//	}
	//	virtual void Walk(int a){ cout << "CBase:Walk" << endl; }
	//};
	//class CDerivedA : public CBase
	//{
	//public:
	//	void my(int a){
	//		cout << "子类" << endl;
	//	}
	//	int  Walk(){ cout << "CDerivedA:Walk" << endl; }//重写
	//};
	//int main()
	//{
	//	CDerivedA ptr;
	//	ptr.Walk(2);//报错：函数不接受 1 个参数
	//	ptr.Walk();//输出：CDerivedA:Walk
	//	system("pause");
	//	return 0;
	//}

	class ClickListener{// 所有的函数都是虚函数，那么就可以认为是接口
	public:
		virtual void click() = 0;
	};

	class ImageClickListener : public ClickListener
	{
	public:
		void click(){
			cout << "图片点击" << endl;
		}
	};
	class DoubleClickListener : public ClickListener
	{
	public:
		void click(){
			cout << "双击了哟" << endl;
		}
	};

	/*void click(ClickListener *listener){
		listener->click();
	}*/

	// 函数指针 07 次
	void click1(void(*c)(int)){// 函数指针作为参数传递  返回值(函数名)(参数)
		// 压缩开始
		for (size_t i = 0; i < 20; i++)
		{
			c(i);// 输出压缩进度
		}
		
		// 压缩结束
	}
	
	void click(int i){
		cout << "click点击"<<i << endl;
	}
	
	/*void main(){
		
		click1(click);
		getchar();
	}
*/

void printWelcome(int len)

{

	printf("欢迎欢迎 -- %d\n", len);

}



void printGoodbye(int len)

{

	printf("送客送客 -- %d\n", len);

}



void callback(int times, void(*print)(int))

{

	int i;

	for (i = 0; i < times; ++i)

	{

		print(i);

	}

	printf("\n我不知道你是迎客还是送客!\n\n");

}

//void main(void)
//
//{
//
//	callback(10, printWelcome);
//
//	callback(10, printGoodbye);
//
//	printWelcome(5);
//	getchar();
//
//}


	// 构造函数和析构函数 
	//class Person
	//{
	//protected:
	//	char* name;
	//	int age;
	//public:
	//	Person(char* name, int age){
	//		this->name = name;
	//		this->age = age;
	//
	//		cout << "Person 的构造函数" << endl;
	//	}
	//
	//	~Person(){
	//		cout << "Person 的析构函数" << endl;
	//	}
	//};
	//
	//class Student : public Person
	//{
	//public:
	//	Student(char* name, int age) : Person(name, age){ // 初始化父类的属性
	//		cout << "Student 的构造函数" << endl;
	//	}
	//	~Student(){
	//		cout << "Student 的析构函数" << endl;
	//	}
	//};
	//
	//void main(){
	//	 构造函数：先父类 -> 再子类
	//	 析构函数：先子类 -> 再父类
	//	Student *stu = new Student("Darren",24);
	//	delete stu;
	//
	//	getchar();
	//}


	// 模板函数 （java 中的泛型）
	/*int add(int number1, int number2){
		return number1 + number2;
	}

	double add(double number1, double number2){
		return number1 + number2;
	}

	float add(float number1, float number2){
		return number1 + number2;
	}*/

	// 模板函数  算法4 看一遍敲一遍
	template <typename T>// 模板函数的定义
	T add(T number1, T number2){
		return number1 + number2;
	}

	void main(){
		
		int sum1 = add(1,2);
	
		cout << sum1 << endl;
	
		int sum2 = add(1.0, 2.0);
	
		cout << sum2 << endl;
	
		int sum3 = add(1.0f, 2.0f);
	
		cout << sum3 << endl;
	
		getchar();
	}


