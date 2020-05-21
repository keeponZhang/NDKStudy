#ifndef STUDENT_H
#define STUDENT_H

class Student{
private:
	int age;
	char* name;
public:
	// ��̬���Ե�����
	static int tag;

public:
	Student();
	Student(char* name);
	Student(char* name,int age);
	// ��������
	~Student();
	// �������캯��
	Student(const Student& stu);

public:
	void setAge(int age);
	void setName(char* name);

	int getAge();
	char* getName();

	void print() const;

	// ��̬����Ԫ
	static void changeTag(int tag);
	friend void changeAge(Student *stu,int age);
};
#endif // STUDENT_H