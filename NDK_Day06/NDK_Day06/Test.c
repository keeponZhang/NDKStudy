#include <stdio.h>

int main(void)
{
	
		const int number = 10;

		// number = 20;

		int* numberP = &number;// ����ͨ����ַȥ�޸�ֵ������ĳЩ������������ͨ��������Ҳ�����޸�ֵ
		// c ���ܹ��޸ĵģ��� c �п���˵��һ��α����

		*numberP = 20;

		printf("%d", number);

		getchar();
	
	
	//char* a = "abc";
	//char*  b = "def";
	//char* c = "ghi";
	////char *arr[3] = { "abc", "def", "ghdi" };
	//char *arr[3] = { a, b, c };
	//char *pArr = arr[0];

	//printf("��ַ�ǣ�%p\n", a);
	//printf("��ַ�ǣ�%s\n", a);

	//printf("��ַ�ǣ�%p\n", a+1);

	//printf("��ַ�ǣ�%p\n", arr);
	//printf("��ַ�ǣ�%p\n", arr+1);
	//printf("��ַ�ǣ�%p\n", arr + 2);

	//printf("�ַ�������arr��ÿ���ַ���Ԫ����:  ");
	//for (int index = 0; index < 3; index++)
	//{
	//	printf("%s ", a);
	//}

	//printf("\n");
	//printf("�ַ�������arr��һ���ַ�����ÿ��Ԫ����:  ");
	//for (int index = 0; index < 3; index++)
	//{
	//	printf("%c ", *(pArr + index));
	//	printf("%p ", pArr + index);

	//}

	printf("\n");
	getchar();
	return 0;
}