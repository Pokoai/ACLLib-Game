#include <stdio.h>
//#include <string.h>
//#include <math.h>
#include <stdlib.h> 

// �����ļ���ͬʹ�ã�������ĸȫ����д 
#define WIN_WIDTH 	1490  					// ���ڿ��
#define WIN_HEIGHT 	860 					// ���ڸ߶�
#define TEXTSIZE  	23						// �����С 
#define COL_NUM  (WIN_WIDTH/TEXTSIZE)		// �ַ����� 


// �����ļ�ʹ�ã�δȫ��д���������ֱ��������� 
#define CharNum (WIN_HEIGHT/TEXTSIZE) 	 	// һ����˿�ַ����� 
#define MinCharNum  6  						// ������˿�ַ�����  
#define MaxCharNum  16  					// �����˿�ַ����� 

char * createString(char *);				// ����һ���ַ��� 
//void createAllChar();						// ����ȫ��Ļ���ַ���
int * createOneSliding(int *);				// ����һ����˿��ʼλ�ú���ֹλ��
//void createAllSliding();					// ����ÿ����˿����ʼλ�ú���ֹλ��
//void pulsRain();							// ���������˿��أ�����һ���µ�
void initModel();							// ��ʼ���ڴ����

extern char charSet[COL_NUM][CharNum];		// ʢ�������ַ� 
extern int strInfo[COL_NUM][2];            	// ʢ�������е���ʼλ�úͳ���  
  
