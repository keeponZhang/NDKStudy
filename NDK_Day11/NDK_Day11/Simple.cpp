#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//void main(){
//	// 打开文件 （文件名，模式）mode r(读) w(写) rb(作为二进制读) wb(作为二进制写)
//	// FILE *fopen( const char *filename, const char *mode );
//
//	char* fileName = "F:/config.java";
//
//	FILE *file = fopen(fileName, "r");
//
//	if (!file){
//		printf("文件打开失败"); 
//			getchar();
//		exit(0);// 退出程序
//	}
//
//	char buffer[10];
//
//	// 缓冲区buffer，长度10 ，文件指针
//	while (fgets(buffer, 10, file)){
//		printf("%s",buffer);
//	}
//
//	// 关闭文件
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
//		printf("文件打开失败");
//		exit(0);// 退出程序
//	}
//
//	fputs("I am Darren",file);
//
//
//	// 关闭文件
//	fclose(file);
//
//
//	getchar();
//}


 //文件复制，当做二进制文件来操作
//void main(){
//	char* fileName = "F:\\screen0.jpg";
//	char* fileCopyName = "F:\\screen1.jpg";
//
//	FILE *file = fopen(fileName, "rb");// 流指针
//	FILE *file_copy = fopen(fileCopyName, "wb");// 新建一个文件 0kb 
//
//	if (!file || !file_copy){
//		printf("文件打开失败");
//		exit(0);// 退出程序
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


// 获取文件的大小
//void main(){
//	//char* fileName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image.jpg";
//	char* fileName = "F:\\screen0.jpg";
//
//	FILE *file = fopen(fileName, "rb");// 流指针
//
//	if (!file){
//		printf("文件打开失败");
//		exit(0);// 退出程序
//	}
//	// 没有一个函数是可以直接拿文件大小
//	// 思路：将文件的指针移动到最后，然后再去计算偏移量
//	// 三个参数  SEEK_SET（开头）, SEEK_CUR（当前）, SEEK_END（移动到最后）
//	fseek(file, 0, SEEK_END);
//
//	// 计算偏移的位置,ftell 从 0 开始统计到当前（SEEK_END）
//	long file_size = ftell(file);
//
//	printf("文件大小：%ld",file_size);
//
//	fclose(file);
//
//	getchar();
//}



// 文件加密
// 图片服务器（使用第三方的），为了防止图片泄密，图片进行加密
//void main(){
//		char* fileName = "F:\\screen0.jpg";
//		char* fileEncrpyName = "F:\\screen0_copy.jpg";
//
//
//	FILE *file = fopen(fileName, "rb");// 流指针
//	FILE *file_encrpy = fopen(fileEncrpyName, "wb");// 新建一个文件 0kb 
//
//	if (!file || !file_encrpy){
//		printf("文件打开失败");
//		exit(0);// 退出程序
//	}
//	// 破坏文件，还原
//	// 思路：把每一个字节都拿出来，对每一个字节都处理，把某部分字节拿出来，进行处理
//	// 10^5 异或  加密过程 
//	//  1010  
//	// ^0101
//	//  1111  加密
//
//	// 解密 同样的去异或 5 
//	//  1111
//	// ^0101
//	//  1010    解密后 10
//	int c;// EOF end of file
//	while ((c = fgetc(file))!=EOF){
//		fputc(c ^ 5, file_encrpy);
//	}
//
//	getchar();
//}



// 文件的解密
//void main(){
//	/*char* fileEnName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image_en.jpg";
//	char* fileDeName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image_de.jpg";*/
//	char* fileEnName = "F:\\screen0_copy.jpg";
//	char* fileDeName = "F:\\screen0_copy_de.jpg";
//	FILE *file = fopen(fileEnName, "rb");// 流指针
//	FILE *file_decrpy = fopen(fileDeName, "wb");// 新建一个文件 0kb 
//
//	if (!file || !file_decrpy){
//		printf("文件打开失败");
//		exit(0);// 退出程序
//	}
//
//	// 思路：把每一个字节都拿出来，对每一个字节都处理，把某部分字节拿出来，进行处理
//	// 10^5 异或  加密过程
//	//  1010  
//	// ^0101
//	//  1111  加密
//
//	// 解密 同样的去异或 5 
//	//  1111
//	// ^0101
//	//  1010    解密后 10
//	int c;// EOF end of file
//	while ((c = fgetc(file)) != EOF){
//		fputc(c ^ 5, file_decrpy);
//	}
//
//	 getchar();
//}

// 就改一个字节, 过不去
//void main(){
//	char* fileEnName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image.jpg";
//	// rwb 
//	FILE *file = fopen(fileEnName, "wb"); // 流指针，创建文件? 有没有其他办法 支付宝人脸识别 Mat 矩阵
//	// file 流的头指针
//
//	fputc(5, file);
//
//	fclose(file);
//
//	// getchar();
//}



// 字符串密码进行加密
//void main(){
//	char* fileName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image.jpg";
//	char* fileEncrpyName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image_en.jpg";
//
//	char* passWord = "123456";// 轮流进行^操作
//
//	FILE *file = fopen(fileName, "rb");// 流指针
//	FILE *file_encrpy = fopen(fileEncrpyName, "wb");// 新建一个文件 0kb 
//
//	if (!file || !file_encrpy){
//		printf("文件打开失败");
//		exit(0);// 退出程序
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
//	char* passWord = "123456";// 轮流进行^操作
//
//	FILE *file = fopen(fileName, "rb");// 流指针
//	FILE *file_decrpty = fopen(fileDeName, "wb");// 新建一个文件 0kb 
//
//	if (!file || !file_decrpty){
//		printf("文件打开失败");
//		exit(0);// 退出程序
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



// java 的操作为什么会复杂？装饰设计模式（光环） okio -> JavaIo -> native方法
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

// 文件的切割，思路类似于断点下载
void main(){
	// 百度云 不大于4G的文件？ 8G 文件，扔进去
	// 大文件（断点续传）

	// 文件切割，把文件合作为一个思考

	// 计算每个文件需要写入多少？
	//char* fileName = "C:\\Users\\hcDarren\\Desktop\\android\\NDK\\image.jpg";
	char* fileName = "F:\\screen0.jpg";
	FILE* file = fopen(fileName,"rb");

	int file_size = getFileSize(fileName);

	// 定义 切多少，计算大小，指定文件名
	int file_number = 3;
	// 二维数组，char[] char*
	// image_0.jpg
	// image_1.jpg
	// image_2.jpg
	// char* file_name
	// char* 
	char** file_names = (char**)malloc(sizeof(char*)*file_number);
	int preFileSize = file_size / file_number;
	// 进行复制
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
		// 从源文件中往切割文件写入数据
		FILE* cur_file = fopen(file_names[i],"wb");

		// 写多少？
		int start = i*preFileSize;
		int end = (i + 1)*preFileSize;
		if (i == file_number - 1){
			end = file_size;
		}
		
		// 第一个循环 file 读，第二个循环还是从 file 里面
		for (int j = start; j < end; j++)
		{
			// 从file 里面读，写如到 cur_file
			fputc(fgetc(file),cur_file);
		}

		fclose(cur_file);
		//free(file_names[i]);
	}

	fclose(file);
	//free(file_names);

	getchar();

}
// for  EOF JNI 3-4 C 进阶 
// grace 2746186102 珍惜（花时间）
