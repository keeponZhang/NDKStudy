#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm> // Ԥ���庯�� ���Ѿ�ʵ�ֺõ�һЩ�㷨ͷ�ļ�
using namespace std;


//void main(){
//	// map ��� key ���� ���������㷨
//	map<int, string> map1;
//
//	// ������� - ��һ��
//	map1.insert(pair<int,string>(01,"01"));
//
//	// �ڶ��ַ�ʽ
//	map1.insert(make_pair(02,"02"));
//	//map1.insert(make_pair(02, "022"));
//	// �����ַ�ʽ
//	map1.insert(map<int,string>::value_type(03,"03"));
//
//	// ���������ǰ������ key �ظ���� ������Ч
//	// map1.insert(map<int, string>::value_type(03, "30"));
//
//	// �����ַ�ʽ = map1[key] = value
//	map1[04] = "04";
//
//	// �������ǻḲ�ǵ�
//	map1[04] = "40";
//	
//	// ���Ҫ�ж�����Ƿ�ɹ� - �Լ�˼�����ο��ϴο�����
//	map1[00] = "00";
//
//	// ѭ�� - ������
//	for (map<int,string>::iterator it = map1.begin(); it != map1.end(); it++)
//	{
//		cout << it->first << " " << (it->second).c_str() << endl;
//	}
//
//	cout << " ��������" << endl;
//
//	// ɾ�� ������
//	map<int,string>::iterator find_it = map1.find(100);
//
//	// cout << find_it->first << " " << (find_it->second).c_str() << endl;
//	if (find_it != map1.end()){
//		cout << find_it->first << " " << (find_it->second).c_str() << endl;
//	}
//	else{
//		cout << " �Ҳ��� " << endl;
//	}
//
//	getchar();
//}


//void main(){
//	multimap<int, string> map1;
//	// ������1 ��11��12��13����2 ��21��22��23����3��31��32��33��
//
//	map1.insert(pair<int, string>(1,"11"));
//	map1.insert(pair<int, string>(1, "12"));
//	map1.insert(pair<int, string>(1, "13"));
//
//	map1.insert(pair<int, string>(3, "31"));
//	map1.insert(pair<int, string>(3, "32"));
//	map1.insert(pair<int, string>(3, "33"));
//
//	map1.insert(pair<int, string>(2, "21"));
//	map1.insert(pair<int, string>(2, "23"));
//	map1.insert(pair<int, string>(2, "22"));
//	
//
//	// ����
//	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
//	{
//		cout << it->first << " " << (it->second).c_str() << endl;
//	}
//	cout << " ��������" << endl;
//
//	// �����ѯ �������
//	multimap<int, string>::iterator find_it = map1.find(3);
//	while (find_it != map1.end()){
//		cout << find_it->first << " " << (find_it->second).c_str() << endl;
//		find_it++;
//		// ��������Ҫ�ҵ�����
//		if (find_it == map1.end() || find_it -> first != 3){
//			break;
//		}
//	}
//
//	getchar();
//}


class Person
{
public:
	string name;
	char* test;
public:
	Person(){}

	Person(string name){
		this->name = name;
		test = (char*)malloc(12);
	}

	// ��������
	~Person(){
		free(test);
		cout << "��������"<< &test << endl;
	}

public:
	void setName(string name){
		this->name = name;
	}

private:

};

// 3. �������󿽱����캯�� , �����ͬһ�������κεط��ı䣬���ϵ�����Ҳ��Ӧ������ ��ָ�룩
//void main(){
//	// java �аѶ�����ӵ��˼���
//	// c++ �л���ö���Ŀ������캯�������ȥ������һ������
//	// ��һ������û��Ĭ�ϵĹ��캯��
//	// �ڶ���������������Ҳ���ܻص��ö�Σ����˵�������������ͷ��ڴ棬��Ҫ�ڿ������캯���н������
//	vector<Person> vector1;
//
//	Person person("Darren");
//	vector1.push_back(person);
//
//	person.setName("Jack");
//
//	Person person1 = vector1.front();
//
//	cout << person1.name.c_str() << endl;
//
//	getchar();
//}


class Compare
{
	// ���������������
public:
	void operator()(){
		cout << "�º���" << endl;
	}
};

void compare1(){
	cout << "��ͨ����" << endl;
}

// �������󣨷º����� һԪν�ʣ���Ԫν��
//void main(){
//	Compare compare;
//
//	// �������ǳ�����
//	compare();
//	// ��ͨ��������
//	compare1();
//
//	getchar();
//}

// һԪν��
void print(int number){
	cout << number << endl;
}

// �º��� - һԪν�� ���ܹ���¼״̬��
class PrintObj
{
public:
	int count = 0;
public:
	void operator()(int number){
		cout << number << endl;
		count++;
	}
};

// �ص������ͷº���������
void main() {

	set<int> set1;
	set1.insert(1);
	set1.insert(2);
	set1.insert(3);
	set1.insert(4);

	// for_each ������ ,�ǳ���Ҫ��һ����ǣ��º������Ҫ�����¼״̬��Ҫȷ������һ�£������÷���ֵ
	// for_each(set1.begin(),set1.end(),print);
	PrintObj printObj;
	printObj = for_each(set1.begin(), set1.end(), printObj);
	cout << "������" << printObj.count << endl;

	getchar();
}


class CompareObj
{
public:
	int count = 0;
public:
	bool operator()(const string str1, const string str2){
		return str1 < str2;
	}
};

//void main(){
//	// ��Ԫν�ʵķº���
//	set<string, CompareObj> set1;
//	set1.insert("aaa");
//	set1.insert("aAa");
//	set1.insert("ccc");
//	set1.insert("ddd");
//	// �Ƿ���� aaa , �����Ƚ� �� �ҷ���
//	for (set<string>::iterator it = set1.begin(); it != set1.end(); it++)
//	{
//		cout << (*it).c_str() << endl;
//	}
//	getchar();
//}
