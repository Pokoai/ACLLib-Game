#include "controller.h"

// �����κ���ʾ�����飬��ʾ�Ľ��� view.c ȥ��
// ���ݵ����齻�� model.c ȥ��
 
void timerListener(int id);
void charMove();
void newString();
 
int Setup()
{
	initWind();  	// ��ʼ������ 
	clearWindow();	// ��մ��� 
	initModel();	// �������ɼ������ 
	
	registerTimerEvent(timerListener);
	startTimer(0, 200);
	
	printf("%s\n", charSet[0]);
	printf("%d\n", strInfo[0][0]);
	printf("%d\n", strInfo[1][1]);
	
	return 0;	
} 



// ����Ŀ��ƾ�ֻ�� timer 
// ÿ�λ��Ѻ�������ݣ����� timer ���� contreler.c ��

void timerListener(int id)
{
	// ��Ȼ timer ����controller �У������漰����ʾ��������Ҫ�� view ������
	// ����������ȥ������ʾ��ĺ������У��ú�������ʵ��Ҫ���� view ��
	// �������ݵ������� controller ���ģ�Ӧ�÷��ڸ��ļ��� 
	
	
	// 1.ÿ�λ��Ѻ��һ���¾��Ǹ�������
	charMove();
	newString();
	// 2. Ȼ����ջ��� 
	clearWindow();
	// 3.���������ʾ
	printChar();
	 
} 


// ��������

// 1.ÿ���ƶ��ַ�����ʼλ
void charMove()
{
	for ( int i = 0; i < COL_NUM; i++ ) {
		strInfo[i][0]++;	
	}
} 

// 2.��˿��أ����´���һ�� 
void newString()
{
	int s;
	for ( int i = 0; i < COL_NUM; i++ ) {
		s = ( strInfo[i][0] - strInfo[i][1] ) * TEXTSIZE; // ����Ϊʲô������ɲο� printChar() ע�� 
		if ( s >= WIN_HEIGHT ) {
			// �������ɵ�i���ַ���
			createString(charSet[i]);
			// �������ɵ� i����˿ 
			createOneSliding(strInfo[i]);
		}
	} 
}

