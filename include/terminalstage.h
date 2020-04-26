#ifndef TERMINAL_STAGE_H
#define TERMINAL_STAGE_H

#include <ncurses.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Position {
  int x;
  int y;
} Position;

typedef struct Room {
  Position position;
  int height;
  int width;

  Position door[4];
  // Monster** monsters;
  // Item** items;
} Room;

typedef struct Player {
  Position position;
  int health;
} Player;

int screenSetUp();
Room** mapSetUp();
Player* playerSetup();
int handleInput(int input, Player * user);
int playerMove(int yPos, int xPos, Player* user);
int checkPosition(int newY, int newX, Player* user);
Room* createRoom(int y, int x, int height, int width, int yDoorDisplacement, int xDoorDisplacement);
int drawRoom(Room* room);

#endif
