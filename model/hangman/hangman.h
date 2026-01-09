#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>

#include "model/category/category.h"

using namespace std;

class Hangman
{
public:
  Hangman() {};

  Category importWords(string filename);

  void play();
};

#endif