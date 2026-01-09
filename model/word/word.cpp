#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

#include "word.h"

using namespace std;

void Word::printWord()
{
  cout << word << endl;
}

string Word::removeSpecialCharacter()
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

bool Word::isAlphabet(char character)
{
  return isalpha(static_cast<unsigned char>(character));
}

bool Word::hasCharacter(vector<char> currentCharacters, int index)
{
  return find(currentCharacters.begin(), currentCharacters.end(), word[index]) != currentCharacters.end();
}

string Word::transformWord(vector<char> currentCharacters)
{
  string transformedWord;

  transform(word.begin(), word.end(), word.begin(), ::tolower);

  for (int count = 0; count < word.size(); count++)
  {
    if (hasCharacter(currentCharacters, count))
    {
      if (count == 0)
      {
        transformedWord += toupper(word[count]);
      }
      else
      {
        transformedWord += word[count];
      }
    }
    else
    {
      transformedWord += '_';
    }

    if (count < word.size() - 1)
    {

      transformedWord += ' ';
    }
  }

  return transformedWord;
}