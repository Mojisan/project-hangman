#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

#include "view.h"

using namespace std;

void View::printCategorys()
{
  Category firstCategory = *gameplay.categorys.begin();

  vector<Category> categorys = gameplay.categorys;

  cout << "Select Category:" << endl;

  for (int count = 0; count < categorys.size(); count++)
  {
    int index = count + 1;
    string name = categorys[count].name;

    cout << index << '.' << name << endl;
  }
}

void View::printHint()
{
  if (gameplay.word)
  {
    cout << "Hint: " << gameplay.word->hint << endl;
  }
  else
  {
    cout << "Word not found" << endl;
  }
}

void View::printScore()
{
  cout << gameplay.score << endl;
}

void View::printGameStatus()
{
  cout << gameplay.getRevealedWord(gameplay.currentCharacter, gameplay.originalWord);

  cout << "  score  " << gameplay.score << ", remaining incorrect guess " << gameplay.currentGuessPoint << endl;
}

void View::printAlreadyGuess()
{
  cout << "already guessed" << endl;
}

void View::printEnding()
{
  if (gameplay.gameResult == Gameplay::GameResult::WIN)
  {
    cout << "you win!! score : " << gameplay.score << endl;
  }
  else if (gameplay.gameResult == Gameplay::GameResult::LOSE)
  {
    cout << "you lose!! score : " << gameplay.score << endl;
  }
}