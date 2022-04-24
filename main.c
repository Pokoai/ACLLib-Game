// ����ʱ�� 

#include "acllib.h"
#include <stdio.h>
#include <math.h>
#include <time.h> 

#define PI 3.14159265358979323846
#define ORX 160       // ����������� 
#define ORY 160
#define UNITANGLE 6  // ������60��ÿ��6�� 
#define HOURANGLE 30 // 12Сʱ��ÿСʱ30��   

// �Զ���һ��ʱ��ṹ���ڲ��� 
//typedef struct time { 
//	int hour;
//	int min;
//	int sec;
//} Time;

typedef struct tm Time;

ACL_Image Image;

// �Ƕ�ת����
double AngleToArc(const double angle) 
{
    return angle / 180 * PI;
}

// ����ת���յ㲢����ֱ��
void rotLine(int orx, int ory, int r, int angle)
{
	// ������ϵתֱ������ϵ
    double x = orx + r * sin(AngleToArc(180 - angle));   
    double y = ory + r * cos(AngleToArc(180 - angle));

    line(orx, ory, x, y);
}

// ����ϵͳʱ�������������ĽǶ� 
void timeToAngle(Time * time, double * h, double * m, double * s)
{
	*s = time->tm_sec * UNITANGLE;
	*m = (time->tm_min + time->tm_sec/60.0) * UNITANGLE;
	*h = (time->tm_hour  + time->tm_min/60.0 + time->tm_sec/3600.0) * HOURANGLE; 
}

// ��ȡϵͳʱ��
Time * getTime()
{
	time_t rawtime;
	Time * info;
	
	time( &rawtime );   // ��������� rawtime �� 
	info = localtime( &rawtime );  // �����ת��Ϊ tm �ṹ�� 
	return info;

} 


void timerListener(int id)
{
	double hha = 0, mma = 0, ssa = 0;  // ʱ����Ƕȱ��� 
//	static Time time = {5, 30, 0};  // �Զ���һ����ʼʱ�� 
	Time * time = getTime(); 

//	{
//		initConsole();
//		printf("%d:", time->tm_hour);
//		printf("%d:", time->tm_min);
//		printf("%d\n", time->tm_sec);
//		printf("��ǰ�ı���ʱ������ڣ�%s\n", asctime(time));
//	}

	timeToAngle(time, &hha, &mma, &ssa); 
	
	beginPaint();
	putImageScale(&Image, 0, 0, 320, 320);	// ���Ʊ��� 
	
	// ������������ 
	setPenColor(RED);
	setPenWidth(1); 
	rotLine(ORX, ORY, 75, ssa);  // ��
	
	setPenColor(BLACK);
	setPenWidth(3); 
	rotLine(ORX, ORY, 60, mma);		// �� 
	rotLine(ORX, ORY, 40, hha);		// ʱ 
	 
	endPaint();
	
	// �ֶ�����ʱ�� 
//	time.sec++;
//	if ( time.sec > 59 ) {
//		time.sec = 0;
//		time.min++;
//		if ( time.min > 59 ) {
//			time.min = 0;
//			time.hh++;
//			if (time.hh > 12) {
//				time.hh = 1;
//			}
//		}
//	}
}

int Setup()
{

    initWindow("ACLLibʱ��", DEFAULT, DEFAULT, 320, 320);	
	loadImage("D:\\Project\\ACLLib-Learn\\examples\\sources\\Time.jpg", &Image);

	registerTimerEvent(timerListener);
	startTimer(0, 1000);

	return 0; 
}
