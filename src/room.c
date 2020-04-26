#include "terminalstage.h"

Room* createRoom(int yPos, int xPos, int height, int width, int yDoorDisplacement, int xDoorDisplacement) {
  Room* newRoom;
  newRoom = malloc(sizeof(Room));


  newRoom->position.x = xPos;
  newRoom->position.y = yPos;
  newRoom->height = height;
  newRoom->width = width;

  assert(yDoorDisplacement < height);
  assert(xDoorDisplacement < width);
  assert((xDoorDisplacement != 0) ? (yDoorDisplacement == 0 || yDoorDisplacement == height) : 1);
  assert((yDoorDisplacement != 0) ? (xDoorDisplacement == 0 || xDoorDisplacement == width) : 1);
  newRoom->door[0].x = xPos + (xDoorDisplacement * 2);
  newRoom->door[0].y = yPos + yDoorDisplacement;

  return newRoom;
}

int drawRoom(Room* room) {
  int x;
  int y;

  // Draw top and bottom walls
  for (x = room->position.x; x < room->position.x + ((room->width) * 2); x+=2) {
    mvprintw(room->position.y, x, "[");
    mvprintw(room->position.y, x + 1, "]");

    mvprintw(room->position.y + room->height + 1, x, "[");
    mvprintw(room->position.y + room->height + 1, x + 1, "]");
  }

  // Draw side walls
  for (y = room->position.y + 1; y < room->position.y + room->height + 1; y++) {
    mvprintw(y, room->position.x, "[");
    mvprintw(y, room->position.x + 1, "]");

    mvprintw(y, room->position.x + (room->width * 2) - 2, "[");
    mvprintw(y, room->position.x + (room->width * 2) - 1, "]");

    for (x = room->position.x + 2; x < room->position.x + ((room->width -1) * 2); x++) {
      mvprintw(y, x, ".");
    }
  }

  // Draw doors
  mvprintw(room->door[0].y, room->door[0].x, "/");
  mvprintw(room->door[0].y, room->door[0].x + 1, " ");

  return 1;
}
