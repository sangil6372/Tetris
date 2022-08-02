#pragma once
#ifndef consoleCursor
#define consoleCursor

#include <Windows.h>

COORD getCursor(void);
void GotoXY(int x, int y);
void CursorView(boolean show);

#endif
