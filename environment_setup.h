#ifndef ENVIRONMENT_SETUP_H
#define ENVIRONMENT_SETUP_H

#pragma once
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>

using namespace std;

class Environment {

private:
  const int width = 120;
  const int height = 40;
  int x, y, fruitX, fruitY, score;
  int tailX[100], tailY[100];
  int tailLength;
  enum Direction {
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
  };
  Direction dir;

public:
  bool gameOver;
  void setup();
  void draw();
  void input();
  void logic();
};

#endif
