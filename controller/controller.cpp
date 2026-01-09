#include <iostream>
#include <string>

#include "controller.h"

using namespace std;

int Controller::inputIndexCategory()
{
  int index;

  while (true)
  {
    cin >> index;

    if (gameplay.categorys.size() > index - 1 && index > 0)
    {
      return index - 1;
    }
    else
    {
      cout << "Category not found. Please try again" << endl;
    }
  }
}

char Controller::inputCharacter()
{
  string character;

  cin >> character;

  return character[0];
}