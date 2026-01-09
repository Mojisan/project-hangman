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

#include "model/hangman/hangman.h"

using namespace std;

int main()
{
  Hangman hangman;
  
  Category animal = hangman.importWords("words/animal.txt");
  Category english = hangman.importWords("words/englishpremierleague2018_2019.txt");

  Rule rule(10);

  Gameplay gameplay(rule, {animal, english});

  Controller controller(gameplay);
  View view(gameplay);

  while (gameplay.gameState != Gameplay::GameState::EXIT)
  {
    switch (gameplay.gameState)
    {
    case Gameplay::GameState::START:
    {
      gameplay.start();

      break;
    }

    case Gameplay::GameState::SELECT:
    {
      view.printCategorys();

      int categoryIndex = controller.inputIndexCategory();

      vector<Word> words = gameplay.selectCategory(categoryIndex);

      Word word = rule.randomWord(words);

      gameplay.setWord(word);

      break;
    }

    case Gameplay::GameState::PLAY:
    {
      char charInput;

      view.printHint();

      while (gameplay.isPlaying())
      {
        view.printGameStatus();

        charInput = controller.inputCharacter();

        if (rule.isAlreadyGuess(charInput, gameplay.currentCharacter))
        {
          view.printAlreadyGuess();

          continue;
        }

        gameplay.addCharacter(charInput);

        if (rule.isCorrect(charInput, gameplay.word->word))
        {
          gameplay.addScore();

          if (gameplay.word.has_value() &&
              rule.isWinning(gameplay.word.value(), gameplay.currentCharacter))
          {
            gameplay.setWin();

            break;
          }

          continue;
        }
        else
        {
          gameplay.currentGuessPoint = rule.decreaseGuess(gameplay.currentGuessPoint);

          if (rule.isLosing(gameplay.currentGuessPoint))
          {
            gameplay.setLose();

            break;
          }

          continue;
        }
      }

      break;
    }

    case Gameplay::GameState::END:
    {
      view.printEnding();

      gameplay.setExitGame();

      break;
    }

    default:
    {

      break;
    }
    }
  }

  return 0;
}
