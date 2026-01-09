#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "rule.h"
#include "model/word/word.h"

using namespace std;

Word Rule::randomWord(vector<Word> words)
{
  srand(time(0));

  int randomIndex = rand() % words.size();

  return words[randomIndex];
}

char Rule::inputCharacter(char character)
{
  return character;
}

bool Rule::isCorrect(char charInput, string word)
{
  transform(word.begin(), word.end(), word.begin(), ::tolower);

  charInput = tolower(charInput);

  for (char character : word)
  {
    if (charInput == character)
    {
      return true;
    }
  }

  return false;
}

int Rule::decreaseGuess(int guessPoint)
{
  return --guessPoint;
}

bool Rule::isAlreadyGuess(char charInput, vector<char> currentWord)
{
  charInput = tolower(charInput);

  for (char character : currentWord)
  {
    if (charInput == character)
    {
      return true;
    }
  }

  return false;
}

bool Rule::isWinning(Word word, vector<char> currentCharacter)
{
  for (char character : word.word)
  {
    if (find(currentCharacter.begin(), currentCharacter.end(), character) == currentCharacter.end())
      return false;
  }

  return true;
}

bool Rule::isLosing(int currentGuessPoint)
{
  return currentGuessPoint == 0;
}