#include <stdio.h>
#include <string.h>
#include <malloc.h>

//struct Worker{// ����һ���ṹ�壬�൱�� java �� class
//	char name[10];
//	int age;
//	double salary;
//};

// �ڶ��ַ�ʽ������ֱ��ȡ����
//struct Worker{// ����һ���ṹ�壬�൱�� java �� class
//	char name[10];
//	int age;
//	double salary;
//}darren = {"Darren",23,1000}, jack; // ���ַ�ʽ����һ��Ĭ�ϳ�ʼֵ




// 1. �ṹ��Ķ����ʹ��
// char* ��������������� 
//void main(){
//
//	// struct Worker worker;// ��ʼ�� , û�г�ʼ��������£���ô�������е����Զ���û�г�ʼֵ��
//
//	// ��ֵ
//	// worker.age = 24;
//	// worker.name = "Darren";
//	// strcpy_s(worker.name,"Jack");
//
//	// jack.name = "Jack";
//	// strcpy_s(jack.name, "Jack"); ""
//	//jack.age = 24;
//
//	//printf("name = %s, age = %d, salary = %lf", darren.name, darren.age, darren.salary);
//
//
//	getchar();
//}

struct Work{
	char name[10];
	char grade[10];
};

// �����ַ�ʽ���ṹ��Ƕ��
//struct Worker{// ����һ���ṹ�壬�൱�� java �� class
//	char name[10];
//	int age;
//	double salary;
//
//	// ������ name grade
//	//Work work;
//};

// �����ַ�ʽ���ṹ��Ƕ��
//struct Worker{// ����һ���ṹ�壬�൱�� java �� class
//	char name[10];
//	int age;
//	double salary;
//
//	struct Work{
//		char name[10];
//		char grade[10];
//	}work;
//
//	// ������ name grade
//	// Work work;
//};

//void main(){
//	struct Worker worker = { "Darren", 23, 1000, {"Android","�м�"} };// Ƕ�׵ĳ�ʼ
//
//	printf("name = %s, grade = %s", worker.work.name, worker.work.grade);
//
//
//	getchar();
//}


// 2. �ṹ��ָ��Ͷ�̬�ڴ濪��
//void main(){
//
//	struct Worker worker = {"Darren",23};
//	Worker* worker_p = &worker;
//
//	// ͨ���ṹ��ָ��ȥ��������
//	// worker.age = 24;
//	worker_p->age = 24;// �ṹ�����������һ�ַ�ʽ��һ�����ֱȽϳ���
//	strcpy_s(worker_p->name,"Jack");
//
//	printf("name = %s, age = %d", worker_p->name, worker_p->age);
//
//	getchar();
//
//}



//struct Worker{// ����һ���ṹ�壬�൱�� java �� class
//	char name[10];
//	int age;
//	double salary;
//	// ������ name grade
//	// Work work;
//};

//void main(){
//	// Worker* worker;// ������һ���ṹ��ָ�� , ָ��û�г�ʼ����
//	Worker* worker = (Worker*)malloc(sizeof(Worker));
//	worker->age = 24;
//	strcpy_s(worker->name, "Jack");
//
//	printf("name = %s, age = %d", worker->name, worker->age);
//
//	// �ͷ�
//	if (worker){
//		free(worker);
//		worker = NULL;
//	}
//	
//	getchar();
//}



//struct Worker{// ����һ���ṹ�壬�൱�� java �� class
//	char name[10];
//	int age;
//	double salary;
//};

// �ṹ�������
//void main(){
//	// �����ṹ�����飬��һ��
//	 //Worker worker[10] = { {"Darren",23,1000},{},{},{},{} };// ������ 10 �� ����̬����
//
//	 //worker[9] = {"Darren9",24,200};
//
//	 //printf("name = %s, age = %d\n", worker[9].name, worker[9].age);
//
//	// ��̬�ڴ濪�� Worker* �ṹ���ָ��
//	Worker* worker = (Worker*)malloc(sizeof(Worker)*10);
//
//	strcpy_s(worker->name,"Darren0");
//	worker->age = 10;
//
//	// �Ե�ʮ�����ݽ��в�����
//	worker += 9;
//	strcpy_s(worker->name, "Darren9");
//	worker->age = 9;
//
//
//	printf("name = %s, age = %d", worker->name, worker->age);
//
//	getchar();
//}


// 3. �ṹ���С���㣨�ֽڶ��룩
struct Worker{// ����һ���ṹ�壬�൱�� java �� class
	
	int age; // 4
	double salary;// 8
	char name; // 1
	
	// char name[10] 24 ��char name[18] 32
	// 32 ��ô���ģ� 18 + 4 +8 = 30 ��32
};

void main(){

	int size = sizeof(Worker);// 16 �ֽ�
	// ����Ĺ���
	// 1. ���������ֽ�ȥ���� 
	// 2. ���ʱ��ֻ�ᰴ�ջ�����������ȥ��
	// 3. ���Ȼ�������ֽ������������Ƿ��ܹ�����������Ե��ֽ������������Ϊ�����ۼӣ�һֱ�ӵ�������λ��

	printf("size = %d", size);

	getchar();
}



struct date{ // 12
	int year;
	int month;
	int day;
};

struct student{
	int number;// 4
	char sex;// 1
	int age;// 4
	char name[10];// 10 
	//struct date birthday;// 12

	// 31%4  32%4  32�ֽڣ� 
};

//void main(){
//
//	int size = sizeof(student);// 36 �ֽ�
//	// ����Ĺ���
//	// 1. ���������ֽ�ȥ���� 
//	// 2. ���ʱ��ֻ�ᰴ�ջ�����������ȥ��
//	// 3. ���Ȼ�������ֽ������������Ƿ��ܹ�����������Ե��ֽ������������Ϊ�����ۼӣ�һֱ�ӵ�������λ��
//	// 4. ���ף���һ��˼��
//
//	printf("size = %d", size);
//
//	getchar();
//}


// 4. �ṹ��ͽṹ��ָ��ȡ����
//struct Worker_{// ����һ���ṹ�壬�൱�� java �� class
//	char name[10];
//	int age;
//	double salary;
//};
//
//typedef Worker_ Worker_;
//// �Խṹ���ָ��ȡ����
//typedef Worker_* Worker;

//void main(){
//	Worker worker = (Worker_*)malloc(sizeof(Worker_));
//
//	printf("%s,%d,%lf",worker->name,worker->age,worker->salary);
//
//	getchar();
//}


// ������һ�� ������
union Person
{
	// ���ܳ���һ�� �������ۼӣ������ֵ 10��12�ֽ�
	char name[10]; // 10 
	int age; // 4 
	double salary;// 8
};

// 5. ������Ķ����ʹ�ã�������ֻ�ܴ���һ����Ҫô�� age ��Ҫô�� name 
//void main(){
//
//	//Person person = {"Darren"};
//	 Person person;
//	
//	 strcpy_s(person.name,"Darren");
//	 person.age = 24;
//	
//	 printf("name = %s,age = %d\n",person.name,person.age);
//	printf("%d", sizeof(Person));
//
//	getchar();
//}


// 6. �������С���� �������ۼӣ�ȡ�����ֵ�������Ƿ񹻻�����������������

// 7. ö�ٵĶ����ʹ�� ö���е������� int
enum CommentType
{
	TEXT = 10,TEXT_IMAGE,IMAGE
};

//void main(){
//
//	CommentType commentType = TEXT;
//	CommentType commentType1 = TEXT_IMAGE;
//	CommentType commentType2 = IMAGE;
//	
//	printf("%d,%d,%d", commentType, commentType1, commentType2);
//
//	getchar();
//}

