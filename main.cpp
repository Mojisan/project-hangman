#include <iostream>
#include <string>

#include "model/word/word.h"
#include "model/category/category.h"
#include "model/rule/rule.h"
#include "model/gameplay/gameplay.h"

using namespace std;

int main()
{
  Word word1("Dog", "Pet", Word::CategoryType::ANIMAL);
  Word word2("Cat", "Pet", Word::CategoryType::ANIMAL);
  Word word3("Bird", "Pet", Word::CategoryType::ANIMAL);
  Word word4("Ramos", "Spain", Word::CategoryType::ENGLISH_PREMIER_LEAGUE_2018_2019);
  Word word5("Rama", "Sponge", Word::CategoryType::ENGLISH_PREMIER_LEAGUE_2018_2019);

  Category animal("Animal", Word::CategoryType::ANIMAL, {word1, word2, word3});
  Category football("Football", Word::CategoryType::ENGLISH_PREMIER_LEAGUE_2018_2019, {word4, word5});

  Rule rule(10);

  Gameplay gameplay(rule, {animal, football});

  cout << word1.word << endl;

  return 0;
}
