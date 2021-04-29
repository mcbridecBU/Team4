# Guess What?! ReadME

"Guess What?!" is a guessing game for developing problem solving skills though the process of elimination. The program could also be used as a study tool by editing the categories in the game.cpp file. 

The files that must be downloaded to runt he program are:
1) "game.cpp"
2) "Makefile"
3) "highscore.txt"

To compile the game itself, the attatched makefile is required. It makes sure to include all the necessary sfml modules (graphics, system, and window).
1) Ensure that makefile is in the same directory as the game.cpp file.
2) Navigate to the directory using a terminal window.
3) Type "make game" to compile the program. This will make an executable titled "GuessWhat".

To launch the executable:
1) Ensure that the executable "GuessWhat" and txt file "highscore.txt" are in your current directory.
2) Enter "GuessWhat" into the terminal.
3) Play the game.

To reset the highscore:
1) Open the "highscore.txt" file.
2) Using a text editing program change the number to 0.
3) Anything entered other than a number may lead to failure of the program.


Gameplay
When the game launches, an instructions page will appear. Press enter to start the game.
Once the player presses enter, four categories will be displayed, each labeled "A Animals", "B Countries", "C Food", and "D Sports".
To select a category, press the corresponding key on your keyboard.

After a category is selected, a new window will open up displaying a hint with nine options, each numbered 1-9.
You can either make a guess right away, or press "0" on the keypad to ask for another hint.
To make a guess, press the corresponding key on your keyboard.
If the guess is correct before any additional hints are given, you recieve 15 points.
Every hint you recieve after that depreciates your score for the round by 5 points.
After three hints, a guess must be made.
If at any point an incorrect guess is selected, the round immediately ends and the score for that round is 0.
When the guess is made a screen will pop up informing the player if their guess was correct or not. 

There are 4 rounds in the game, and any category can be selected for each round.
After 4 rounds, your score will be displayed, minimum being 0 and maximum being 60.
If the high score is beat, the current score will become the new score and will be saved into the text file. There are two possible end screens, one for if the high score is beat and one for if not. Both give an option to play again. 
