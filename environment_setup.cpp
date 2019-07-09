#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include "key_controls.h"
#include "environment_setup.h"

using namespace std;

Controls c;

void Environment::setup() {
  gameOver = false;
  dir = STOP;
  x = width / 2;
  y = height / 2;
  fruitX = rand() % width;
  fruitY = rand() % height;
  score = 0;
}

void Environment::draw() {
  system("clear");
  for (int i = 0; i < width + 2; i++) {
    cout << "*";
  }
  cout << endl;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (j == 0) {
        cout << "*";
      }
      // cout << " ";
      if (i == y && j == x) {
        cout << "O";
      } else if (i == fruitY && j == fruitX) {
        cout << "+";
      } else {
        bool printed = false;
        for (int k = 0; k < tailLength; k++) {
          if (tailX[k] == j && tailY[k] == i) {
            cout << "o";
            printed = true;
          }
        }
        if (!printed) {
          cout << " ";
        }
      }
      if (j == width - 1) {
        cout << "*";
      }
    }
    cout << endl;
}
  for (int i = 0; i < width + 2; i++) {
    cout << "*";
  }
  cout << endl;
  cout << "Score: " << score << endl;
}

void Environment::input() {
  if (c.kbhit()) {
    switch (c.getch()) {
      case 'a': dir = LEFT;
      break;
      case 'd': dir = RIGHT;
      break;
      case 'w': dir = UP;
      break;
      case 's': dir = DOWN;
      break;
      case 'x': gameOver = true;
      break;
    }
  }
}

void Environment::logic() {
  int prevX = tailX[0];
  int prevY = tailY[0];
  int prev_x, prev_y;
  tailX[0] = x;
  tailY[0] = y;
  for (int i = 1; i < tailLength; i++) {
    prev_x = tailX[i];
    prev_y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = prev_x;
    prevY = prev_y;
  }

  // handling movement
  switch (dir) {
    case LEFT: x--;
    break;
    case RIGHT: x++;
    break;
    case UP: y--;
    break;
    case DOWN: y++;
    break;
    default:
    break;
  }

  // going out of bounds
  if (x >= width || x <= 0 || y >= height || y <= 0) {
    gameOver = true;
  }
  for (int i = 0; i < tailLength; i++) {
    if (tailX[i] == x && tailY[i] == y) {
      gameOver = true;
    }
  }

  // fruit eaten
  if (x == fruitX && y == fruitY) {
    tailLength++;
    score++;
    fruitX = rand() % width;
    fruitY = rand() % height;
  }
}
