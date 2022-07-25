#include <stdio.h>
#include <conio.h>	//�ܼ� ����� �Լ� ���� 
#include <Windows.h> // ������ ��ũ��, �Լ�, API �Լ� ���� ���
#include <time.h> //���� ����
#include <mmsystem.h> // ������� ���� �������

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW 224
#define SPACEBAR 72

enum ColorType {
	WHITE = 15, GRAY = 8, BLUE = 9, GREEN = 10
}COLOR;


/*
_kbhit()
Ű�� ������ 0�� �ƴ� ���� ��ȯ
�ش� key ���� ���۷� ����

���⼭ ����Ű�� Ư��Ű�� ���ֵ�
2���� ������ return ��
����Ű 224 �� �� ��° ��ȯ ��(�����¿�)
arrow 224
up 72 down 80 left 75 right 77


_getch()�� ���� �� key ���� ���� ����
(�ֿܼ��� ���� ���ڸ� ����!)



*/

void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
} // ���� �� 

void GotoXY(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void CursorView(char show)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

int x = 30;
int y = 7;

int main() {
	enum COLOR color;
	color = GREEN;

	CursorView(0);
	GotoXY(x, y);
	printf("��");


	while (1) {
		if (_kbhit()) {
			int nkey = _getch();

			if (nkey == SPACEBAR) {
				printf("space bar");
			}
			if (nkey == ARROW) {
				nkey = _getch();
				switch (nkey) {
				case UP:
					system("cls");
					GotoXY(x, --y);
					printf("��");
					break;
				case LEFT:
					system("cls");
					GotoXY(x = x - 2, y);
					printf("��");
					break;
				case RIGHT:
					system("cls");
					GotoXY(x = x + 2, y);
					printf("��");
					break;
				case DOWN:
					system("cls");
					GotoXY(x, ++y);
					printf("��");
					break;

				}
			}
		}
	}

	return 0;
}







