
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





int x = 30;
int y = 7;

int main() {

	CursorView(false); //Ŀ�� ǥ�� X 
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







