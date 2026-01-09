#ifndef WORD_H
#define WORD_H

#include <string>
#include <vector>

using namespace std;

class Word
{
public:
  string word;
  string hint;
  string category;

  Word(string word, string hint, string category) : word(word), hint(hint), category(category) {}

  void printWord();

  string removeSpecialCharacter();

  bool isAlphabet(char character);

  string transformWord(vector<char> characters);
};

#endif
