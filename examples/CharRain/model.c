// ��Ÿ������ݵĵط�
// �������ݲ�Ҫ�����������Ӧ���� controller �и������� 


#include "model.h" 

// ȫ�ֱ���
//���������Ҫ�����ݣ��� controller��view ʹ�� 

char charSet[COL_NUM][CharNum];  // ʢ�������ַ��� 
int strInfo[COL_NUM][2];  		// ʢ���������е� ��ʼλ�á����� 

/*
 *������������������Լ������Ľṹ�����
 * typedef struct { 
 *    char charSet[COL_NUM][CharNum];
 *    int pos;
 *	  int len;
 *} String;
 *
 */

// ���ɵ����ַ������� A-Z ��� 
char * createString(char * s)
{
	// ��Ҫȷ�������೤���ַ����������� .h �ļ����ȶ�����
	int c; 
	
	for ( int i = 0; i < CharNum; i++ ) {
		// ������� A-Z ���ַ������� A:64, Z:90  ACS11��
		// ÿ�� for ѭ������Ҫ����һ�������Ա���Ҫ����һ���� 64-91���ֵ����Ȼû��
		// ��ô���Ǿ���Ҫʹ��ѭ���ˣ���һ�ξ�Ҫִ�У����Բ��� do-while ѭ��
		do {
			// ��ȷ�� ����� < 91 
			c = rand() % 91;
		} while ( c < 64 ); // c<64 ����ȥ while��ֱ������һ�� 64<= c < 91 ����Ϊֹ 
		*(s+i) = c; 
	}
	// ��Ҫ�� s ĩβ���һ��'\0'�ַ������ܱ�ʾ s ��һ���ַ���
	*(s+CharNum) = '\0';
	
	return s; 	
}


// ����������ַ��������� charSet �ַ��������� 
void createAllChar()
{
	// Ҫȷ����ʾ�����е��ַ������� .h �ļ��ж������
	
//	char s[CharNum+1];  // ��һ��������� '\0'
	
	// ���������ַ�
	for ( int i = 0; i < COL_NUM; i++ ) {
//		strncat(charSet, createString(s), CharNum+1); // ���� strncat, ��֤��ȫ 
		createString(charSet[i]);
	} 
 } 
 

// �������ַ������ȡ��������ʾ��һ���ַ�
// ȷ���˸����ַ�����ʼλ�úͳ��Ⱦ�ȷ���˸����ַ���
// ��ʼλ�á���������������Ҫһ���������洢 
int * createOneSliding(int * arry)
{
	// ���ȷ����ʼλ��
	arry[0] = rand() % CharNum - CharNum;  // δ������
	// ȷ��������ȣ�����Ҫ��֤�ڹ涨��Χ��
	// ������ͬ��ȷ���ַ��� A-Z ֮��
	do {
		arry[1] = rand() % MaxCharNum + 1;
	} while( arry[1] < MinCharNum); 
	
	return arry;
}


// ���������ַ���
void createAllSliding() 
{	
	for ( int i = 0; i < COL_NUM; i++ ) {
		createOneSliding(strInfo[i]); 
		strInfo[i][0] += CharNum;  // ǰ������Ĳ����� 
	}
}


// ��ʼ�� Model�������������� 
void initModel()
{
	createAllChar();
	createAllSliding();
} 




















 


