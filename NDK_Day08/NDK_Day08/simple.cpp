#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <windows.h>

// ���������
/*void main(){
	// �����������ÿ�����У��������һ�£�����ķ�ʽ���ǳ�ʼ��������
	// ��ʼ�����������, ÿ�η��������ǵ�ǰʱ�䣬���£�ʵ�ó������� C ��������Կ����ȫ��
	srand((unsigned)time(NULL));
	int i;
	for (i = 0; i<10; i++)
		printf("%d\n", rand() % 100);
	getchar();
}


void staticlloc(){
	int arr[5];// ��̬���� 0.8M
	int i = 0;
	for (; i < 5; i++)
	{
		arr[i] = i;
		printf("%d, %p\n", *(arr + i), arr + i);
	}
}

// �ص㣬�ڴ濪��
void main(){
	// Stack overflow ջ��� ����ж�һ���ڴ�����û��д�����ݣ��� NULL������Խ��
	// int arr[10*1024*1024];// ռ���ڴ��Ƕ��٣� ��С��10M�����С�� intռ��4�ֽڣ�40M�ռ�

	// c �з���������ģ�ͣ�ջ����
	// ջ��ռ���ڴ�ռ����ֵ 2M �������ڴ�ķ�ʽ�Ǿ�̬�ڴ濪�� int arr[10*1024*1024]�������������Զ�����
	// �ѣ�ռ���ڴ�ռ����ֵ 80% �������ڴ�ķ�ʽ�Ƕ�̬�ڴ濪�� �������Զ����ձ����ֶ����գ��ڴ治��ʹ�õ�ʱ��һ��Ҫ�ֶ����գ�
	while (true)
	{
		Sleep(100);
		staticlloc();
	}
	
	getchar();
}


void dynamiclloc(){
	int* arr = (int*)malloc(1 * 1024 * 1024 * sizeof(int)); // 40M

	// �ڶ�����Ҫ�ķ������ֶ��ͷ� free , �ͷ�arr��һ���ڴ�
	free(arr);
}

// ��̬�ڴ濪��
void main(){
	
	// int arr[10 * 1024 * 1024];
	

	// ����
	while (true)
	{
		Sleep(100);
		dynamiclloc();
	}

	getchar();
}


// ʵ�õĳ���
void main(){
	// ��������������Ҫ�����û������������Ȼ���������
	int num;
	printf("���������ĸ�����");
	// ��ȡ�û������ֵ
	scanf_s("%d",&num);

	// ����һ������������û�������
	// int arr[num]; ��̬���٣��ڴ��С���ܸı�
	int* arr = (int*)malloc(sizeof(int)*num);

	// for ѭ������
	int i = 0;
	int print_num;
	for (; i < num;i++){
		printf("�������%d����ֵ��",i);
		scanf_s("%d", &print_num);
		arr[i] = print_num;// arr[i] = *(arr+i)
		printf("%d, %p\n", *(arr + i), arr + i);
	}

	// ���� ������4��Сʱ����������
	free(arr);

	getchar();
}
*/

// �ı��ڴ�ռ��С
void main(){
	int num;
	printf("���������ĸ�����");
	// ��ȡ�û������ֵ
	scanf_s("%d", &num);

	// 5d ��ֵ
	int* arr = (int*)malloc(sizeof(int)*num);
	int i = 0;
	int print_num;
	for (; i < num; i++){
		arr[i] = i;// arr[i] = *(arr+i)
	}

	printf("�����ڴ��ָ�룺%p\n",arr);

	// �ټӵ��ڴ�
	printf("�����������ĸ�����");
	// ��ȡ�û������ֵ
	int new_num;
	scanf_s("%d", &new_num);// 5 
	// ԭ���ǿ��ڴ��ָ�룬�ܵĴ�С��ԭ���Ĵ�С+�µĴ�С��
	int* new_arr = (int*)realloc(arr, sizeof(int)*(num+new_num));

	if (new_arr){// = if(new_arr != NULL)
	i = new_num;
	for (; i < (num + new_num); i++){
		arr[i] = i;// arr[i] = *(arr+i)
	}

	printf("�¿����ڴ��ָ�룺%p\n", new_arr);

	// ��ӡ����
	i = 0;
	for (; i < num + new_num; i++){
		printf("%d, %p\n", *(arr + i), arr + i);
	}

	}
	if (new_arr){
		// ����ɹ��ˣ�ֻҪ�ͷ��µĵ�ַ����
		free(new_arr);
		new_arr = NULL;
	}
	else{
		// ���û�гɹ����ͷ�ԭ�����ڴ�
		free(arr);
	}

	// ��Ҫ����ȥ�ͷ�,�ǿ��ַһ�����ͷţ����п��ܻᱻ�µ�Ӧ��ռ�ã���Ҫȥ�ٴ��ͷ�
	// free(new_arr);

	// ���� C/C++ ��ͨ 

	getchar();
}