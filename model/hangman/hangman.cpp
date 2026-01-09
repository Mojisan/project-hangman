#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "model/word/word.h"
#include "model/category/category.h"
#include "model/rule/rule.h"
#include "model/gameplay/gameplay.h"
#include "hangman.h"

#include "view/view.h"

#include "controller/controller.h"

using namespace std;

Category Hangman::fileToCategory(string filename)
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

void Hangman::play()
{
  Category animal = fileToCategory("words/animal.txt");
  Category englishPremierLeague = fileToCategory("words/englishpremierleague2018_2019.txt");

  Rule rule(10);

  Gameplay gameplay(rule, {animal, englishPremierLeague});

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

      vector<Word> words = gameplay.getWords(categoryIndex);

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

            view.printGameStatus();

            break;
          }

          continue;
        }
        else
        {
          gameplay.currentGuessPoint = rule.decreaseGuessPoint(gameplay.currentGuessPoint);

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
};