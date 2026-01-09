#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

#include "model/gameplay/gameplay.h"

using namespace std;

class Controller
{
public:
  Gameplay& gameplay;

  Controller(Gameplay& gameplay) : gameplay(gameplay) {}

  int inputIndexCategory();

  char inputCharacter();
};

#endif