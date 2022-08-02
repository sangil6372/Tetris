
#include "psi_tetris_Screen.h"
#include "psi_tetris_consoleCursor.h"

int board[22][14] = { 0 };

int NextBlock[6][6] = {
		1,1,1,1,1,1,
		1,0,0,0,0,1,
		1,0,0,0,0,1,
		1,0,0,0,0,1,
		1,0,0,0,0,1,
		1,1,1,1,1,1,
};

void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
} // 글자 색 설정

void GameTitle() {

}

void InGameFrame() {
	int picture_X = 36;//14*2+4+8 //2+14+2 = 18//
	int picture_Y = 0;
	// 빈 공간 채워 넣기 picture[][] secPicture[][]
	GotoXY(picture_X, picture_Y + 19);
	switch (level) {
	case 0:
		printf("⊙ gameLevel : easy");
		break;
	case 1:
		printf("⊙ gameLevel : normal");
		break;
	case 2:
		printf("⊙ gameLevel : hard");
		break;
	}
	GotoXY(picture_X, picture_Y + 21);
	printf("⊙ game KEY");
	printScore();
	GotoXY(picture_X, picture_Y + 22);
	printf("  ▲         : block rotate");
	GotoXY(picture_X, 23);
	printf("◀  ▶       : move LEFT /  move RIGHT");
	GotoXY(picture_X, 24);
	printf("  ▼         : move DOWN");
	GotoXY(picture_X, 25);
	printf("■■■■     : space BAR (DIRECT DOWN)");

	//게임 키 입력하라고 재촉하는 거 인 듯
	for (int i = 0; i < 3; i++) {
		GotoXY(picture_X, picture_Y + 21);
		printf("⊙ game KEY");
		Sleep(350);
		GotoXY(picture_X, picture_Y + 21);
		printf("            ");
		Sleep(250);
	}
	GotoXY(picture_X, picture_Y + 21);
	printf("            ");
	GotoXY(picture_X, picture_Y + 21);
	printf("⊙ game KEY");

}

void ShowNextBlock() {
	GotoXY(36 + 9, 0 + 11);
	textcolor(DARKPURPLE);
	printf("NEXT BLOCK");
	textcolor(WHITE);

	for (int y = 0; y < 6; y++) {
		for (int x = 0; x < 6; x++) {
			GotoXY(36 + 8 + x * 2, 12 + y);
			if (NextBlock[y][x] == 1) {
				textcolor(3);//6
				printf("▩");
				textcolor(WHITE);
			}
			if (y > 0 && y < 5) {
				if (x > 0 && x < 5) {
					if (Blocks[nexShape][0][y - 1][x - 1] == 2)
					{
						NextBlock[y][x] = Blocks[nexShape][0][y - 1][x - 1];
						GotoXY(36 + 8 + x * 2, 12 + y);
						printf("■");
					}
				}
			}
		}
	}

}

void DeleteNextBlock() {
	for (int y = 0; y < 6; y++) {
		for (int x = 0; x < 6; x++) {
			if (y > 0 && y < 5) {
				if (x > 0 && x < 5) {
					if (NextBlock[y][x] == 2) {
						GotoXY(36 + 8 + x * 2, 12 + y);
						printf("  ");
					}
				}
			}
		}
	}
}
void createBoards() {

	for (int i = 0; i < BoardHeight; i++) {
		board[i][0] = 1;
		board[i][BoardWidth - 1] = 1;
		for (int j = 0; j < BoardWidth; j++) {
			if (i == 0)
				board[i][j] = 0;
			board[BoardHeight - 1][j] = 1;
			if (i > 0 && i < BoardHeight - 1)
				if (j > 0 && j < BoardWidth - 1)
					board[i][j] = 0;
		}
	}

}

void printBoards() {
	for (int x = 1; x < 13; x++) {
		GotoXY(BoardX + x * 2, BoardY + 1);
		printf("__");
	} // 테트리스 떨어지는 경계 만들기 

	for (int y = 0; y < BoardHeight; y++) {
		GotoXY(BoardX, BoardY + y);
		if (board[y][0] == 1) {
			textcolor(3);	printf("▩");
		}

		if (board[y][BoardWidth - 1] == 1) {
			GotoXY(BoardX + BoardWidth * 2 - 2, BoardY + y);
			textcolor(3);
			printf("▩");
		}
		textcolor(WHITE);
	}
	for (int x = 0; x < BoardWidth; x++) {
		GotoXY(BoardX + x * 2, BoardY + BoardHeight - 1);
		if (board[BoardHeight - 1][x] == 1) {
			textcolor(3);	printf("▩");
		}
		textcolor(WHITE);
	}
}

void addBlock(int shape, int rotate) {

}
void deleteBlock() {

}

void EndGameFrame() {
	for (int y = 1; y < BoardHeight - 1; y++) {
		for (int x = 1; x < BoardWidth - 1; x++) {
			if (board[y][x] >= 3) {
				GotoXY(BoardX + x * 2, BoardY + y);
				printf("▣");
			}
		}
		Sleep(150 - y * 5);
	}
	GotoXY(BlockStartX, BlockStartY + 1);
	printf("GameOVER");
	Sleep(3000);
	exit(0);
}