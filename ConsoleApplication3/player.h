// contains functions to control player
#pragma once

#include "conx2.h"

// the size of the screen
#define maxx 100
#define maxy 50

typedef struct _node node;
struct _node {
	node * next;
	COORD pos;
};

typedef struct _snake snake;
struct _snake {
	node * head;
	node * tail;
	int dir;
	int len;
	int pts;
};

void init(snake *, int, int, int[maxy][maxx]);

void move(int[maxy][maxx], snake *, COORD);

bool die(int[maxy][maxx], COORD);
