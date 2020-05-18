#ifndef CONSOLE_COLORER_H
#define CONSOLE_COLORER_H

// PROG - MIEIC - JAS
#include <windows.h>

#include <cstdlib>
#include <ctime>
#include <iostream>

// COLOR CODES:
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

// Responsible for coloring console
class ConsoleColorer {
 public:
  ConsoleColorer();

  void static setColorAndBackground(unsigned int color,
                                    unsigned int background_color);
};

#endif