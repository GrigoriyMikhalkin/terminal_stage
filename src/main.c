#include "terminalstage.h"

int main () {
  int ch;
  Player * user;

  screenSetUp();
  mapSetUp();

  user = playerSetup();
  while ((ch = getch()) != 'q') {
    handleInput(ch, user);
  }

  endwin();

  return 0;
}

int screenSetUp() {
  initscr();
  printw("Hello wrld!");
  noecho();
  refresh();

  return 0;
}

Room** mapSetUp() {
  Room** rooms;
  rooms = malloc(sizeof(Room) * 3);

  int yPos = 3;
  int xPos = 2;
  rooms[0] = createRoom(yPos, xPos, 3, 7, 0, 3);
  drawRoom(rooms[0]);

  yPos = 13;
  xPos = 12;
  rooms[1] = createRoom(yPos, xPos, 3, 7, 0, 3);
  drawRoom(rooms[1]);

  yPos = 20;
  xPos = 19;
  rooms[2] = createRoom(yPos, xPos, 3, 7, 0, 3);
  drawRoom(rooms[2]);

  return rooms;
}
