#include "view.h"

void initWind()
{
	ACL_Sound pSound;
	
	initWindow("CharRain", 0, 0, WIN_WIDTH, WIN_HEIGHT);
	srand((unsigned int)time(NULL));
	
	loadSound("D:\\Project\\ACLLib-Learn\\examples\\CharRain\\Flower Dance.mp3", &pSound);
	playSound(pSound, 1);
//	initConsole();
	
	beginPaint();
	setBrushColor(RGB(0, 0, 0));
	setTextBkColor(RGB(0, 0, 0));
	setTextFont("Kristen ITC");
	setTextSize(TEXTSIZE);
	endPaint();
}

void clearWindow()
{
	beginPaint();
	rectangle(0, 0, WIN_WIDTH, WIN_HEIGHT);
	endPaint();
}

// ֻҪ�������ˣ���������ȥ���Ƴ�������
// ���ÿ������ݱ仯���� 
void printChar()
{
	char tempStr[2];  // ����װҪ��ʾ���ַ�, �����ﻹҪ��һ��'\0'�ַ������ַ��� 
//	char *temp=NULL;  // ��֪��Ϊ�β������ַ���ָ�� 
	beginPaint();
	
	for (int i = 0; i < COL_NUM; i++ ) {  // ����ÿ�� 
//		printf("%d\n", i);
		// strInfo[i][0]�洢���ǳ�ʼλ�ã�strInfo[i][1]�洢�������г���
		// ���������������ӣ���ʾ������ʵ�����Ǵӳ�ʼλ�ÿ�ʼ��ǰ�ҳ��ȸ��ַ�������������
		// �����ַ������� CharNum=64�����г�ʼλ�ã�30�����ȣ�10��
		//��ô�����о����ַ��� 20~30 ��һ�Σ����� 30~40 
		// top ʵ���Ͼ��Ǹ����е�ͷ��strInfo[i][1]Ϊβ 
		int top = strInfo[i][0] - strInfo[i][1]; 
		for ( int j = 0; j < strInfo[i][1]; j++, top++ ) {  // ���������У�����������strInfo[i][1] 
			// ���е�ͷ����0��С��CharNum����Ļ�ϲ���Ԫ�أ�����Ҫ����
			// �����������л������ƶ���ֱ����ͷ�ﵽ��Ļ���ˣ���ʼ���ƣ�ֱ������������г��� 
			if ( top < 0 || top >= CharNum ) {
				continue;
			}
			// top: ����ͷ��charSet[i] + top���� charSet[i]���ַ���ָ���Ƶ�����ͷ��
			// �״����Ƶ�ͷ�������� top++���Ժ�ÿ�ξ������δ�ͷ�������ƶ�һλ
			// 1����ָ����ָ���� 1���ַ������� temp		
			strncpy(tempStr, charSet[i] + top, 1);
			tempStr[1] = '\0';
			
			// ��ʼ�ǻ��ƴ� top~top+strInfo[i][1] ���ַ���
			// ֱ����forѭ�����������һ���ַ�ʱ��j==strInfo[i][1] - 1����
			// �����Ƶ��ַ���y������󣬼�λ���������·�
			// ��������ַ��ð�ɫ��ʾ 
			if ( j == strInfo[i][1] - 1 ) {
				setTextColor(RGB(255, 255, 255));
			} else {
				// ����λ���ַ���һ��ʼ�ӽ���ɫ�������壨��Ϊ����Ҳ�Ǻ�ɫ��
				// Խ����Ƶģ�λ��Խ����Ļ�·�����ɫԽ�ӽ���0��255��0�� 
				setTextColor(RGB(0, (j+1) * 255 / strInfo[i][1], 0));
			}
			
//			paintText(i*TEXTSIZE, top*TEXTSIZE, temp.c_str()); // c++
			// i*TEXTSIZE����ͬ�е����� x �᲻ͬ 
			// top*TEXTSIZE������ top++, ͬһ���еĲ�ͬλ���ַ� y �᲻ͬ 
			paintText(i*TEXTSIZE, top*TEXTSIZE, tempStr);

		}
	}
	endPaint();
}




