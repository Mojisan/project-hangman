#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <vector>

#include "model/word/word.h"

using namespace std;

class Category
{
public:
  string name;
  Word::CategoryType type;
  vector<Word> words;

  Category(string name, Word::CategoryType type, vector<Word> words) : name(name), type(type), words(words) {}

  void printCategoryName();
};

#endif