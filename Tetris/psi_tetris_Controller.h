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

int nkey; //특정 방향키 아스키 코드 값

// 콘솔 좌표값은 크기가 작으므로 short 

//현재 블록 모양
short curShape;
void CurrentShape();
//다음 블록 모양
short nexShape;
void NextShape();

//블록의 현재 좌표!!!
short BlockCOL;
short BlockROW;
//블록의 이전 좌표
short prevBlockCOL;
short prevBlockROW;

//테트리스 보드 내 현재 위치하는 커서
COORD Cursor;

//이전 블록 지우기
void deletePrevBlock();

//스코어
int static score;
void printScore();

//게임 난이도
short gameLevel;

//새로운 블록 종류 생성
void newBlock();

short turn;
void RotateBlock(); //방향키 받을시 rotate 를통해 방향키 변경

boolean IsCollision(int shape, int rotate, int curX, int curY);
//블록이 bottom에 닿았을 경우 
void blockFixed(int shape, int rotate);

boolean IsNextBlock;


boolean IsMaxLine(); // 게임 핵심 마지막줄 제거 
void deleteLine();

boolean IsOverHeight(); // 게임 오버 


//미리보기 블록 만들고 지울 때 해당 좌표 저장해야합니다.
COORD previewPoint;
//미리보기 블록, 현재 블록 이후에 나올 블록 화면에 표현.
void previewBlock(int shape, int rotate);
//테트리스 돌아가는데 있어 가장 중요한 함수.(메인함수급입니다)
void tetris_process();


#endif