#include <iostream>

using namespace std;

//template <typename T>
//T add(T number1 , T number2){
//
//	cout << "ģ�庯��������" << endl;
//	return number1 + number2;
//}

// �������� 3 ������ �� ������һ�� int �����Ͳ���������ɣ����� double float û�У��ͻ���������

// ������ xposed ����
// 1. �����ʱ�� c �� c++ ��������� cpp/c �ļ���һЩ�Ż���ģ�庯����
// 2. java �� small -> class��Ҳ������ c/c++ �������ܹ���ʶ��һ�״��� public:void _thiscall Activity::initView(void)
// 3. ���ɶ������ļ� .obj .o �ȵ�һЩ�ļ�����������ģ�� cmake ��һЩ���� 
// 4. ���ͻ��ִ���ļ� .dll, .so , .exe

//
//class Activity
//{
//public:
//	void initView();
//
//	void initData();
//
//};
//
//class MainActivity: public Activity
//{
//public:
//
//	void initView(){
//		
//	}
//};
//
//
//
//// ����ͨ������ģ�庯��ͬʱ���ڵ�ʱ�����Ȼ������ͨ����
////��ͨ����
//int add(int number1 , int number2){
//	cout << "int add ������" << endl;
//	return number1 + number2;
//}
//
//// so �Ǻ��ѱ������룬��java��ȫΪɶ��
//// small �﷨
//
//void main(){
//
//	int sum1 = add(1,2);
//
//	double sum2 = add(1.0 , 2.3);
//
//	float sum3 = add(1.0f, 2.4f);
//
//	cout << sum1 << " , " << sum2 << endl;
//
//	getchar();
//}


// 2. ģ����  �﷨����ģ�庯���ǳ�����
template <class T>
class Callback
{
public:
	void onError(){
		
	}

	void onSucceed(T result){
		cout << result << endl;
	}
};

// ģ����̳� ���������Ҳ��ģ����
// ������಻��ģ����
//class HttpCallback : public Callback<int>
//{
//	
//};

template <class T>
class HttpCallback : public Callback<T>
{

};

void main(){
	HttpCallback<int> *callback = new HttpCallback<int>();

	callback->onSucceed(12);

	getchar();
}


