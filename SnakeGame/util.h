#ifndef _UTIL_H_
#define _UTIL_H_

#include <Windows.h>

//enum�� ����� ����
enum CURSOR_TYPE
{
	NOCURSOR,
	SOLIDCURSOR,
	NORMALCURSOR
};
//�Լ� ����� ����
void gotoxy(int x, int y);
void setcursortype(CURSOR_TYPE c);

#endif