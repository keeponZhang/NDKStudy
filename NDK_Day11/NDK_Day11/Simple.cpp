#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//void main(){
//	// ���ļ� ���ļ�����ģʽ��mode r(��) w(д) rb(��Ϊ�����ƶ�) wb(��Ϊ������д)
//	// FILE *fopen( const char *filename, const char *mode );
//
//	char* fileName = "F:/config.java";
//
//	FILE *file = fopen(fileName, "r");
//
//	if (!file){
//		printf("�ļ���ʧ��"); 
//			getchar();
//		exit(0);// �˳�����
//	}
//
//	char buffer[10];
//
//	// ������buffer������10 ���ļ�ָ��
//	while (fgets(buffer, 10, file)){
//		printf("%s",buffer);
//	}
//
//	// �ر��ļ�
//	fclose(file);
//
//
//	getchar();
//
//}


//void main(){
//
//	char* fileName = "F:/configq.java";
//
//	FILE *file = fopen(fileName, "w");
//
//	if (!file){
//		printf("�ļ���ʧ��");
//		exit(0);// �˳�����
//	}
//
//	fputs("I am Darren",file);
//
//
//	// �ر��ļ�
//	fclose(file);
//
//
//	getchar();
//}


 //�ļ����ƣ������������ļ�������
//void main(){
//	char* fileName = "F:\\screen0.jpg";
//	char* fileCopyName = "F:\\screen1.jpg";
//
//	FILE *file = fopen(fileName, "rb");// ��ָ��
//	FILE *file_copy = fopen(fileCopyName, "wb");// �½�һ���ļ� 0kb 
//
//	if (!file || !file_copy){
//		printf("�ļ���ʧ��");
//		exit(0);// �˳�����
//	}
//
//	// size_t fread(void          *buffer, size_t size, size_t count, FILE          *stream);
//	int buffer[512];// 2048 = 4*514
//	int len;
//	printf("%d",sizeof buffer);
//	while ((len = fread(buffer, sizeof(int), 512, file))!=0){
//		fwrite(buffer, sizeof(int), len, file_copy);
//	}
//
//	fclose(file);
//	fclose(file_copy);
//
//	getchar();
//}


// ��ȡ�ļ��Ĵ�С
//void main(){
//	//char* fileName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image.jpg";
//	char* fileName = "F:\\screen0.jpg";
//
//	FILE *file = fopen(fileName, "rb");// ��ָ��
//
//	if (!file){
//		printf("�ļ���ʧ��");
//		exit(0);// �˳�����
//	}
//	// û��һ�������ǿ���ֱ�����ļ���С
//	// ˼·�����ļ���ָ���ƶ������Ȼ����ȥ����ƫ����
//	// ��������  SEEK_SET����ͷ��, SEEK_CUR����ǰ��, SEEK_END���ƶ������
//	fseek(file, 0, SEEK_END);
//
//	// ����ƫ�Ƶ�λ��,ftell �� 0 ��ʼͳ�Ƶ���ǰ��SEEK_END��
//	long file_size = ftell(file);
//
//	printf("�ļ���С��%ld",file_size);
//
//	fclose(file);
//
//	getchar();
//}



// �ļ�����
// ͼƬ��������ʹ�õ������ģ���Ϊ�˷�ֹͼƬй�ܣ�ͼƬ���м���
//void main(){
//		char* fileName = "F:\\screen0.jpg";
//		char* fileEncrpyName = "F:\\screen0_copy.jpg";
//
//
//	FILE *file = fopen(fileName, "rb");// ��ָ��
//	FILE *file_encrpy = fopen(fileEncrpyName, "wb");// �½�һ���ļ� 0kb 
//
//	if (!file || !file_encrpy){
//		printf("�ļ���ʧ��");
//		exit(0);// �˳�����
//	}
//	// �ƻ��ļ�����ԭ
//	// ˼·����ÿһ���ֽڶ��ó�������ÿһ���ֽڶ�������ĳ�����ֽ��ó��������д���
//	// 10^5 ���  ���ܹ��� 
//	//  1010  
//	// ^0101
//	//  1111  ����
//
//	// ���� ͬ����ȥ��� 5 
//	//  1111
//	// ^0101
//	//  1010    ���ܺ� 10
//	int c;// EOF end of file
//	while ((c = fgetc(file))!=EOF){
//		fputc(c ^ 5, file_encrpy);
//	}
//
//	getchar();
//}



// �ļ��Ľ���
//void main(){
//	/*char* fileEnName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image_en.jpg";
//	char* fileDeName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image_de.jpg";*/
//	char* fileEnName = "F:\\screen0_copy.jpg";
//	char* fileDeName = "F:\\screen0_copy_de.jpg";
//	FILE *file = fopen(fileEnName, "rb");// ��ָ��
//	FILE *file_decrpy = fopen(fileDeName, "wb");// �½�һ���ļ� 0kb 
//
//	if (!file || !file_decrpy){
//		printf("�ļ���ʧ��");
//		exit(0);// �˳�����
//	}
//
//	// ˼·����ÿһ���ֽڶ��ó�������ÿһ���ֽڶ�������ĳ�����ֽ��ó��������д���
//	// 10^5 ���  ���ܹ���
//	//  1010  
//	// ^0101
//	//  1111  ����
//
//	// ���� ͬ����ȥ��� 5 
//	//  1111
//	// ^0101
//	//  1010    ���ܺ� 10
//	int c;// EOF end of file
//	while ((c = fgetc(file)) != EOF){
//		fputc(c ^ 5, file_decrpy);
//	}
//
//	 getchar();
//}

// �͸�һ���ֽ�, ����ȥ
//void main(){
//	char* fileEnName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image.jpg";
//	// rwb 
//	FILE *file = fopen(fileEnName, "wb"); // ��ָ�룬�����ļ�? ��û�������취 ֧��������ʶ�� Mat ����
//	// file ����ͷָ��
//
//	fputc(5, file);
//
//	fclose(file);
//
//	// getchar();
//}



// �ַ���������м���
//void main(){
//	char* fileName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image.jpg";
//	char* fileEncrpyName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image_en.jpg";
//
//	char* passWord = "123456";// ��������^����
//
//	FILE *file = fopen(fileName, "rb");// ��ָ��
//	FILE *file_encrpy = fopen(fileEncrpyName, "wb");// �½�һ���ļ� 0kb 
//
//	if (!file || !file_encrpy){
//		printf("�ļ���ʧ��");
//		exit(0);// �˳�����
//	}
//
//	int c;// EOF end of file
//	int index = 0;
//	int pass_len = strlen(passWord);
//	while ((c = fgetc(file)) != EOF){
//		fputc(c ^ passWord[index%pass_len], file_encrpy);
//		index++;
//	}
//}



//void main(){
//	char* fileName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image_en.jpg";
//	char* fileDeName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image_de.jpg";
//
//	char* passWord = "123456";// ��������^����
//
//	FILE *file = fopen(fileName, "rb");// ��ָ��
//	FILE *file_decrpty = fopen(fileDeName, "wb");// �½�һ���ļ� 0kb 
//
//	if (!file || !file_decrpty){
//		printf("�ļ���ʧ��");
//		exit(0);// �˳�����
//	}
//
//	int c;// EOF end of file
//	int index = 0;
//	int pass_len = strlen(passWord);
//	while ((c = fgetc(file)) != EOF){
//		fputc(c ^ passWord[index%pass_len], file_decrpty);
//		index++;
//	}
//
//	fclose(file);
//	fclose(file_decrpty);
//}



// java �Ĳ���Ϊʲô�Ḵ�ӣ�װ�����ģʽ���⻷�� okio -> JavaIo -> native����
int getFileSize(char* fileName){
	FILE* file = fopen(fileName,"rb");

	if (!file){
		return 0;
	}

	fseek(file,0,SEEK_END);
	int file_size = ftell(file);

	fclose(file);

	return file_size;
}

// �ļ����и˼·�����ڶϵ�����
void main(){
	// �ٶ��� ������4G���ļ��� 8G �ļ����ӽ�ȥ
	// ���ļ����ϵ�������

	// �ļ��и���ļ�����Ϊһ��˼��

	// ����ÿ���ļ���Ҫд����٣�
	//char* fileName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image.jpg";
	char* fileName = "F:\\screen0.jpg";
	FILE* file = fopen(fileName,"rb");

	int file_size = getFileSize(fileName);

	// ���� �ж��٣������С��ָ���ļ���
	int file_number = 3;
	// ��ά���飬char[] char*
	// image_0.jpg
	// image_1.jpg
	// image_2.jpg
	// char* file_name
	// char* 
	char** file_names = (char**)malloc(sizeof(char*)*file_number);
	int preFileSize = file_size / file_number;
	// ���и���
	int i = 0;
	for (; i < 3; i++)
	{
		file_names[i] = (char*)malloc(sizeof(char)*100);// '\0'
		sprintf(file_names[i], "F:\\ndkWorkSpace\\image_%d.jpg", i);

		printf("%s\n", file_names[i]);
	}

	i = 0;
	for (; i < file_number; i++)
	{
		// ��Դ�ļ������и��ļ�д������
		FILE* cur_file = fopen(file_names[i],"wb");

		// д���٣�
		int start = i*preFileSize;
		int end = (i + 1)*preFileSize;
		if (i == file_number - 1){
			end = file_size;
		}
		
		// ��һ��ѭ�� file �����ڶ���ѭ�����Ǵ� file ����
		for (int j = start; j < end; j++)
		{
			// ��file �������д�絽 cur_file
			fputc(fgetc(file),cur_file);
		}

		fclose(cur_file);
		//free(file_names[i]);
	}

	fclose(file);
	//free(file_names);

	getchar();

}
// for  EOF JNI 3-4 C ���� 
// grace 2746186102 ��ϧ����ʱ�䣩
