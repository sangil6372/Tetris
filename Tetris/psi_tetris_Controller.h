#pragma once


#ifndef controller
#define controllor

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>


#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")

enum blockProperty {
	BlockSIZE = 4,
	BlockRotate = 4,
	BlockType = 7,

	BlockStartX = 14,
	BlockStartY = 4
};

enum boardProperty {
	BoardWidth = 14,
	BoardHeight = 22,
	BoardX = 4,
	BoardY = 3
};

enum Keys {
	LEFT = 75,
	RIGHT = 77,
	UP = 72,
	DOWN = 80,
	ARROW = 224,
	SPACEBAR = 32
};

typedef enum gameSpeed {
	easy = 230,
	normal = 170,
	hard = 150
}SPEED;

int nkey; //Ư�� ����Ű �ƽ�Ű �ڵ� ��

// �ܼ� ��ǥ���� ũ�Ⱑ �����Ƿ� short 

//���� ��� ���
short curShape;
void CurrentShape();
//���� ��� ���
short nexShape;
void NextShape();

//����� ���� ��ǥ!!!
short BlockCOL;
short BlockROW;
//����� ���� ��ǥ
short prevBlockCOL;
short prevBlockROW;

//��Ʈ���� ���� �� ���� ��ġ�ϴ� Ŀ��
COORD Cursor;

//���� ��� �����
void deletePrevBlock();

//���ھ�
int static score;
void printScore();

//���� ���̵�
short gameLevel;

//���ο� ��� ���� ����
void newBlock();

short turn;
void RotateBlock(); //����Ű ������ rotate ������ ����Ű ����

boolean IsCollision(int shape, int rotate, int curX, int curY);
//����� bottom�� ����� ��� 
void blockFixed(int shape, int rotate);

boolean IsNextBlock;


boolean IsMaxLine(); // ���� �ٽ� �������� ���� 
void deleteLine();

boolean IsOverHeight(); // ���� ���� 


//�̸����� ��� ����� ���� �� �ش� ��ǥ �����ؾ��մϴ�.
COORD previewPoint;
//�̸����� ���, ���� ��� ���Ŀ� ���� ��� ȭ�鿡 ǥ��.
void previewBlock(int shape, int rotate);
//��Ʈ���� ���ư��µ� �־� ���� �߿��� �Լ�.(�����Լ����Դϴ�)
void tetris_process();


#endif