#include <stdio.h>// ����ͷ�ļ� ���Ƿ��������� .h .hpp ���涼�Ƿ�����������.cpp ��c++�� .c  ���Ƿ�����ʵ�� 
/*void main(){// �����������
	printf("Hello World!");// printf C�Ĵ�ӡ���

	getchar();
}*/

// ������������
/*void main(){
	int i = 100;
	double d = 200;
	float f = 200;
	long l = 100;
	short s = 100;
	char c = 'D';
	// �ַ��� char*

	// �����ӡ ,Ҫ��ռλ��
	printf("i��ֵ�ǣ�%d\n",i);
	printf("d��ֵ�ǣ�%lf\n", d);
	printf("f��ֵ�ǣ�%f\n", f);
	printf("l��ֵ�ǣ�%ld\n", l);
	printf("s��ֵ�ǣ�%d\n", s);
	printf("c��ֵ�ǣ�%c", c);

	getchar();

}*/

// �����ĵ�ַ���κε����ݣ������������е�ַ��סַ���ƺţ�
/*void main(){

	int i = 100;
	// &i & ����ȡ�����ĵ�ַ
	// ͨ�� debug �ĵ��ԣ����ǿ��Ը��ݵ�ַȥ��ѯ�õ�ַ������ int 4�ֽ� sizeof() ��ȡ����������ռ���ֽ���
	printf("i �ĵ�ַ�ǣ�%p", &i);

	getchar();
}

void main(){
	
	printf("int ����������ռ���ֽ�����%d\n",sizeof(int));// 4
	printf("double ����������ռ���ֽ�����%d\n", sizeof(double));// 8
	printf("char ����������ռ���ֽ�����%d\n", sizeof(char));// 1

	getchar();
}

// ָ������ͻ�ȡ��ַ��ֵ
void main(){
	
	int i = 100;
	double d = 200;

	printf("i��ֵ�ǣ�%d\n",i);
	// ͨ�� * ��ȡ��ַ��ֵ
	printf("i��ֵ�ǣ�%d\n",*(&i));

	// ָ��(��ַ)���� ָ���ţ�ָ�򣩵ľ��Ǳ����ĵ�ַ
	// int* ������� int���͵�ָ�루��ַ��
	int* p = &i;
	// double* p1 = &d;
	printf("i��ֵ�ǣ�%d\n", *p);

	getchar();
}

// ͨ��ָ���޸�ֵ 
void main(){

	int i = 100;

	int* p = &i;

	i = 200;

	printf("i��ֵ�ǣ�%d\n",i);

	// ����һ�ַ�ʽ����ȡָ���ֵ���м�ӵ��޸� 
	*p = 300;
	printf("i��ֵ�ǣ�%d", i);

	getchar();
}*/

/*void change(int i){// ��� i ������һ��
	printf("change ��i�ĵ�ַ�ǣ�%p\n",&i);
	i = 200;
}
// ͨ����ַ���޸�
void change(int* p){
	printf("change��i�ĵ�ַ�ǣ�%p\n",p);
	*p = 200;
}

// ͨ�������޸�ֵ
void main(){
	int i = 100;
	printf("i�ĵ�ַ�ǣ�%p\n", &i);
	printf("i��ֵ�ǣ�%d\n", i);

	change(&i);

	printf("i�޸ĺ��ֵ�ǣ�%d\n", i);
	getchar();
}
*/
// ��Ŀ��д������������ֵ���н��� 
void change(int* a,int* b){ // 2 �����⣺�� a,b ����ֵ���н��������ǲ����ٶ�����ڴ棨�������м������ 
	// �����������д
	int temp = *a;
	
	*a = *b;// a��ֵ = b ��ֵ 

	*b = temp;
}
/*
void main(){
	int a = 100;
	int b = 200;
	// ����
	// change(&a,&b);

	a = a + b;// a = 300 
	//a = a - b;
	b = a - b;// b = 200 
	a = a - b;// a = 100 
	

	printf("�ͽ�����ab��ֵ�ֱ��ǣ�%d,%d",a,b);

	getchar();
}
*/
/*
void main(){
	int a = 100;
	int b = 200;

	// a = b ��b������ֵ���Ƹ�a
	printf("a,b�ĵ�ַ�ֱ��ǣ�%p,%p\n",&a,&b);

	int* p1 = &a;// p1 ��һ����������
	int* p2 = &b;

	// p1 = p2 ��ʲô��˼���е������� a = b ��p1 �� p2 ֻ��һ���������ѣ�
	p1 = p2;// ֻ��p1 �ı������ˣ���û�иĶ� a �ĵ�ַ

	printf("a,b�ĵ�ַ�ֱ��ǣ�%p,%p\n", &a, &b);
	getchar();
}
*/
















