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
	int add;
	char aux[2];  // ����װҪ��ʾ���ַ�, �����ﻹҪ��һ��'\0'�ַ������ַ��� 
//	char *aux=NULL;  // ��֪��Ϊ�β������ַ���ָ�� 
	beginPaint();
	
	for (int i = 0; i < COL_NUM; i++ ) {  // ����ÿ�� 
//		printf("%d\n", i);
		// strInfo[i][0]�洢���ǳ�ʼλ�ã�strInfo[i][1]�洢�������г���
		// ���������������ӣ���ʾ������ʵ�����Ǵӳ�ʼλ�ÿ�ʼ��ǰ�ҳ��ȸ��ַ�������������
		// �����ַ������� CharNum=64�����г�ʼλ�ã�30�����ȣ�10��
		//��ô�����о����ַ��� 20~30 ��һ�Σ����� 30~40 
		// add ʵ���Ͼ��Ǹ����е�ͷ��strInfo[i][1]Ϊβ 
		add = strInfo[i][0] - strInfo[i][1]; 
		for ( int j = 0; j < strInfo[i][1]; j++, add++ ) {  // ���������У�����������strInfo[i][1] 
			// ���е�ͷ����0��С��CharNum����Ļ�ϲ���Ԫ�أ�����Ҫ����
			// �����������л������ƶ���ֱ����ͷ�ﵽ��Ļ���ˣ���ʼ���ƣ�ֱ������������г��� 
			if ( add < 0 || add >= CharNum ) {
				continue;
			}
			// add: ����ͷ��charSet[i] + add���� charSet[i]���ַ���ָ���Ƶ�����ͷ��
			// �״����Ƶ�ͷ�������� add++���Ժ�ÿ�ξ������δ�ͷ�������ƶ�һλ
			// 1����ָ����ָ���� 1���ַ������� aux		
			strncpy(aux, charSet[i] + add, 1);
			aux[1] = '\0';
			
			// ��ʼ�ǻ��ƴ� add~add+strInfo[i][1] ���ַ���
			// ֱ����forѭ�����������һ���ַ�ʱ��j==strInfo[i][1] - 1����
			// �����Ƶ��ַ���y������󣬼�λ���������·�
			// ��������ַ��ð�ɫ��ʾ 
			if ( j == strInfo[i][1] - 1 ) {
				setTextColor(RGB(255, 255, 255));
			} else {
				// ����λ���ַ���һ��ʼ�ӽ���ɫ�������壨��Ϊ����Ҳ�Ǻ�ɫ��
				// Խ����Ƶģ�λ��Խ����Ļ�·�����ɫԽ�ӽ���0��255��0�� 
				setTextColor(RGB(0, (j+1) * (255 / strInfo[i][1]), 0));
			}
			
//			paintText(i*TEXTSIZE, add*TEXTSIZE, aux.c_str()); // c++
			// i*TEXTSIZE����ͬ�е����� x �᲻ͬ 
			// add*TEXTSIZE������ add++, ͬһ���еĲ�ͬλ���ַ� y �᲻ͬ 
			paintText(i*TEXTSIZE, add*TEXTSIZE, aux);

		}
	}
	endPaint();
}




