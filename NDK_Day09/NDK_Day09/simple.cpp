#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//void main(){
//	printf("Hello World!");// �����ÿ���������һ��
//	getchar();
//}

/*
// �ַ�������
void main(){

	// ��һ�� �ַ�������
	char str[] = {'D','a','r','r','e','n','\0'};

	str[2] = 'y';

	printf("%s\n",str);// �ַ�����β�� '\0'

	// �ڶ���
	char *str1 = "Darren";

	str1[2] = 'y';

	printf("%s", str1);

	// ����һ�����޸�һ�������޸�

	getchar();

}


int strlen_(char *str){
	// ��ô��ȡ�ַ����ĳ��ȣ� ���϶�ȡ�ַ����ж�ĩβ '\0'

	int len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}

// �ַ������Ȼ�ȡ
void main(){

	char *name = "Darren is";

	char str[] = { 'D', 'a', 'r', 'r', 'e', 'n', '\0','i','s' };

	// ��ô��ȡ���ȣ���һ�ַ�ʽ���㣨����ʹ��
	// printf("length is %d",sizeof(str)/sizeof(char));


	printf("name length is %d\n", strlen(str));

	// �Լ���дһ��������ȡ�ַ����ĳ���
	// strlen_(name);
	printf("name length is %d", strlen_(str));

	getchar();
}


// �ַ�����ת��
void main(){

	// char * num = "1"; -> int float double
	// char *num_str = "12.0xxx";
	// int number = atoi(num_str);// �������ת������ 0 ����������������������ֵľͻᱻ�޳� 12xxx -> 12

	// char *num_str = "12.5f";
	// float number = atof(num_str);// �������ת�����ص���Ĭ��ֵ 0.000000 

	char *num_str = "12.5xx";
	double number = strtod(num_str, NULL);

	printf("number is %lf",number);
	getchar();
}

// �ַ����ıȽ�
void main(){

	char* str1 = "Darren is";
	char* str2 = "darren";

	// ����С�ڵ��� 
	// int rc = strcmp(str1, str2);// ���ִ�Сд�Ƚ�
	// int rc = _strcmpi(str1, str2);// c strcmpi c++ _strcmpi , andrroid ndk strcasecmp

	// �Ƚ�ǰ����
	// int rc = strncmp(str1, str2,7);// count ������ǱȽ��ַ���ǰ�����Ƿ����
	int rc = _strnicmp(str1, str2, 6);
	if (rc == 0){
		printf("���");
	}
	else{
		printf("�����");
	}

	getchar();
}*/

// �ַ������ң�����
//void main(){
//	
//	char* str = "name is Darren";
//	char *substr = "D";
//	char* pos = strstr(str, substr);// ���ص����ַ�����һ�γ��ֵ�λ�ã�λ��ָ�룩, ���û���ҵ����ص��ǿ�
//	// ��һ��λ�� int ��ô�죿 strstr 
//	 int postion = pos - str;
//
//	 printf("��һ�γ��ֵ�λ���ǣ�%d\n",postion);
//
//	// ������pos �ǲ��ǿվͿ�����
//	if (pos){
//		printf("%s", "����");
//	}
//	else{
//		printf("%s", "������");
//	}
//
//	getchar();
//}


// ƴ�ӣ���ȡ����Сдת��
//void main(){
//
//	// strcpy(); copy����
//	char* str = "darren";
//
//	char *str1 = " is";
//
//	// char* str1 = "is";
//	int len = strlen(str);// cpy[len] android studio �ǿ��Ե�
//	char cpy[20];
//
//	// str �� copy �� cpy ����
//	strcpy(cpy, str);
//
//	printf("%s\n",cpy);
//
//	// ƴ��
//	strcat(cpy,str1);
//
//	printf("%s", cpy);
//
//	getchar();
//}


//char * substr(char * str,int start,int end){
//
//	// ����һ���ַ���ȥ�洢���ǵ����ݣ����ٶ�����
//	// char sub[end-start];
//	int len = end - start;
//	char* sub = (char*)malloc(len*sizeof(char)+1);// �ǵü���1 ���� NDK һ�����þ�̬������洢 char sub[len]
//	// malloc һ��Ҫ free 
//
//	// ������ֵ
//	str += start;
//	for (int i = 0; i < len; i++)
//	{
//		sub[i] = *str;
//		str++;// ָ��������һλ 
//	}
//	// ����ַ�����β������ print �޷��жϽ�β
//	sub[len] = '\0';
//
//	printf("%p\n",sub);
//
//	// free(sub);
//
//	return sub;
//}

// �ַ����Ľ�ȡ
//void main(){
//
//	char *str = "Darren is";
//	
//	// ��ȡ������λ�õ������λ�� 3��5
//	char *sub = substr(str,0,5);
//
//	printf("%p\n", sub);
//
//	printf("%s",sub);
//
//	// һ��Ҫ free ����Ϊ��� substr �ж�̬�����ڴ棬�����������������в�������ô�����Լ��ķ�������Ҫ�Լ�������ڴ�
//	free(sub);
//
//	getchar();
//}


// dest ������Ž������С�Լ�ָ��
// source ��Ҫת�����ַ���
void lower(char* dest,char* source){
	while (*source != '\0'){
		// �õ�ǰ�ַ�
		char ch = *source;
		// ת�긳ֵ�� dest
		*dest = tolower(ch);// a -> a A -> a
		// ����ָ�� ++ ��������һ��
		source++;
		dest++;
	}
	// ����ַ�����β
	*dest = '\0';
}

// ��Сдת��
void main(){
	char* name = "daRRen";
	char dest[20];

	lower(dest,name);

	printf("%s",dest);

	getchar();
}


// С����ҵ ��strcmp ʵ��һ�顣ʵ�ִ�дת�����ַ����滻(�´ο�)
// aabbaabbaabb aa ���滻�� cc 