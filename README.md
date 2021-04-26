# Guess What?!

Guess What?! is a guessing game for developing problem solving skills though the process of elimination.

To compile the game itself, the attatched makefile is required. It makes sure to include all the necessary sfml modules (graphics, system, and window).

When the game launches, four categories will be displayed, each labeled "A Countries", "B Countries", "C Food", and "D Sports".
To select a category, press the corresponding key on your keyboard.

After a category is selected, a new window will open up displaying nine options, each numbered 1-9, and a hint.
You can either make a guess right away, or press "0" on the keypad to ask for another hint.
To make a guess, press the corresponding key on your keyboard.
If the guess is correct before any additional hints are given, you recieve 20 points.
Every hint you recieve after that depreciates your score for the round by 5 points.
After three hints, a guess must be made.
If at any point an incorrect guess is selected, the round immediately ends and the score for that round is 0.

There are 4 rounds in the game, and each category is able to be selected for mulitple rounds.
After 4 rounds, your score is displayed, minimum being 0 and maximum being 80.
