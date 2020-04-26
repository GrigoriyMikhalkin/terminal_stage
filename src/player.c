#include "terminalstage.h"

Player * playerSetup() {
  Player * newPlayer;
  newPlayer = malloc(sizeof(Player));

  newPlayer->position.x = 18;
  newPlayer->position.y = 15;
  newPlayer->health = 5;

  mvprintw(newPlayer->position.y, newPlayer->position.x, "@");
  move(newPlayer->position.y, newPlayer->position.x);

  return newPlayer;
}

int handleInput(int input, Player * user) {
  int newX;
  int newY;

  switch (input) {
    /* Move up */
    case 'w':
    case 'W':
      newY = user->position.y - 1;
      newX = user->position.x;
      break;

    /* Move down */
    case 's':
    case 'S':
      newY = user->position.y + 1;
      newX = user->position.x;
      break;

    /* Move left */
    case 'a':
    case 'A':
      newY = user->position.y;
      newX = user->position.x - 1;
      break;

    /* Move right */
    case 'd':
    case 'D':
      newY = user->position.y;
      newX = user->position.x + 1;
      break;
  }

  checkPosition(newY, newX, user);
}

int playerMove(int yPos, int xPos, Player * user) {
  mvprintw(user->position.y, user->position.x, ".");

  user->position.y = yPos;
  user->position.x = xPos;
  mvprintw(user->position.y, user->position.x, "@");
  move(user->position.y, user->position.x);

}

int checkPosition(int newY, int newX, Player * user) {
  int space;
  switch (mvinch(newY, newX)) {
    case '.':
    case '/':
    case ' ':
      playerMove(newY, newX, user);
      break;

    case '[':
    case ']':
      break;
  }
}
