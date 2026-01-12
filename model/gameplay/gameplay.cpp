#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

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

int Gameplay::addScore(int point)
{
  return score += point;
}

void Gameplay::setWord(Word randomWord)
{
  originalWord = randomWord.word;
  randomWord.word = removeSpecialCharacter(originalWord);
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

string Gameplay::getRevealedWord(vector<char> currentCharacters, string word)
{
  string transformedWord;

  transform(word.begin(), word.end(), word.begin(), ::tolower);

  for (int count = 0; count < word.size(); count++)
  {
    char character = word[count];

    if (isalpha(static_cast<unsigned char>(character)))
    {
      if (hasCharacter(currentCharacters, character))
      {
        if (count == 0)
          transformedWord += toupper(character);
        else
          transformedWord += character;
      }
      else
      {
        transformedWord += '_';
      }
    }
    else
    {
      transformedWord += character;
    }

    if (count < word.size() - 1)
    {
      transformedWord += ' ';
    }
  }

  return transformedWord;
}

bool Gameplay::hasCharacter(vector<char> currentCharacters, char character)
{
  return find(currentCharacters.begin(), currentCharacters.end(), character) != currentCharacters.end();
}

string Gameplay::removeSpecialCharacter(string word)
{
  string transformedWord;

  for (char character : word)
  {
    if (isAlphabet(character))
    {
      transformedWord += tolower(static_cast<unsigned char>(character));
    }
  }

  return transformedWord;
}

bool Gameplay::isAlphabet(char character)
{
  return isalpha(static_cast<unsigned char>(character));
}