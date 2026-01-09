#ifndef VIEW_H
#define VIEW_H

#include <string>

#include "model/gameplay/gameplay.h"

using namespace std;

class View
{
public:
  Gameplay& gameplay;

  View(Gameplay& gameplay) : gameplay(gameplay) {}

  void printCategorys();

  void printHint();

  void printScore();

  void printGameStatus();

  void printAlreadyGuess();

  void printEnding();
};

#endif