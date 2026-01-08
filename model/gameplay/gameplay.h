#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <string>
#include <optional>

#include "model/word/word.h"
#include "model/rule/rule.h"

using namespace std;

class Gameplay
{
public:
  enum class GameStage
  {
    START,
    SELECT,
    PLAY,
    END
  };

  int score;
  int currentGuessPoint;
  optional<Word> word;
  vector<char> currentWord;
  GameStage gameStage;
  vector<Category> categorys;
  Rule rule;

  Gameplay(Rule rule, vector<Category> categorys) : score(0), currentGuessPoint(0), word(), currentWord(), gameStage(GameStage::START), categorys(categorys), rule(rule) {}

  void start();

  vector<Word> selectCategory(int categoryIndex);

  void readyToPlay();

  int addScore(bool correct);

  bool isEnding(bool ending);

  void setWord(Word randomWord);
};

#endif