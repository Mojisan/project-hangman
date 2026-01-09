#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "model/word/word.h"
#include "model/category/category.h"
#include "model/rule/rule.h"
#include "model/gameplay/gameplay.h"
#include "model/hangman/hangman.h"

#include "view/view.h"

#include "controller/controller.h"

using namespace std;

Category Hangman::importWords(string filename)
{
  ifstream file(filename);
  vector<Word> words;

  if (!file)
  {
    cout << "Cannot open file\n";
    return Category("-", {});
  }

  string header;
  getline(file, header);

  string line;

  getline(file, line);

  while (getline(file, line))
  {
    stringstream ss(line);
    string word, hint;

    getline(ss, word, ',');
    getline(ss, hint);

    Word newWord(word, hint, header);

    words.push_back(newWord);
  }

  Category category(header, words);

  file.close();
  return category;
}

void Hangman::play() {

};