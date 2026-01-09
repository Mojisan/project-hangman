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
  vector<Word> words;

  Category(string name, vector<Word> words) : name(name), words(words) {}

  void printCategoryName();
};

#endif