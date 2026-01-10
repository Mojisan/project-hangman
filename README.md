# project-hangman

### How to build the program

Build in Terminal or PowerShell

```
g++ -std=c++17 -I. `
main.cpp `
model/word/word.cpp `
model/category/category.cpp `
model/rule/rule.cpp `
model/gameplay/gameplay.cpp `
view/view.cpp `
controller/controller.cpp `
model/hangman/hangman.cpp `
-o game
```

Build in Bash or MSYS2

```
g++ -std=c++17 -I. \
main.cpp \
model/word/word.cpp \
model/category/category.cpp \
model/rule/rule.cpp \
model/gameplay/gameplay.cpp \
view/view.cpp \
controller/controller.cpp \
model/hangman/hangman.cpp \
-o game

```

### How to run the program

Run in Command line

`./game`

### How to play hangman game

1.  Select a category by entering its number.

```
Select Category:
1.Animal Name
2.English Premier League 2018/2019 Team
```

2.  Command line will show hint of word.

```
Hint: Hen
_ _ _ _ _ _ _  score  0, remaining incorrect guess 10
```

3.  Enter a character to guess and see the result.

```
_ _ _ _ _ _ _  score  0, remaining incorrect guess 10
H
_ h _ _ _ _ _  score  5, remaining incorrect guess 10
k
_ h _ _ k _ _  score  10, remaining incorrect guess 10
g
_ h _ _ k _ _  score  10, remaining incorrect guess 9
```

- You can guess up to 10 times.
- The game supports case-sensitive input.
- Already guessed characters are supported.

4.  If you win or lose, the command line will display your score like this:

```
C h i c k e n  score  30, remaining incorrect guess 9
you win!! score : 30
```

Hope you enjoy it!
