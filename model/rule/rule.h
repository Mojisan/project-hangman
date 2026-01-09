#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>

#include "model/category/category.h"
#include "model/word/word.h"

using namespace std;

class Rule
{
public:
  int guessPoint;

  Rule(int guessPoint) : guessPoint(guessPoint) {}

  Word randomWord(vector<Word> words);

  char inputCharacter(char character);

  bool isCorrect(char charInput, string word);

  int decreaseGuess(int guessPoint);

  bool isAlreadyGuess(char charInput, vector<char> currentWord);

  bool isWinning(Word word, vector<char> currentWord);

  bool isLosing(int currentGuessPoint);
};

#endif