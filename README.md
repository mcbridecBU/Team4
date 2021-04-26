# Guess What?!

Guess What?! is a guessing game for developing problem solving skills though the process of elimination.

To compile the game itself, the attatched makefile is required. It makes sure to include all the necessary sfml modules (graphics, system, and window).
1) Ensure that makefile is in the same directory as the game.cpp file.
2) Navigate to the directory using a terminal window.
3) Type "make game" to compile the program. This will make an executable titled "game".
4) To launch the executable, type "game" into the terminal.

When the game launches, four categories will be displayed, each labeled "A Animals", "B Countries", "C Food", and "D Sports".
To select a category, press the corresponding key on your keyboard.

After a category is selected, a new window will open up displaying a hint with nine options, each numbered 1-9.
You can either make a guess right away, or press "0" on the keypad to ask for another hint.
To make a guess, press the corresponding key on your keyboard (note - keypad numbers are not currently supported).
If the guess is correct before any additional hints are given, you recieve 15 points.
Every hint you recieve after that depreciates your score for the round by 5 points.
After three hints, a guess must be made.
If at any point an incorrect guess is selected, the round immediately ends and the score for that round is 0.

There are 4 rounds in the game, and any category can be selected for each round.
After 4 rounds, your score will be displayed, minimum being 0 and maximum being 60.
