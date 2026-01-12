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
  charInput = tolower(charInput);

  transform(word.begin(), word.end(), word.begin(), ::tolower);

  for (char character : word)
  {
    if (charInput == character)
    {
      return true;
    }
  }

  return false;
}

int Rule::decreaseGuessPoint(int currentGuessPoint)
{
  return --currentGuessPoint;
}

bool Rule::isAlreadyGuess(char charInput, vector<char> currentCharacters)
{
  charInput = tolower(charInput);

  for (char character : currentCharacters)
  {
    if (charInput == character)
    {
      return true;
    }
  }

  return false;
}

bool Rule::isWinning(Word word, vector<char> currentCharacters)
{
  for (char character : word.word)
  {
    if (isSameWord(character, currentCharacters))
      return false;
  }

  return true;
}

bool Rule::isSameWord(char character, vector<char> currentCharacters)
{
  return find(currentCharacters.begin(), currentCharacters.end(), character) == currentCharacters.end();
}

bool Rule::isLosing(int currentGuessPoint)
{
  return currentGuessPoint == 0;
}