#include <stdio.h>

// ����ָ��Ͷ༶ָ��
//void main(){
//
//	int num = 12;
//	// int* ָ��  & ȡ��ַ
//	int* p = &num;
//
//	int** s_p = &p;// ��һ��ָ��ȡ��ַ
//
//	// int*** s_s_p = &s_p; // �༶ָ��
//
//	printf("p ��ֵ�ǣ�%p��s_p ��ֵ�ǣ�%p",p,s_p);//s_p ��ַ�� 0x0023FE34 ������ֵ�� 0023fe40 
//	// 0023fe40 ���� p �ĵ�ַ��������ֵ�� 12
//
//	// ͨ������ָ����ô��ȡ���յ�ֵ��s_p ��*����ȡֵ��
//	printf("��ȡ���յ�ֵ�ǣ�%d", **s_p);
//
//	getchar();// ��ͣ
//
//
//}


// ����������ָ�� (�ص�)
//void main(){
//	// ��������
//	int arr[] = {1,2,3,4};
//	
//	//// ��������, linux ��������
//	//for (int i = 0; i < 4;i++){
//	//	printf("%d\n",arr[i]);
//	//}
//	//// forѭ���� c �� C++ �е���ȷд��
//	//int i = 0;
//	//for (; i < 4; i++){
//	//	printf("%d\n", arr[i]);
//	//}
//
//	// ��һ������: arr ��ֵ = arr ȥ��ַ��ֵ ��arr ��ַ��ֵ = arr[0]�ĵ�ַ��ֵ���׵�ַ��
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
//	// ��λ�ȡ�����ָ��
//	int* arr_p = &arr[0];// ����ָ��ָ�����������׵�ַ
//	
//	// ��һϵ�еĲ���
//	printf("%d\n",*arr_p);
//	printf("arr_p= %p\n", arr_p);
//
//	// ��ָ����� ++ 
//	arr_p++;
//
//	printf("%d\n", *arr_p);
//
//	// ָ���������߶���λ
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

// ����ָ���������ѭ����ֵ
//void main(){
//	
//	int arr[] = {1,2,3,4};
//
//	int* arr_p = arr;
//
//	int i = 0;
//	for (; i < 4;i++){
//		printf("λ��%d��ֵ�ǣ�%d\n", i, *(arr_p+i));
//	}
//
//	getchar();
//}


//void main(){
//
//	int arr[4];// ָ������[4]
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
//		printf("λ��%d��ֵ�ǣ�%d\n", i, arr[i]);
//	}
//
//	getchar();
//}


// ����ָ������ļ��ַ�ʽ
//void main(){
//
//	int arr[] = { 1, 2, 3, 4 };
//
//	int* arr_p = arr;
//
//	int i = 0;
//	for (; i < 4; i++){
//		printf("λ��%d��ֵ�ǣ�%d\n", i, arr_p[i]);// == *(arr_p+i)
//		// printf("λ��%d��ֵ�ǣ�%d\n", i, *(arr + i));
//	}
//
//	getchar();
//}
//
//
//// ָ��ΪʲôҪ������? ָ����ʵ����һ���ַ��������ֵ�����
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
//	// ȡֵ��ʱ����Ҫ֪����ôȡ,ָ���ƫ��
//
//	getchar();
//}


// ����ָ�루�ص���
void add(int num1,int num2){
	printf("num1 + num2 = %d\n",(num1+num2));
}

void mins(int num1, int num2){
	printf("num1 - num2 = %d\n", (num1 - num2));
}
// ����ָ�룬�������� 
void opreate(void(method)(int,int),int num1,int num2){
	method(num1, num2);
}
//void main(){
//	
//	// add(1,2);
//
//	// ����ָ����ô���壿�����ķ���(*����������)(�����Ĳ���)
//	opreate(add, 1, 2);
//	opreate(mins, 1, 2);
//
//	getchar();
//}


// ��������ѹ���ص�
void call_back(int current,int total){
	printf("ѹ���Ľ����ǣ�%d/%d",current,total);
}

// ������� 3 ������һ��������ļ��� 
void compress(char* file_name,void(*callback)(int,int)){
	callback(12,24);
}


//void main(){
//	
//
//	void(*call)(int, int);// ������һ������
//	call = call_back;// ������ָ�븳ֵ
//
//	// call(1,2);// ͨ������ָ���ӵĵ���call_back
//	compress("1.png", call);
//
//	getchar();
//}
