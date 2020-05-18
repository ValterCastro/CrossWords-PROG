#include "ConsoleColorer.h"

ConsoleColorer::ConsoleColorer(){};

void ConsoleColorer::setColorAndBackground(unsigned int color,
                                           unsigned int background_color) {
  HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

  if (background_color == BLACK)
    SetConsoleTextAttribute(hCon, color);
  else
    SetConsoleTextAttribute(
        hCon, color | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}