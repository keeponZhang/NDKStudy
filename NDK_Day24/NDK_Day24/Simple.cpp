#include <iostream>

using namespace std;

// 1. ���Գ�ʼ��

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
//Student(char* name, int age, string courseName) : Person(name, age), course(courseName){ // ��ʼ�����������
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



// 2. ��̳У��� java �����ǲ������̳� �� c++ �ǿ��Եģ�������Ҳ�����ж����ԣ����壩

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
//class Student : public Person, public Child // ��̳� , ��û��ʵ��
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

// 2.2 ��̳� �������ԣ�
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
//class B : virtual public A{ // ȷ���̳й�������ͬ���Ի��ߺ�����ֻ����һ�ݿ���
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


// 3. c++ �еĶ�̬
//class Activity
//{
//public:
//	virtual void onCreate(){ // ֧�ֶ�̬���麯��
//		cout << "Activity �е� onCreate" << endl;
//	}
//};
//
//class MainActivity : public Activity
//{
//public:
//	void onCreate(){
//		cout << "MainActivity �е� onCreate" << endl;
//	}
//};
//
//class WelcomeActivity : public Activity
//{
//public:
//	void onCreate(){
//		cout << "WelcomeActivity �е� onCreate" << endl;
//	}
//};
//
//void startActivity(Activity* activity){
//	activity->onCreate();
//}
//
//void main(){
//	Activity *activity1 = new MainActivity();// ���� = new �������
//	Activity *activity2 = new WelcomeActivity();
//
//	// activity->onCreate();
//	// c++ �еĶ�̬�������ģ�Ĭ������²�����
//	// ����ָ����������ã���д �������滻ԭ�� 
//	// �����ڱ����ڼ䲢��֪�����е�״̬������Ҫ�����Ǹ���������ֻҪ���������еĹ����вŻ�ȥ����Ҫ���еķ���
//	// ����һ�� java �еĶ�̬ 20K
//	startActivity(activity1);
//	startActivity(activity2);
//
//	// c++ ��̬����̬��̬(�Ӹ���)����̬��̬�����������أ����������ȷ���Ե�����
//	//��һ���⳵��5 �֣� 2 �֣���ƣ���4 ��
//
//	getchar();
//}


//// java �����Ƶ� �����࣬�ӿ� ���麯��
//class BaseActivity // �� java �еĳ�����һ������
//{
	//public:
	//	//void onCreate(){// ��ͨ����
	//	//	initView();
	//	//	initData();
	//	//}
	//	void onReusme(){// ��ͨ����
	//		cout << "BaseActivity onReusme" << endl;
	//	}
	//	// �������Ҫʵ�� 
	//	//virtual void initData() = 0;// �麯����û��ʵ�ֵģ������� java �еĳ��󷽷���������಻ʵ�ֻᱨ��
	//
	//	//virtual void initView() = 0;
	//
	//	virtual void initData(){
	//		cout << "BaseActivity initData" << endl;
	//	};//  �ᱨ��
	//	virtual void initView()=0;//virtual void initView();(�ᱨ��virtualʵ�ֱ�����ʵ�ֻ���=0����
	//};

	//void BaseActivity::initData(){
	//	cout << "BaseActivity initData" << endl;
	//}
	//void BaseActivity::initView(){
	//	cout << "BaseActivity initView" << endl;
	//}

	// �����ʵ�ָ���Ĵ��麯������ô MainActivity Ҳ���ɳ����࣬�����಻����ʵ����
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
	//		cout << "����" << endl;
	//	}
	//};
	//class CDerivedA : public CBase
	//{
	//public:
	//	int my(float a){
	//		cout << "����" << endl;//��һ����������������������ͣ���������ͬ
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
	//		cout << "����" << endl;
	//	}
	//};
	//class CDerivedA : public CBase
	//{
	//public:
	//	void my(int a){
	//		cout << "����" << endl;//����������ͬ
	//	}
	//};
	//int main()
	//{
	//	CDerivedA ptr;
	//	ptr.my(5);//��1������һ������
	//	ptr.my(5, 5);//��2������������������ʱ�ᱨ����������������������˵�����ʱ�����ಢû�м̳е�����void my(int a,int b)������
	//	system("pause");
	//	return 0;
	//}



	//class CBase
	//{
	//public:
	//	void  my(int a, int b){
	//		cout << "����" << endl;
	//	}
	//	virtual void Walk(){ cout << "CBase:Walk" << endl; }
	//};
	//class CDerivedA : public CBase
	//{
	//public:
	//	void my(int a){
	//		cout << "����" << endl;
	//	}
	//	void  Walk(){ cout << "CDerivedA:Walk" << endl; }//�ض���������ԭ�������Ͳ�ͬ
	//};
	//int main()
	//{
	//	CDerivedA ptr;
	//	ptr.Walk();
	//	system("pause");
	//	return 0;
	//}



	//���಻�����ظ��ຯ�����������ط�����ͬһ��������
	//class CBase
	//{
	//public:
	//	void  my(int a, int b){
	//		cout << "����" << endl;
	//	}
	//	virtual void Walk(int a){ cout << "CBase:Walk" << endl; }
	//};
	//class CDerivedA : public CBase
	//{
	//public:
	//	void my(int a){
	//		cout << "����" << endl;
	//	}
	//	int  Walk(){ cout << "CDerivedA:Walk" << endl; }//��д
	//};
	//int main()
	//{
	//	CDerivedA ptr;
	//	ptr.Walk(2);//�������������� 1 ������
	//	ptr.Walk();//�����CDerivedA:Walk
	//	system("pause");
	//	return 0;
	//}

	class ClickListener{// ���еĺ��������麯������ô�Ϳ�����Ϊ�ǽӿ�
	public:
		virtual void click() = 0;
	};

	class ImageClickListener : public ClickListener
	{
	public:
		void click(){
			cout << "ͼƬ���" << endl;
		}
	};
	class DoubleClickListener : public ClickListener
	{
	public:
		void click(){
			cout << "˫����Ӵ" << endl;
		}
	};

	/*void click(ClickListener *listener){
		listener->click();
	}*/

	// ����ָ�� 07 ��
	void click1(void(*c)(int)){// ����ָ����Ϊ��������  ����ֵ(������)(����)
		// ѹ����ʼ
		for (size_t i = 0; i < 20; i++)
		{
			c(i);// ���ѹ������
		}
		
		// ѹ������
	}
	
	void click(int i){
		cout << "click���"<<i << endl;
	}
	
	/*void main(){
		
		click1(click);
		getchar();
	}
*/

void printWelcome(int len)

{

	printf("��ӭ��ӭ -- %d\n", len);

}



void printGoodbye(int len)

{

	printf("�Ϳ��Ϳ� -- %d\n", len);

}



void callback(int times, void(*print)(int))

{

	int i;

	for (i = 0; i < times; ++i)

	{

		print(i);

	}

	printf("\n�Ҳ�֪������ӭ�ͻ����Ϳ�!\n\n");

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


	// ���캯������������ 
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
	//		cout << "Person �Ĺ��캯��" << endl;
	//	}
	//
	//	~Person(){
	//		cout << "Person ����������" << endl;
	//	}
	//};
	//
	//class Student : public Person
	//{
	//public:
	//	Student(char* name, int age) : Person(name, age){ // ��ʼ�����������
	//		cout << "Student �Ĺ��캯��" << endl;
	//	}
	//	~Student(){
	//		cout << "Student ����������" << endl;
	//	}
	//};
	//
	//void main(){
	//	 ���캯�����ȸ��� -> ������
	//	 ���������������� -> �ٸ���
	//	Student *stu = new Student("Darren",24);
	//	delete stu;
	//
	//	getchar();
	//}


	// ģ�庯�� ��java �еķ��ͣ�
	/*int add(int number1, int number2){
		return number1 + number2;
	}

	double add(double number1, double number2){
		return number1 + number2;
	}

	float add(float number1, float number2){
		return number1 + number2;
	}*/

	// ģ�庯��  �㷨4 ��һ����һ��
	template <typename T>// ģ�庯���Ķ���
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


