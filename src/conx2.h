// contains functions to control console IO
#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <malloc.h>

void hidcur(void);
void gotoxy(int, int);
int getkey(void);
bool KeyPressed(void);
void clrcon(void);
