#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void change1(int number){// �����޸�
	number = 300;
	printf("%p\n",number);
}

void change2(int* number){// ����
	*number = 300;
}

//void main(){
//	
//	int a = 100;
//
//	// �޸� a ��ֵ 
//
//	a = 200;
//	printf("%p\n", &a);
//
//	change1(a);// a������ֵ���Ƹ��� number ���� ��number������һ�������У�number ��һ���µı���
//	printf("a = %d", a);
//
//	change2(&a);// a �ĵ�ַ���Ƹ��� number ���� ��number������һ�������У�number ��һ���µı���
//
//	printf("a = %d",a);// a = 200 ? 
//
//
//	getchar();
//}


void changeNumber(int* number){
	*number = 300;
}

// 2. ָ���Ӹ�ֵ������
//void main(){
//
//	// ͨ��ָ��ȥ�޸�ֵ
//
//	int number = 100;
//
//	// ��ͬһ���������棬ֱ�Ӹ���
//	number = 200;
//
//	// ͨ��ָ��ȥ��ֵ����ʵ����Ϊ��������������ȥ��Ӹ�ֵ
//	// int* p = &number;
//	// *p = 300;
//	changeNumber(&number);
//
//	// ����������ʱ���벻��ָ�룬ָ����ֵ������кܶ࣬����һ�־���ͨ������ȥ�޸�ֵ
//	// 1.��ȡBitmap��Ϣ
//	// AndroidBitmapInfo android_bitmap_info; // �ṹ��
//	// AndroidBitmap_getInfo(env, bitmap, &android_bitmap_info); // ͨ�� getInfo ����ȥ��ȡ Bitmap ������
//	// ��ȡbitmap�� ���ߣ�format
//	// int bitmap_width = android_bitmap_info.width;
//	// int bitmap_height = android_bitmap_info.height;
//
//	// c �� java �ķ�����ͬ���ڣ�c ���Դ�����ĵ�ַ�ڷ�������ȥ��ֵ��java һ�㶼��ͨ������ֵ
//
//	// ģ��һ��ָ�뷽����ֵ��д�����ܳ��ã�
//	// java д��
//	// AndroidBitmapInfo android_bitmap_info = AndroidBitmap_getInfo(env, bitmap);
//	// c ��д��
//	printf("%d",number);
//
//	// �����ڵķ��� 100  60��ҵ���߼� 15�ֿ��ά�� 10��С��Ϸ��ܵ�ά�� 15�ܹ��������Ż� 50fps 60fps �Ż�������� 
//	
//	getchar();
//}

//struct AndroidBitmapInfo
//{
//	int width;
//	int height;
//	int format;
//} info;// ������һ���ṹ�� ���� info



//typedef struct AndroidBitmapInfo
//{
//	int width;
//	int height;
//	int format;
//};// ������һ���ṹ��ȡ��һ������ AndroidBitmapInfo ���ṹ��������� ����
//
//void AndroidBitmap_getInfo(AndroidBitmapInfo* bitmapInfo){
//	// ͨ��ָ���ڷ������渳ֵ
//	bitmapInfo->width = 200;
//	bitmapInfo->height = 200;
//}

// ģ�� AndroidBitmap_getInfo 

//void main(){
//	// ͨ��ָ���Ӹ�ֵ�ܳ���
//	struct AndroidBitmapInfo androidBitmapInfo;
//	AndroidBitmap_getInfo(&androidBitmapInfo);
//
//	printf("width = %d, height = %d",androidBitmapInfo.width,androidBitmapInfo.height);
//
//	getchar();
//}


// Ұָ��Ϳ�����
//typedef struct AndroidBitmapInfo
//{
//	int width;
//	int height;
//	int format;
//};// ������һ���ṹ��ȡ��һ������ AndroidBitmapInfo ���ṹ��������� ����
//
//void AndroidBitmap_getInfo(AndroidBitmapInfo* bitmapInfo){
//	// ͨ��ָ���ڷ������渳ֵ
//	bitmapInfo->width = 200;
//	bitmapInfo->height = 200;
//}

// ģ�� AndroidBitmap_getInfo 
//void main(){
//	// ͨ��ָ���Ӹ�ֵ�ܳ��� (���ڴ��Ͽ���)
//	struct AndroidBitmapInfo *androidBitmapInfo = (AndroidBitmapInfo*)malloc(sizeof(AndroidBitmapInfo));
//	AndroidBitmap_getInfo(androidBitmapInfo);
//
//	printf("width = %d, height = %d", androidBitmapInfo -> width, androidBitmapInfo -> height);
//
//	// �ͷ�
//	if (androidBitmapInfo != NULL){
//		free(androidBitmapInfo);
//		// �������Ұָ�����������ٳ������ĳ���
//		androidBitmapInfo = NULL;
//	}
//
//	// ����ط�д�� n �д��룬ʡ�� n ��
//	// �ٴ��ͷ�,�������� 
//	if (androidBitmapInfo){
//		free(androidBitmapInfo);
//	}
//
//	getchar();
//}

//void main(){
//	// д��λ�� 0x00000000 ʱ�������ʳ�ͻ
//	char* p1 = NULL;// p1 = NULL ��NULL Ҳ�ǵط� ��ָ��ָ�� NULL �൱��ָ�� 0x00000000
//
//	// �������ǲ����ܶ� 0x00000000 ȥ���������ط��� c �� c++ �����������е�
//
//	// Student student = null; û��ȥ���� null ��ɶ���� c �� c++ �е�����
//
//	strcpy(p1,"1122");
//
//	getchar();
//}


// ���ַ�����ǿ��
//void main(){
//	 //char buff[100] = { 'd','a', 'r', 'r', 'e', 'n' };// ���� 6 - 99 ����Ĭ��ֵ 0 
//	 //char buff[6] = { 'd', 'r', 'r', 'e', 'n' };
//	// char buff[] = {'d','r','r','e','n'}; // ������ 12��'\0'�� ��size �� 5 ��Ĭ��ͳ������ĸ�����
//	// char buff[2] = { 'd', 'r', 'r', 'e', 'n' };// ���벻ͨ�������ȳ���
//	// char buff[100] = { 0 };// �������ʼ��Ϊ 0 
//	// char buff[100] ���ݶ���Ĭ��ֵ -52
//
//	 //char buff[] = "123456";// len �� 6 ��'\0'����size �� 7 ��
//	// �൱�� char buff[] = {1��2��3��4��5��6��\0}
//	char* buff = "123456";
//
//	// ����һ�� char buff[] = "123456" �� char* buff = "123456"; malloc �ķ�ʽ  ɶ���� ��
//	// �ַ����������κεط������ڴ棬ջ����������������
//
//	// ��С size 100 
//	int len = strlen(buff);// len 5  ���� '\0' �ͽ�����
//	int size = sizeof(buff);
//
//	printf("len = %d, size = %d\n",len,size);
//
//	// ���� 
//	printf("%d,%d,%d,%d", buff[0], buff[66], buff[99],buff[77]);
//
//	getchar();
//}


// ���һ����ȡ Bitmap ���Եĺ�����������ô��ƣ����ص㣩
// 1. ȷ����Ĳ��� ����ָ��
// 2. һ��Ҫ���ǽ�׳��
// 3. Ҫ�쳣��������׳�˵�� ����Ƶ ffmpeg
// 4. ��Ҫֱ�����׵�ȥ�ı���ô��ݸ����ָ�� ����ȷ�

//struct AndroidBitmapInfo
//{
//	int width;
//	int height;
//	int format;
//};// ������һ���ṹ��ȡ��һ������ AndroidBitmapInfo ���ṹ��������� ����
//
//int AndroidBitmap_getInfo(AndroidBitmapInfo* bitmapInfo){
//
//	// �� bitmapInfo �����ٴθ�ֵ
//
//	//  2. һ��Ҫ���ǽ�׳�� , �Լ��ķ����ᱨ��
//	if (bitmapInfo == NULL){
//		// 3. Ҫ�쳣��������׳�˵�� ����Ƶ ffmpeg
//		printf("bitmapInfo �� NULL �޷����в����������� %d",-1);
//		return -1;
//	}
//	// ���ܻ����� -xx 
//
//	// ͨ��ָ���ڷ������渳ֵ
//	bitmapInfo->width = 200;
//	bitmapInfo->height = 200;
//	return 0;// һ�� 0 �����������
//}

// ģ�� AndroidBitmap_getInfo 
//void main(){
//	// ͨ��ָ���Ӹ�ֵ�ܳ��� (���ڴ��Ͽ���)
//	struct AndroidBitmapInfo *androidBitmapInfo = (AndroidBitmapInfo*)malloc(sizeof(AndroidBitmapInfo));
//
//	// �ͷź��ٵ���
//	int res = AndroidBitmap_getInfo(androidBitmapInfo);
//
//	if (res == 0){
//		// ...
//		// ����� �� ������Ҳ�ᱨ�����Ҳ���֪����������
//		printf("width = %d, height = %d", androidBitmapInfo->width, androidBitmapInfo->height);
//	}
//
//	// �ͷ�
//	if (androidBitmapInfo != NULL){
//		free(androidBitmapInfo);
//		// �������Ұָ�����������ٳ������ĳ���
//		androidBitmapInfo = NULL;
//	}
//
//	getchar();
//}
//
//// 4. ��Ҫֱ�����׵�ȥ�ı���ô��ݸ����ָ�� ����ȷ�
//int strlen( char* const str){
//	// ��ʱ����,��· 
//	char* countStr = str;
//
//	int count = 0;
//	while (*countStr)// != '\0'
//	{
//		countStr++;
//		count++;
//	}
//
//	// �Լ��뿴������Բ���
//	printf("str = %s,len = %d\n",str,count);
//
//	return count;
//}

//void main(){
//	char* str = "123456";
//
//	int len = strlen(str);
//
//	printf("len = %d",len);
//	getchar();
//}

void abc(char** str, int len){
	for (int i = 0; i < len; i ++ ){
		printf("%s\n", str[i]);
	}
}
void bd(char str[10][30], int len){
	for (int i = 0; i < len; i++){
		printf("%s\n", str[i]);
	}
}
void main(){
	//char * name[] = { "keepon", "zhang", "army" };
	//printf("%p,%p,%p\n", name[0], name[1], name[2]);
	//printf("%s,%s,%s\n", name[0], name[1], name[2]);
	char   name2[10][30] = { "keepon", "zhang", "army" };
	
	printf("%p,%p,%p\n", name2, name2+1, name2+2);
	printf("%p,%p,%p\n", name2[0], name2[1], name2[2]);
	printf("%s,%s,%s", name2[0], name2[1], name2[2]);

	/*int number = 3;
	char** params = (char**)malloc(sizeof(char*)*number);
	for (int i= 0; i < number; i++){
		params[i] = (char*)malloc(sizeof(char)* 100);
		sprintf(params[i], "i==%d", i);
	}
	abc(params, number);*/
	getchar();
}


