#include <iostream>
#include <string>

#include "gameplay.h"

using namespace std;

void Gameplay::start()
{
  gameStage = GameStage::START;
  currentGuessPoint = rule.guessPoint;
  score = 0;
}

vector<Word> Gameplay::selectCategory(int categoryIndex)
{
  gameStage = GameStage::SELECT;

  vector<Word> words = categorys.at(categoryIndex).words;

  return words;
}

void Gameplay::readyToPlay()
{
}

int Gameplay::addScore(bool correct)
{
  return score += 5;
}

bool Gameplay::isEnding(bool ending)
{
  if (ending)
  {
    gameStage = GameStage::END;
    return true;
  }

  return false;
}

void Gameplay::setWord(Word randomWord) {
  word = randomWord;

  cout << word.value().word << endl;
}