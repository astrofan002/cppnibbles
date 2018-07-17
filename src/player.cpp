#include "player.h"

// initialized the snake as a single 'O'
void init(snake * player, int sx, int sy, int map[maxy][maxx]) {
	node * seed = (node *)malloc(sizeof(node));
	seed->next = NULL;
	seed->pos.X = sx;
	seed->pos.Y = sy;
	player->head = player->tail = seed;
	player->dir = 4;
	player->len = 1;
	player->pts = 1;
	map[sy][sx] = 1;
	gotoxy(sx, sy);
	printf("O");
};

void move(int map[maxy][maxx], snake * player, COORD newxy) {
	COORD curxy;

	node * New = (node *) malloc(sizeof(node));
	curxy = player->head->pos;
	
	// this one applied enqueueing a linked list
	New->next = NULL;
	New->pos = newxy;
	player->head->next = New;
	player->head = New;
	map[newxy.Y][newxy.X] = 1;
	if (player->len >= 2) {
		gotoxy(curxy.X, curxy.Y);
		printf("o");
	}
	gotoxy(newxy.X, newxy.Y);
	printf("0");
	
	if (player->pts == player->len) {
		// this one applied dequeueing
		node * old = player->tail;
		player->tail = player->tail->next;
		map[old->pos.Y][old->pos.X] = 0;
		gotoxy(old->pos.X, old->pos.Y);
		printf(" ");
		free(old);
	}
	else {
		player->len++;
	}
	return;
};

bool die(int map[maxy][maxx], COORD pos) {
	if (map[pos.Y][pos.X] == 1) {
		return TRUE;
	}
	else return FALSE;
};