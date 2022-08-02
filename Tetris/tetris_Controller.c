#include "psi_tetirs_Blocks.h"
#include "psi_tetris_consoleCursor.h"
#include "psi_tetris_Controller.h"
#include "psi_tetris_Screen.h"

void newBlock() {
	turn = 0;
	NextShape();
	CurrentShape();
	NextShape();
	Cursor.X = BlockStartX;
	Cursor.Y = BlockStartY;
}

void RotateBlock() {
	turn++;
	if (turn == 4) turn % 4;
}

void CurrentShape() {
	curShape = nexShape;
}

void NextShape() {
	srand(time(NULL));
	nexShape = rand() % BlockType;
}

void tetris_process() {
	createBoards(); // 게임보드 생성
	srand(time(NULL));
	newBlock();
	InGameFrame();
	ShowNextBlock();
	Sleep(1000);

	while (1) {
		if (IsNextBlock == true) {
			IsNextBlock = false;
			DeleteNextBlock();
			ShowNextBlock();
		}
		printBoards();
		GotoXY(Cursor.X, Cursor.Y);
		addBlock(curShape, turn);
		previewBlock(curShape, turn);
		if (_kbhit()) {
			nkey = _getch();
			if (nkey == SPACEBAR)
			{

				while (!IsCollision(curShape, turn, Cursor.X, Cursor.Y + 1))
				{
					deletePrevBlock();  //아래와 이 함수 묶으면 깔끔,,
					deleteBlock();      //
					GotoXY(Cursor.X, Cursor.Y + 1);
					addBlock(curShape, turn);
					if (IsCollision(curShape, turn, Cursor.X, Cursor.Y + 1) == true)
					{
						blockFixed(curShape, turn);
						if (IsMaxLine())
							deleteLine();
						break;
					}
				}
				continue;
			}
			if (nkey == ARROW) {
				nkey = _getch();
				int a;
				switch (nkey) {
				case UP:
					a = turn;
					if (!IsCollision(curShape, (++a % 4), Cursor.X, Cursor.Y)) {
						deletePrevBlock();
						deleteBlock();
						RotateBlock();
						addBlock(curShape, turn);
						previewBlock(curShape, turn);
						continue;
					}
					break;
				case LEFT:
					if (!IsCollision(curShape, turn, Cursor.X - 2, Cursor.Y)) {
						deletePrevBlock();
						deleteBlock();
						GotoXY(Cursor.X - 2, Cursor.Y);
						addBlock(curShape, turn);
						previewBlock(curShape, turn);
						continue;
					}
					break;
				case RIGHT:
					if (!IsCollision(curShape, turn, Cursor.X + 2, Cursor.Y)) {
						deletePrevBlock();
						deleteBlock();
						GotoXY(Cursor.X + 2, Cursor.Y);
						addBlock(curShape, turn);
						previewBlock(curShape, turn);
						continue;
					}
					break;
				case DOWN:
					if (!IsCollision(curShape, turn, Cursor.X, Cursor.Y + 2)) {
						deletePrevBlock();
						deleteBlock();
						GotoXY(Cursor.X, Cursor.Y + 2);
						addBlock(curShape, turn);
						previewBlock(curShape, turn);
						continue;
					}
					break;
				}
			}
		}
	}
}

void printScore() {
	GotoXY(36, 20);
	printf("⊙ Score : %d", score);

}