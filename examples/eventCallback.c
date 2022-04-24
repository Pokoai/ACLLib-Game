#include "acllib.h"
#include <stdio.h>

// ���ص����� 
void mouseListener(int x, int y, int button, int event)
{
	static int ox = 0;
	static int oy = 0;
	 
	printf("x=%d, y=%d, button=%d, event=%d\n", x, y, button, event);
	
	beginPaint();
	// ������±�־������Ϊ 1���ɿ�Ϊ 0 
	static int lflag = 0; 
	if ( button == LEFT_BUTTTON && event == BUTTON_DOWN ) {
			printf("�������\n");
			lflag = 1;
	} 
	if ( button == LEFT_BUTTTON && event == BUTTON_UP ) {
		lflag = 0;
		printf("����ɿ�\n"); 
	}
	// �������ʱ�Ż��� 
	if ( lflag == 1) {
		line(ox, oy, x, y);
	}
	endPaint();
	
	ox = x;
	oy = y;
}

// ���̻ص����� 
void keyboardListener(int key, int event)
{
	printf("key=%d, event=%d\n", key, event);
}

// ��ʱ���ص����� 
void timerListener(int id)
{
	static int cnt = 0;
	
	printf("id=%d\n", id);
	if ( id == 0 ) {
		cnt++;
		if ( cnt == 5 ) {
			cancelTimer(0);
		}
	}
}


int Setup()
{	
	// ���ô��� 
	initWindow("test", 900, 100, 1000, 1000);
	// �� console
	initConsole();
	
	// �� ACLLib ע������¼� 
	registerMouseEvent(mouseListener);
	registerKeyboardEvent(keyboardListener);
	registerTimerEvent(timerListener);
	startTimer(0, 1000);
	startTimer(1, 1000);
	 
//	// ��ʼ��ͼ
//	beginPaint();
//	
//	
//	// ������ͼ 
//	endPaint();
	
	return 0; 
}
