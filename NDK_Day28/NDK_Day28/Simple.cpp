#include <iostream>

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include <set>

using namespace std;


//void main(){ // vector ����
//
//	// vector  
//	// 1. vector<int> v;
//
//	// 2. vector<int> v(10);
//
//	// 3. vector<int> v(10,0);
//
//
//	vector<int> v;
//
//	// ��������
//	// v.begin() �������Ŀ�ʼλ��
//	v.insert(v.begin(),12);
//	v.insert(v.begin(), 22);
//	v.insert(v.begin(), 32);
//
//	//v.insert(v.end(), 42);
//
//	// ���õ���ֵ����ֵ (�޸�)
//	/*v.front() = 33;
//	v.back() = 44;*/
//
//	v.push_back(55);
//
//	// �Ƴ�����Ԫ�أ���û�з���ֵ
//	// v.pop_back();
//	// ͨ��������λ�ý����Ƴ�
//	//v.erase(v.begin());
//
//	// ��ȡ���� for ѭ��
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << "\t";// Խ�����崻�
//	}
//	cout << endl;
//	//
//	//for (int i = 0; i < v.size(); i++)
//	//{
//	//	cout << v.at(i) << "\t"; // Խ�����쳣 out_of_range
//	//}
//	//cout << endl;
//
//	//// ͨ��������
//	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	//{
//	//	cout << *it << "\t"; // Խ�����쳣 out_of_range
//	//}
//	cout << endl;
//
//	getchar();
//}


// stack ջ�� �Ƚ���� (��������)
//void main(){
//	stack<int> s;
//
//	// ѹջ ��ѹ��ָ��λ��
//	s.push(12);
//	s.push(22);
//	s.push(32);
//
//	// �����ܹ�ͨ���Ǳ�ȥ�����ȡֵ������ڿ����Ĺ����������ȷ��Ҫͨ���Ǳ�ȥ��ȡֵ����Ҫ�Զ���
//	
//	/*for (int i = 0; i < s.size(); i++)
//	{
//		cout << s. << endl;
//	}*/
//	
//
//	// ������Ҳû�У�����֧��ѭ���� ���ǵ�ѭ��
//	
//	/*for (stack<int>::iterator it; i < s.size(); i++)
//	{
//		cout << s.pop << endl;
//	}*/
//	
//
//	int top = s.top();
//
//	cout << top << endl;
//
//	// ����ջ��
//	s.pop();
//
//	top = s.top();
//
//	cout << top << endl;
//	
//
//	while (!s.empty())
//	{
//		int top = s.top();
//		cout << top << endl;
//		s.pop();
//	}
//
//	getchar();
//}


// queue ���� (��������)
//void main(){
//
//	queue<int> q;
//
//	q.push(12);
//	q.push(44);
//	q.push(32);
//
//	
//	q.front() = 42;
//
//	cout << q.front() << endl;
//
//	q.pop();
//
//	cout << q.front() << endl;
//	
//	// ����������
//	int back = q.back();
//	cout << back << endl;
//	
//
//	while (!q.empty())
//	{
//		cout << q.front() << endl;
//		q.pop();
//	}
//
//	getchar();
//}


// ���ȼ����� (���ݽṹ ���飬����ķ�ʽ������) 
//void main(){
//
//	// int ��ŵ����� vector<int> �������ͣ����飩 greater �Ӵ�С less ��С����
//	priority_queue<int,vector<int>,less<int>> pq;
//	pq.push(12);
//	pq.push(44);
//	pq.push(32);
//	pq.push(9);
//	pq.push(10);
//
//	// ���ֵ 
//	cout << pq.top() << endl;
//
//	getchar();
//}

// list ����, ˫������(��û�лػ�)
//void main(){
//
//	list<int> l;
//
//	// ����
//	l.push_front(11);
//	l.push_back(22);
//	l.insert(l.begin(),10);
//
//	//10 11  22 
//	// �޸�
//	l.back() = 33; //10 11  33
//	l.front() = 44; //44 11  33
//
//	// ����ͨ���Ǳ�ȥ���ʣ�Ҳ����ȥ�޸�
//
//	// �Ƴ�
//	/*l.erase(l.begin());
//	l.pop_front();
//	l.pop_back();*/
//	
//	// ѭ��
//	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
//	{
//		cout << *it << endl;
//	}
//
//
//	getchar();
//}


class Student
{
public:
	string name;
	int grade;

public:
	Student(string name, int grade){
		this->name = name;
		this->grade = grade;
	}
};

// ν�ʣ�����ν�ʣ� �������ض��Ĺ�������д�ĺ���ν�� 
//bool compare(const Student& _Left, const Student& _Right){
//	return _Left.grade > _Right.grade;
//}

// �������� �º���
struct comparefuction
{
	// ���������� () ��������������󣬷º���
	bool operator()(const Student& _Left, const Student& _Right) const{
		return _Left.grade > _Right.grade;
	}
};

// ������������ ��������������
//void main(){
//	set<Student, comparefuction> s;
//
//	Student s1("Darren1", 2);
//	Student s2("Darren2", 9);
//	Student s3("Darren3", 5);
//
//	s.insert(s1);
//	s.insert(s2);
//	s.insert(s3);
//
//	for (set<Student>::iterator it = s.begin(); it != s.end(); it++)
//	{
//		cout << it->name.c_str() << "," << it->grade << endl;
//	}
//
//	getchar();
//}


// set ������������ṹ�� ��������������ݽ������򣬵��ǲ�����Ԫ����ͬ
//void main(){
//	// set<int,less<int>> s;// ��С�������� ��Ĭ�Ͼ��� less
//	set<int, greater<int>> s;
//
//	// ��Ӳ��� , ����Ҫ�õ�������Ҳ����Ҫָ��λ�� 
//	s.insert(3);
//	s.insert(5);
//	s.insert(4);
//
//	// �ظ��Ĳ��룬�����ᱨ����������ֵ �����������λ�� ���Ƿ�����
//	pair<set<int, greater<int>>::iterator, bool> res = s.insert(5);
//	// res.first; ��ȡ��һ������
//	bool insert_succeed = res.second;
//	if (insert_succeed){
//		cout << "����ɹ�" << endl;
//	}
//	else{
//		cout << "����ʧ��" << endl;
//	}
//
//	// int count = s.count(5);
//	// s.find();
//
//
//	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
//	{
//		cout << *it << endl;
//	}
//
//	getchar();
//}


// multiset���� , �����ظ� ���÷��� set һ��
void main(){
	// set<int,less<int>> s;// ��С�������� ��Ĭ�Ͼ��� less
	multiset<int, greater<int>> ms;

	// ��Ӳ��� , ����Ҫ�õ�������Ҳ����Ҫָ��λ�� 
	ms.insert(3);
	ms.insert(5);
	ms.insert(4);
	ms.insert(4);
	ms.insert(3);

	for (set<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << endl;
	}

	getchar();
}

// 2 �ο� �� ʵս ���п���ɨ�� ������ʶ��  20 �����ݽṹ 
// ˼·��opencv

// ��Ƶ��Grace 2746186102
// QQȺ��546270670




