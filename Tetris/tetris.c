
#include "psi_tetirs_Blocks.h"
#include "psi_tetris_consoleCursor.h"
#include "psi_tetris_Controller.h"
#include "psi_tetris_Screen.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>



#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW 224
#define SPACEBAR 72



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





int x = 30;
int y = 7;

int main() {

	CursorView(false); //커서 표시 X 
	/*
	sleep(1000);
	GameTitle();
	tetis_process();
	*/

	tetris_process();





	enum COLOR color;
	color = GREEN;

	CursorView(0);
	GotoXY(x, y);


	










	

	return 0;
}







