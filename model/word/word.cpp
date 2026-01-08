#include <iostream>
#include <string>
#include <vector>

#include "word.h"

using namespace std;

void Word::printWord()
{
  cout << word << endl;
}

string Word::transformWord()
{
  return word;
}