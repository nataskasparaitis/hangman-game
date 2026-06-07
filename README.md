# Hangman Game (Lithuanian)

A console-based Hangman game written in C. The player guesses letters to reveal a hidden word chosen from three difficulty levels. The game saves progress, prevents repeating the same word within a difficulty level, and calculates a performance score based on the number of wrong guesses.

## Features

* Three difficulty levels:

  * Easy
  * Medium
  * Hard
* Random word selection without repetition within each difficulty level
* Progress saving and loading
* Tracks guessed letters to prevent duplicate guesses
* Score calculation based on word length and wrong guesses
* Average score displayed after multiple rounds
* Option to play again after each completed word

## Requirements

* GCC or another C compiler
* Standard C libraries:

  * `stdio.h`
  * `stdlib.h`
  * `string.h`
  * `time.h`

## Files

| File            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| `main.c`        | Main game loop, menu, and progress handling                  |
| `funkcijos.c`   | Core game functions (saving, difficulty selection, guessing) |
| `funkcijos.h`   | Struct definitions and function prototypes                   |
| `easy.txt`      | Word list containing words up to 5 letters                   |
| `medium.txt`    | Word list containing words from 6 to 8 letters               |
| `hard.txt`      | Word list containing words with 8 or more letters            |
| `progresas.txt` | Auto-generated save file storing game progress               |

## Compilation

Compile all source files together:

```bash
gcc main.c funkcijos.c -o hangman
```

Alternatively, you can create and use a Makefile.

## How to Play

### Run the Game

```bash
./hangman
```

If a saved game exists, the program automatically loads it and continues where you left off.

### Select Difficulty

When starting a new game, choose one of the following:

* `easy` - words up to 5 letters
* `medium` - words from 6 to 8 letters
* `hard` - words with 8 or more letters

### Gameplay

* The selected word is displayed as underscores (`_`).
* Guess one letter at a time.
* Correct guesses reveal all matching letters.
* Incorrect guesses reduce your score.
* The round ends when the entire word is revealed.

### Replay

After completing a word:

* You can choose to play another round.
* Previously solved words are not selected again within the same difficulty level.
* After all rounds, the game displays your average score.

## Score Calculation

### Formula

* The score starts at a base of 23 points.
* Each guess (correct or incorrect) reduces the base by 1.
* The final percentage is calculated as:

```text
score = ((23 - total_guesses) / (23 - word_length)) * 100
```

* For a perfect game (no incorrect guesses), you get 100%.
* The more extra guesses you make, the lower your score.
* If you reach 23 total guesses, your score becomes 0%.

## Save File (`progresas.txt`)

The save file stores:

* Current difficulty level
* Current hidden word
* Current revealed progress
* Previously guessed letters
* Number of solved words per difficulty
* Number of wrong guesses
* Total accumulated score
* Previously used word indexes (0-9) for each difficulty

The game automatically:

* Saves after every guess
* Loads progress when starting


All prompts are displayed in Lithuanian.

## Notes

* Word lists contain Lithuanian words without diacritics (e.g. `burna`, `tiesa`).
* Input is case-sensitive and should be entered in lowercase.
* The game uses fixed-size buffers and does not support words longer than 10 characters.
* If a difficulty file is missing, the program exits with an error message.

## Possible Improvements

* Support Lithuanian letters with diacritics (`ą`, `č`, `ę`, `ė`, `į`, `š`, `ų`, `ū`, `ž`)
* Support longer words using dynamically allocated memory
* Add ASCII-art hangman graphics
* Add multiplayer mode
* Store highscores in a separate file
* Add difficulty statistics and leaderboards
