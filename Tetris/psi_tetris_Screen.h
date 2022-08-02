#pragma once
#ifndef __TETRIS_SCREEN_H__
#define __TETRIS_SCREEN_H__


#include <stdio.h>
#include <windows.h>     // �� �� header file�� ���� ������ ���� �ݵ�� �ʿ��� ���Դϴ�.
#include "psi_tetris_Controller.h"
#include "psi_tetirs_Blocks.h"


#define COL                   GetStdHandle(STD_OUTPUT_HANDLE)        // �ܼ�â�� �ڵ����� �ޱ�

typedef enum Color {
	DARKPURPLE = 5,
	GRAY = 8,
	BLUE = 9,
	GREEN = 10,
	AQUA = 11,
	RED = 12,
	PURPLE = 13,
	YELLOW = 14,
	WHITE = 15
}COLOR;

void createBoards();

int static level;



#endif