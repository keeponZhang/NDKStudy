#define _SCL_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<set>
#include<functional>
#include<algorithm>
using namespace std;


// �Զ������� () �����
// 1. Ԥ���庯������ͺ���������
//void main(){
//	// c/c++ �ṩ�˺ܶඨ��õĺ�������
//	// �����ļ��� less ��greater��plus��equal_to
//	plus<string> strAdd;
//	string str = strAdd("aaa","bbb");
//
//	// cout << str.c_str() << endl;
//
//	set<string, greater<string>> set1;
//	set1.insert("aaa");
//	set1.insert("bbb");
//	set1.insert("ccc");
//
//	// �ж��ǲ��ǰ��� aaa 
//	// ��ôд�º�����һ��Ҫȷ������ķº����Ĳ���
//	// bind2nd ���������� , aaa �൱�� equal_to �е� right 
//	
//	template<class _Ty = void>
//	//struct multiplies
//	//	: public binary_function<_Ty, _Ty, _Ty>
//	//{	// functor for operator*
//	//	_Ty operator()(const _Ty& _Left, const _Ty& _Right) const
//	//	{	// apply operator* to operands
//	//		return (_Left * _Right);
//	//	}
//	//};
//	set<string, greater<string>>::iterator find_it = find_if(set1.begin(), set1.end(),bind2nd(equal_to<string>(),"aaa"));
//	if (find_it != set1.end()){
//		cout << "�ҵ���" << (*find_it).c_str() << endl;
//	}
//	else
//	{
//		cout << "û���ҵ�" << endl;
//	}
//
//	getchar();
//}


// 1���ַ�ʽ�Զ���º�������������
//class Equal
//{
//private:
//	int equal_number;
//public:
//	Equal(int equal_number){
//		this->equal_number = equal_number;
//	}
//public:
//	bool operator()(const int& number){
//		return number == equal_number;
//	}
//};

//void main(){
//	vector<int> vector1;
//	vector1.push_back(1);
//	vector1.push_back(2);
//	vector1.push_back(3);
//	vector1.push_back(2);
//	vector1.push_back(4);
//	vector1.push_back(2);
//
//	// �Ҽ����� ���� 2 �ĸ���
//	int count = count_if(vector1.begin(), vector1.end(), Equal(2));
//	cout << "count = " << count << endl;
//
//	// Ԥ����õĺ������� + ����������
//	count = count_if(vector1.begin(), vector1.end(), bind2nd(equal_to<int>(),2));
//	cout << "count = " << count << endl;
//
//	getchar();
//}


//void print(int number){
//	cout << number << endl;
//}
//
//// �����޸�
//int transform_print(int number){
//	// cout << number << endl;
//	return number + 3;
//}

// foreach��transform��find��find_if��count��count_if��megre��sort��random_shuffle��copy��replace
// ����Ԥ�����㷨 ѭ��������ɾ���ģ���
//void main(){
//	vector<int> vector1;
//	vector1.push_back(1);
//	vector1.push_back(2);
//	vector1.push_back(3);
//	vector1.push_back(4);
//
//	// for_each(vector1.begin(), vector1.end(),print);
//	vector<int> vector2;
//	vector2.resize(vector1.size());
//
//	transform(vector1.begin(), vector1.end(), vector2.begin(), transform_print);
//
//	for_each(vector2.begin(), vector2.end(), print);
//
//	getchar();
//}


// find��find_if
//void main(){
//	vector<int> vector1;
//	vector1.push_back(1);
//	vector1.push_back(2);
//	vector1.push_back(3);
//	vector1.push_back(4);
//
//	vector<int>::iterator find_it = find(vector1.begin(), vector1.end(), 2);
//
//	if (find_it != vector1.end()){
//		cout << "����" << endl;
//	}
//	else
//	{
//		cout << "������" << endl;
//	}
//
//	// ��û�д���2�ģ��Զ��庯������Ԥ���庯������+������������ʡ��...
//
//	getchar();
//}


// count��count_if
//void main(){
//	vector<int> vector1;
//	vector1.push_back(1);
//	vector1.push_back(2);
//	vector1.push_back(3);
//	vector1.push_back(2);
//	vector1.push_back(4);
//
//	int number = count(vector1.begin(), vector1.end(), 2);
//
//	cout << "����2�ĸ���:" << number << endl;
//
//	number = count_if(vector1.begin(), vector1.end(), bind2nd(less<int>(), 2));
//
//	cout << "С��2�ĸ���:" << number << endl;
//
//	number = count_if(vector1.begin(), vector1.end(), bind2nd(greater<int>(), 2));
//
//	cout << "����2�ĸ���:" << number << endl;
//
//	getchar();
//}

//class _merge
//{
//public:
//	bool operator()(int number1,int number2){
//		return true;
//	}
//
//};
//
//void print(int number){
//	cout << number << endl;
//}

// megre��sort��random_shuffle��copy��replace
//void main(){
//
//	// ��������������кϲ� - �鲢����
//	vector<int> vector1;
//	vector1.push_back(1);
//	vector1.push_back(2);
//	vector1.push_back(3);
//
//	vector<int> vector2;
//	vector1.push_back(4);
//	vector1.push_back(5);
//	vector1.push_back(6);
//
//	vector<int> vector3;
//	vector3.resize(6);
//	merge(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), vector3.begin());
//	for_each(vector3.begin(), vector3.end(), print);
//
//	getchar();
//}


//void print(int number){
//	cout << number << endl;
//}

//void main(){
//
//	vector<int> vector1;
//	vector1.push_back(1);
//	vector1.push_back(3);
//	vector1.push_back(2);
//	vector1.push_back(4);
//
//	sort(vector1.begin(),vector1.end(),less<int>());
//	for_each(vector1.begin(), vector1.end(), print);
//
//	cout << "ѭ������" << endl;
//
//	// ����ѭ�� 
//	random_shuffle(vector1.begin(), vector1.end());
//	for_each(vector1.begin(), vector1.end(), print);
//
//	getchar();
//}


void print(int number){
	cout << number << endl;
}

// copy��replace
void main(){

	vector<int> vector1;
	vector1.push_back(1);
	vector1.push_back(2);
	vector1.push_back(3);
	vector1.push_back(4);

	vector<int> vector2;
	vector2.resize(2);
	copy(vector1.begin(), vector1.begin() + 2, vector2.begin());
	// for_each(vector2.begin(), vector2.end(), print);

	replace(vector1.begin(), vector1.end(), 2, 22);
	for_each(vector1.begin(), vector1.end(), print);

	getchar();
}

// ͷ���ķ�װ ToolBar ˼�����Զ��� View  4����ʽ     
// ˼������ ����ʽȥ��� NavigationBar (����Դ����ֿ��) 

// ������� ����չ�Բ���ʵ���Բ�ǿ ���̳�(����)���ڸ��ӣ�����
 
// ģ���� _InIt ���� , _First, _Last , ����ֵ ��һ������
// _Pr _Pred ����ʲô��
//template<class _InIt,
//class _Pr> inline
//	_InIt find_if(_InIt _First, _InIt _Last, _Pr _Pred)
//{	// find first satisfying _Pred
//		_DEBUG_RANGE(_First, _Last);
//		_DEBUG_POINTER(_Pred);
//		return (_Rechecked(_First,
//			_Find_if(_Unchecked(_First), _Unchecked(_Last), _Pred)));
//	}
//template<class _InIt,
//class _Pr> inline
//	_InIt _Find_if(_InIt _First, _InIt _Last, _Pr _Pred)
//{	// find first satisfying _Pred
//		for (; _First != _Last; ++_First)
//		// if ����ֵ��һ�� bool ���� ���� _Pred ���洫����һ������ ��Ҫô���ǻص�����Ҫô���Ƿº���
//		if (_Pred(*_First))
//			break;
//		return (_First);
//}


// ��һ����ȷ���ã������뽲�� ���Լ�ȥ������֤��

// ���氲�� ��2�����п���ʶ�� ��20�����ݽṹ�㷨����Ƶ�����⣩��15�� Openvc 20�� ����Ƶ 
// ��� + ���  opencv mat-bitmap 

// QQȺ��546270670
// ��ƵGrace��2746186102 




























