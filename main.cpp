#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include "environment_setup.h"

using namespace std;

int main() {
  Environment env;

  env.setup();
  while(!env.gameOver) {
    env.draw();
    env.input();
    env.logic();
  }
  return 0;
}
