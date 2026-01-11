#include <iostream>
#include <vector>

#include "gameplay.h"
#include "model/word/word.h"

using namespace std;

void Gameplay::start()
{
  gameState = GameState::START;

  currentGuessPoint = rule.guessPoint;
  score = 0;

  gameState = GameState::SELECT;
}

vector<Word> Gameplay::getWords(int categoryIndex)
{
  vector<Word> words = categorys.at(categoryIndex).words;

  return words;
}

int Gameplay::addScore()
{
  return score += 5;
}

void Gameplay::setWord(Word randomWord)
{
  originalWord = randomWord.word;
  randomWord.word = randomWord.removeSpecialCharacter();

  word = randomWord;

  gameState = GameState::PLAY;
}

void Gameplay::setLose()
{
  gameResult = GameResult::LOSE;
  gameState = GameState::END;
}

void Gameplay::setWin()
{
  gameResult = GameResult::WIN;
  gameState = GameState::END;
}

void Gameplay::addCharacter(char charInput)
{
  charInput = tolower(charInput);

  currentCharacter.push_back(charInput);
}

bool Gameplay::isPlaying()
{
  return currentGuessPoint >= 0 || gameState != GameState::PLAY;
}

void Gameplay::setExitGame()
{
  gameState = GameState::EXIT;
}