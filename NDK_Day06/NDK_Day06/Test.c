#include <stdio.h>

int main(void)
{
	
		const int number = 10;

		// number = 20;

		int* numberP = &number;// 不能通过地址去修改值，但是某些编译器上面能通过，但是也不能修改值
		// c 是能够修改的，在 c 中可以说是一个伪命题

		*numberP = 20;

		printf("%d", number);

		getchar();
	
	
	//char* a = "abc";
	//char*  b = "def";
	//char* c = "ghi";
	////char *arr[3] = { "abc", "def", "ghdi" };
	//char *arr[3] = { a, b, c };
	//char *pArr = arr[0];

	//printf("地址是：%p\n", a);
	//printf("地址是：%s\n", a);

	//printf("地址是：%p\n", a+1);

	//printf("地址是：%p\n", arr);
	//printf("地址是：%p\n", arr+1);
	//printf("地址是：%p\n", arr + 2);

	//printf("字符串数组arr的每个字符串元素是:  ");
	//for (int index = 0; index < 3; index++)
	//{
	//	printf("%s ", a);
	//}

	//printf("\n");
	//printf("字符串数组arr第一个字符串的每个元素是:  ");
	//for (int index = 0; index < 3; index++)
	//{
	//	printf("%c ", *(pArr + index));
	//	printf("%p ", pArr + index);

	//}

	printf("\n");
	getchar();
	return 0;
}