#include <stdio.h>
#include <conio.h>	//콘솔 입출력 함수 제공 
#include <Windows.h> // 윈도우 매크로, 함수, API 함수 정의 등등
#include <time.h> //난수 생성
#include <mmsystem.h> // 배경음악 관련 헤더파일

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
키를 누르면 0이 아닌 값을 반환
해당 key 값을 버퍼로 저장

여기서 방향키는 특수키로 간주됨
2개의 정수를 return 함
방향키 224 와 두 번째 반환 값(상하좌우)
arrow 224
up 72 down 80 left 75 right 77


_getch()로 버퍼 의 key 값을 전달 받음
(콘솔에서 단일 문자를 읽음!)



*/

void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
} // 글자 색 

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
	printf("★");


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
					printf("★");
					break;
				case LEFT:
					system("cls");
					GotoXY(x = x - 2, y);
					printf("★");
					break;
				case RIGHT:
					system("cls");
					GotoXY(x = x + 2, y);
					printf("★");
					break;
				case DOWN:
					system("cls");
					GotoXY(x, ++y);
					printf("★");
					break;

				}
			}
		}
	}

	return 0;
}







