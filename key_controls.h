#ifndef KEY_CONTROLS_H
#define KEY_CONTROLS_H

#pragma once
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>

using namespace std;

class Controls {

public:
  int getch();
  bool kbhit();
};

#endif
