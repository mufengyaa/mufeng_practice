#define _CRT_SECURE_NO_WARNINGS

#include<graphics.h>
#include<easyx.h>
#include<conio.h>

typedef struct btnode {
	int x;
	int y;
	wchar_t text[30];
	int status;
} btnode;

void drawBtn1(btnode t){    //���ư�ť
	setfillcolor(RGB(93, 107, 153));
	setbkmode(TRANSPARENT);
	fillroundrect(t.x, t.y, t.x + 300, t.y + 100, 100, 100);
	settextstyle(35, 20, _T("����"));
	outtextxy(t.x + 70, t.y + 38, t.text);
}

void drawup1(IMAGE upimg) {   //ui1���ϲ�
	btnode upmen= { 30,10,L"���ӰԺϵͳ" ,0};
	SetWorkingImage(&upimg);
	setbkcolor(RGB(93, 107, 153));
	cleardevice();
	settextstyle(50, 30, _T("����"));
	outtextxy(300,35,upmen.text);
	SetWorkingImage();
	putimage(0, 0, &upimg);
}
void drawdown1(IMAGE downimg,btnode* downmen) {   //ui2���²�
	int i = 0;
	SetWorkingImage(&downimg);
	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < 2; i++) {
		drawBtn1(downmen[i]);
	}
	SetWorkingImage();
	putimage(0, 119, &downimg);
}
int main(){   //ui1
	int i = 0;
	const int width = 1000;
	const int height = 618;

	initgraph(width, height, EW_NOCLOSE);
	IMAGE upimg(1000, 118);
	IMAGE downimg(1000, 500);
	MOUSEMSG msg;

	btnode downmen[2] = { {350,120,L"����ϵͳ",0} ,{350,250,L"�˳�ϵͳ",0} };
	while (1) {
		if (msg.uMsg == WM_LBUTTONDOWN) {
			for (i = 0; i < 2; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 300 && msg.y >= downmen[i].y && msg.y <= downmen[i].y + 100)
				{
					downmen[i].status = 1;
				}
			}

		}
	}

	drawup1(upimg);
	drawdown1(downimg,downmen);
    _getch();
	closegraph();
	return 0;
}
