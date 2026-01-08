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
  return guessPoint--;
}

bool Rule::isAlreadyGuess(char charInput, vector<char> currentWord)
{
  for (char character : currentWord)
  {
    if (charInput == character)
    {
      return true;
    }
  }

  return false;
}

bool isWinning(Word word, vector<char> currentWord)
{
  return false;
}