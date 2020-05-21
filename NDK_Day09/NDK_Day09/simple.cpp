#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//void main(){
//	printf("Hello World!");// 把这堂课内容再敲一遍
//	getchar();
//}

/*
// 字符串定义
void main(){

	// 第一种 字符串数组
	char str[] = {'D','a','r','r','e','n','\0'};

	str[2] = 'y';

	printf("%s\n",str);// 字符串结尾是 '\0'

	// 第二种
	char *str1 = "Darren";

	str1[2] = 'y';

	printf("%s", str1);

	// 区别，一个能修改一个不能修改

	getchar();

}


int strlen_(char *str){
	// 怎么获取字符串的长度？ 不断读取字符，判断末尾 '\0'

	int len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}

// 字符串长度获取
void main(){

	char *name = "Darren is";

	char str[] = { 'D', 'a', 'r', 'r', 'e', 'n', '\0','i','s' };

	// 怎么获取长度？有一种方式计算（不好使）
	// printf("length is %d",sizeof(str)/sizeof(char));


	printf("name length is %d\n", strlen(str));

	// 自己来写一个方法读取字符串的长度
	// strlen_(name);
	printf("name length is %d", strlen_(str));

	getchar();
}


// 字符串的转换
void main(){

	// char * num = "1"; -> int float double
	// char *num_str = "12.0xxx";
	// int number = atoi(num_str);// 如果不能转换就是 0 ，后面如果有其他不是数字的就会被剔除 12xxx -> 12

	// char *num_str = "12.5f";
	// float number = atof(num_str);// 如果不能转换返回的是默认值 0.000000 

	char *num_str = "12.5xx";
	double number = strtod(num_str, NULL);

	printf("number is %lf",number);
	getchar();
}

// 字符串的比较
void main(){

	char* str1 = "Darren is";
	char* str2 = "darren";

	// 大于小于等于 
	// int rc = strcmp(str1, str2);// 区分大小写比较
	// int rc = _strcmpi(str1, str2);// c strcmpi c++ _strcmpi , andrroid ndk strcasecmp

	// 比较前几个
	// int rc = strncmp(str1, str2,7);// count 代表的是比较字符串前几个是否相等
	int rc = _strnicmp(str1, str2, 6);
	if (rc == 0){
		printf("相等");
	}
	else{
		printf("不相等");
	}

	getchar();
}*/

// 字符串查找，包含
//void main(){
//	
//	char* str = "name is Darren";
//	char *substr = "D";
//	char* pos = strstr(str, substr);// 返回的是字符串第一次出现的位置（位置指针）, 如果没有找到返回的是空
//	// 求一下位置 int 怎么办？ strstr 
//	 int postion = pos - str;
//
//	 printf("第一次出现的位置是：%d\n",postion);
//
//	// 包含？pos 是不是空就可以了
//	if (pos){
//		printf("%s", "包含");
//	}
//	else{
//		printf("%s", "不包含");
//	}
//
//	getchar();
//}


// 拼接，截取，大小写转换
//void main(){
//
//	// strcpy(); copy进来
//	char* str = "darren";
//
//	char *str1 = " is";
//
//	// char* str1 = "is";
//	int len = strlen(str);// cpy[len] android studio 是可以的
//	char cpy[20];
//
//	// str 会 copy 到 cpy 里面
//	strcpy(cpy, str);
//
//	printf("%s\n",cpy);
//
//	// 拼接
//	strcat(cpy,str1);
//
//	printf("%s", cpy);
//
//	getchar();
//}


//char * substr(char * str,int start,int end){
//
//	// 开辟一个字符串去存储我们的数据，开辟多大计算
//	// char sub[end-start];
//	int len = end - start;
//	char* sub = (char*)malloc(len*sizeof(char)+1);// 记得加上1 ，在 NDK 一般会采用静态的数组存储 char sub[len]
//	// malloc 一定要 free 
//
//	// 遍历赋值
//	str += start;
//	for (int i = 0; i < len; i++)
//	{
//		sub[i] = *str;
//		str++;// 指针往后逻一位 
//	}
//	// 标记字符串结尾，否则 print 无法判断结尾
//	sub[len] = '\0';
//
//	printf("%p\n",sub);
//
//	// free(sub);
//
//	return sub;
//}

// 字符串的截取
//void main(){
//
//	char *str = "Darren is";
//	
//	// 截取第三个位置到第五个位置 3，5
//	char *sub = substr(str,0,5);
//
//	printf("%p\n", sub);
//
//	printf("%s",sub);
//
//	// 一定要 free ，因为你的 substr 有动态开辟内存，但是真正开发过程中并不会这么做，自己的方法尽量要自己处理好内存
//	free(sub);
//
//	getchar();
//}


// dest 用来存放结果，大小自己指定
// source 需要转换的字符串
void lower(char* dest,char* source){
	while (*source != '\0'){
		// 拿当前字符
		char ch = *source;
		// 转完赋值给 dest
		*dest = tolower(ch);// a -> a A -> a
		// 接着指针 ++ ，遍历下一个
		source++;
		dest++;
	}
	// 标记字符串结尾
	*dest = '\0';
}

// 大小写转换
void main(){
	char* name = "daRRen";
	char dest[20];

	lower(dest,name);

	printf("%s",dest);

	getchar();
}


// 小的作业 ：strcmp 实现一遍。实现大写转换。字符串替换(下次课)
// aabbaabbaabb aa 都替换成 cc 