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
  enum class GameState
  {
    START,
    SELECT,
    PLAY,
    END,
    EXIT
  };

  enum class GameResult
  {
    UNKNOWN,
    WIN,
    LOSE,
  };

  int score;
  int currentGuessPoint;
  optional<Word> word;
  vector<char> currentCharacter;
  GameState gameState;
  vector<Category> categorys;
  Rule rule;
  GameResult gameResult;

  Gameplay(Rule rule, vector<Category> categorys) : score(0), currentGuessPoint(0), word(), currentCharacter(), gameState(GameState::START), categorys(categorys), rule(rule), gameResult(GameResult::UNKNOWN)
  {
  }

  void start();

  vector<Word> selectCategory(int categoryIndex);

  void readyToPlay();

  int addScore();

  void setWord(Word randomWord);

  void setLose();

  void setWin();

  void addCharacter(char charInput);

  bool isPlaying();

  void setExitGame();
};

#endif