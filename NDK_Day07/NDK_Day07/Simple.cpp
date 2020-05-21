#include <stdio.h>

// 二级指针和多级指针
//void main(){
//
//	int num = 12;
//	// int* 指针  & 取地址
//	int* p = &num;
//
//	int** s_p = &p;// 对一级指针取地址
//
//	// int*** s_s_p = &s_p; // 多级指针
//
//	printf("p 的值是：%p，s_p 的值是：%p",p,s_p);//s_p 地址是 0x0023FE34 上面存的值是 0023fe40 
//	// 0023fe40 就是 p 的地址，上面存的值是 12
//
//	// 通过二级指针怎么获取最终的值？s_p （*代表取值）
//	printf("获取最终的值是：%d", **s_p);
//
//	getchar();// 暂停
//
//
//}


// 数组与数组指针 (重点)
//void main(){
//	// 定义数组
//	int arr[] = {1,2,3,4};
//	
//	//// 遍历数组, linux 就有问题
//	//for (int i = 0; i < 4;i++){
//	//	printf("%d\n",arr[i]);
//	//}
//	//// for循环在 c 和 C++ 中的正确写法
//	//int i = 0;
//	//for (; i < 4; i++){
//	//	printf("%d\n", arr[i]);
//	//}
//
//	// 看一种现象: arr 的值 = arr 去地址的值 ，arr 地址的值 = arr[0]的地址的值（首地址）
//	printf("arr = %p\n", arr);
//
//	printf("arr& = %p\n", &arr);
//	printf("arr[0]& = %p\n", &arr[0]);
//
//
//	printf("arr+1 = %p\n", arr+1);
//	printf("&arr+1= %p\n", &arr+1);
//
//	
//	int(*p)[4] = &arr;
//	printf("p= %p\n", p);
//	printf("p+1= %p\n", p+1);
//
//	printf("&p= %p\n", &p);
//
//	// 如何获取数组的指针
//	int* arr_p = &arr[0];// 数组指针指向的是数组的首地址
//	
//	// 做一系列的操作
//	printf("%d\n",*arr_p);
//	printf("arr_p= %p\n", arr_p);
//
//	// 对指针进行 ++ 
//	arr_p++;
//
//	printf("%d\n", *arr_p);
//
//	// 指针再往后逻动两位
//	arr_p += 2;
//
//	printf("%d\n", *arr_p);
//
//	getchar();
//}
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//
//	int *p = &a[2];
//	printf("%d\n", p[-2]);
//	printf("%d\n", *(p - 2));
//	getchar();
//	return 0;
//}


void main(){
	int a[3] = { 1, 2, 3 };
	int b[3] = { 4,5, 6};
	int c[3] = { 7, 8, 9};
	
	int matrix[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	int * p = matrix[3];
	printf("matrix%p\n", matrix);
	printf("matrix+1%p\n", matrix+1);
	//int(*p)[3] = matrix + 1;
	int* p2 = matrix[1];
	printf("matrix[1]%p\n", matrix[1]);

	getchar();
}


//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	printf("%p\n", a);
//	int *ptr = (int *)(&a + 1);
//	printf("%p\n", ptr-1);
//
//	printf("%d %d\n", *(a + 1), *(ptr - 1));
//	getchar();
//	return 0;
//}

// 采用指针遍历数组循环赋值
//void main(){
//	
//	int arr[] = {1,2,3,4};
//
//	int* arr_p = arr;
//
//	int i = 0;
//	for (; i < 4;i++){
//		printf("位置%d的值是：%d\n", i, *(arr_p+i));
//	}
//
//	getchar();
//}


//void main(){
//
//	int arr[4];// 指定数组[4]
//
//	int* arr_p = arr;
//
//	int i = 0;
//	for (; i < 4; i++){
//		// ? 
//		*(arr_p + i) = i;
//	}
//
//	i = 0;
//	for (; i < 4; i++){
//		printf("位置%d的值是：%d\n", i, arr[i]);
//	}
//
//	getchar();
//}


// 数组指针操作的几种方式
//void main(){
//
//	int arr[] = { 1, 2, 3, 4 };
//
//	int* arr_p = arr;
//
//	int i = 0;
//	for (; i < 4; i++){
//		printf("位置%d的值是：%d\n", i, arr_p[i]);// == *(arr_p+i)
//		// printf("位置%d的值是：%d\n", i, *(arr + i));
//	}
//
//	getchar();
//}
//
//
//// 指针为什么要有类型? 指针其实就是一块地址而且他的值都差不多
//void main(){
//
//	int num = 12;
//
//	int* num_p = &num;
//
//	printf("%p",num_p);
//
//	// double* num_p_d = num_p;
//
//	// 取值的时候我要知道怎么取,指针的偏移
//
//	getchar();
//}


// 函数指针（回调）
void add(int num1,int num2){
	printf("num1 + num2 = %d\n",(num1+num2));
}

void mins(int num1, int num2){
	printf("num1 - num2 = %d\n", (num1 - num2));
}
// 方法指针，传两个数 
void opreate(void(method)(int,int),int num1,int num2){
	method(num1, num2);
}
//void main(){
//	
//	// add(1,2);
//
//	// 方法指针怎么定义？方法的返回(*方法的名称)(方法的参数)
//	opreate(add, 1, 2);
//	opreate(mins, 1, 2);
//
//	getchar();
//}


// 监听数据压缩回调
void call_back(int current,int total){
	printf("压缩的进度是：%d/%d",current,total);
}

// 这个方法 3 ，他是一个额外的文件了 
void compress(char* file_name,void(*callback)(int,int)){
	callback(12,24);
}


//void main(){
//	
//
//	void(*call)(int, int);// 声明了一个函数
//	call = call_back;// 给函数指针赋值
//
//	// call(1,2);// 通过函数指针间接的调用call_back
//	compress("1.png", call);
//
//	getchar();
//}
