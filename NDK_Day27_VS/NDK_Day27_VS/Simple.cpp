#define D_SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>// STL �㷨��
#include <cctype> // �õ�һ������ָ�룬�ص�����

using namespace std;


//void main(){
//
//	string str("1234567");
//
//	// 1. �ַ����ı���
//	for (int i = 0; i < str.length(); i++)
//	{
//		cout << str[i] << endl;
//	}
//
//	// ����������
//	for (string::iterator it = str.begin(); it < str.end(); it++)
//	{
//		cout << *it << endl;
//	}
//
//	try{
//		for (int i = 0; i < str.length()+2; i++)
//		{
//			cout << str.at(i) << endl;// ���Խ������쳣
//		}
//
//		for (int i = 0; i < str.length()+2; i++)
//		{
//			cout << str[i] << endl;// �ᵼ�³���崻���AS�����ǿ��Ե�
//		}
//	}
//	catch (...){
//		cout << "�쳣��" << endl;
//	}
//
//	getchar();
//}


// ��ӣ�ɾ�����滻�����ң���Сдת��
//void main(){
//
//	// ���
//	string str1 = "123";
//	string str2 = "456";
//
//	 //str1 = str1 + str2;
//	 str1.append(str2);
//
//
//	cout << str1.c_str() << endl;
//
//	getchar();
//}


//void main(){
//
//	// ɾ��
//	string str1 = "123 abc 123 abc 123";
//
//	// str1.erase(0,3);// ��һ�������������￪ʼ �� �ڶ���������ɾ��������Ĭ��ֵ���ַ����Ľ�β��
//
//	// ������ɾ��  2 bc 123 abc 123 ����
//	for (string::iterator it = str1.begin(); it<str1.begin()+3; it++)// ɾ��һ���ֺ󶼻��ͷ��ʼ����
//	{
//		printf("%d ", it);
//		str1.erase(it);
//	}
//
//	cout << str1.c_str() << endl;
//
//	getchar();
//}


// �滻
//void main(){
//
//	string str1 = "123 abc 123 abc 123";
//	// ��һ�������������￪ʼ
//	// �ڶ����������滻����
//	// �������������滻��˭
//	str1.replace(0,6,"1234");
//
//	cout << str1.c_str() << endl;
//
//	getchar();
//}


// ����
//void main(){
//
//	string str1 = "123 abc 123 abc 123";
//	// ����˭�������￪ʼ
//	 int position = str1.find("123",1);
//	// �Ӻ�����ǰ���
//	//int position = str1.rfind("123");
//
//	cout << position << endl;
//
//	getchar();
//}


// ��Сдת��
//void main(){
//
//	string str1 = "AAA abc BBB abc 123";
//	 //ת���ɴ�д
//	 transform(str1.begin(), str1.end(), str1.begin(), toupper);
//
//	//transform(str1.begin(), str1.end(), str1.begin(), tolower);
//
//	cout << str1.c_str() << endl;
//
//	getchar();
//}


// ��ҵ
// string str1 = "AAA abc BBB abc 123";  abc ȫ���滻�� def 
//void main(){
//	// �Ĵ�������ı�������ȡ��ַ��register ����
//	register int a = 10;
//	// c++ �ܶ�Ĭ������¾ͻ��� register ��ǿ
//	printf("%d", &a);
//
//	for (register int i = 0; i < 10; i++)
//	{
//
//	}
//
//	getchar();
//}

// ����������ǿ
//int a = 10;
//
//void main(){
//
//	printf("%d", a);
//
//	getchar();
//}


//class Student
//{
//public:
//	char* name;
//
//public:
//	void print() const{
//		// name = "1234";
//	}
//};

// 2.1 ʹ�ó���
//void main(){
//	// 1. ���α������ɸı�
//	// const int number = 1;
//	// ����ָ�� ����ָ�룬ָ�볣��
//	int number = 1;
//	/* const int *n_p = &number;
//	 *n_p = 2;*/
//
//
//	// ָ�볣��
//	 /*int * const n_p = &number;
//	 n_p = 200;*/
//
//	// �������캯������������أ��������棨�����������ĳ�Ա���ɸı䣩
//
//	cout << "Hello" << endl;
//
//	getchar();
//}

// 2.2 c / c++ ֮�������
// c ���� const ��һ��α���⣬����ͨ��ָ��ȥ����������ʱ�ڵļ��
// c++ ���治���ڱ���ʱ����������������ʱ���˴���
//void main(){
//	const int number = 12;
//	// number = 23;
//	int *number_p = const_cast<int*>(&number);// ����ͨ�� const_cast ת���Ѿ������޸�ֵ
//	*number_p = 20;
//	cout << number << endl;
//	cout << *number_p << endl;
//
//	getchar();
//}
// 2.3 c / c++ ���Ե�ʵ��ԭ��
// ʹ��ѧϰ��ʱ��Ҫ�����ȥ����ԭ��
// ����һЩ��ֵ�������취ȥ����


// 3. ���ü�ǿ
// 3.1 ���õ�ʹ�ó���(�عˣ��ô�)
// 3.2 ���õı�������
//void change(int& number1,int& number2){
//	int temp = number1;
//	number1 = number2;
//	number2 = temp;
//}
//// ��ʵ���ñ��ʾ��� ָ��
//void change(int& number1){// �൱�� change(int* number1)
//	number1 = 12;// �൱�� *number1 = 12; 
//}

//void main(){
//
//	int number1 = 10;
//	int number2 = 20;
//
//	change(number1);
//
//	cout << number1 << endl;
//
//	getchar();
//}


int get(){
	int number = 10;
	return number;
}

int& get1(){
	int number = 10;
	return number;
}


// ��������ֵ����ֵ������
//void main(){
//	
//	int number1 = get(); // 10
//	cout << number1 << endl;
//
//	int number2 = get1(); // 10
//	cout << number2 << endl;
//	
//	int& number3 = get1(); //? Ұָ�� 12478
//	cout << number3 << endl;
//
//	getchar();
//}


//class Sudent
//{
//private:
//	string name;
//public:
//	Sudent(string name){
//		this->name = name;
//	}
//
//public:
//	string& getName(){ // Java �붼����
//		return this->name;
//	}
//};
//
//void main(){
//
//	Sudent stu = Sudent("Darren");
//
//	// �Ĳ���
//	 //stu.getName() = "Jack";
//
//	stu.getName() = "Jack";
//
//	cout << stu.getName().c_str() << endl;
//
//	// vector front back 
//
//	getchar();
//}


class Exception {
public:
	Exception(string msg ){
		cout << "���캯��" <<this<< endl;
	}
	Exception(const Exception & e){
		cout << "�������캯��" <<this<< endl;
	}
	~Exception(){
		cout << "��������" <<this<< endl;
	}
};

void c_method(){// ������Լ���д ��1000 ����
	/*Exception e = Exception("�쳣��");
	cout << "����e����:" << &e << endl;
	throw e;*/

	 
	throw  &(Exception("�쳣��"));//һ�㲻����д��������ջ�ᱻ������

	//throw   new Exception("�쳣��");

	//throw  Exception("�쳣��");
}

void main(){
	string my("keepon");
	cout<< my.c_str() << endl;
	try{
		c_method();
	}
	catch (Exception* e){
		 
		// Exception����ι��캯������������ 
		// Exception& �����˶�δ������� (����)
		// Exception* �����Ķ���ᱻ���������ʹ�þֲ��������߳�Ա�ͻ���һ��Ұָ��
		//cout << "try�쳣:" <<e.what()<< "  "<< &e<< endl;
		cout << "try�쳣:" << e << endl;
		//delete e;
	}
	catch (...){
		cout << "�����쳣" << endl;
	}

	getchar();
}



