#ifndef WORD_H
#define WORD_H

#include <string>

using namespace std;

class Word
{
public:
  enum class CategoryType
  {
    ANIMAL,
    ENGLISH_PREMIER_LEAGUE_2018_2019,
  };

  string word;
  string hint;
  CategoryType category;

  Word(string word, string hint, CategoryType category) : word(word), hint(hint), category(category) {}

  void printWord();

  string transformWord();
};

#endif
