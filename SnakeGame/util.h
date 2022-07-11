#ifndef _UTIL_H_
#define _UTIL_H_

#include <Windows.h>

//enum은 헤더에 정의
enum CURSOR_TYPE
{
	NOCURSOR,
	SOLIDCURSOR,
	NORMALCURSOR
};
//함수 제목들 선언
void gotoxy(int x, int y);
void setcursortype(CURSOR_TYPE c);

#endif