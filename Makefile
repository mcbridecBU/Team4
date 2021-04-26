# Copyright 2021 F. Alshammari fahed@bu.edu
# Copyright 2021 S. Deckers sebd@bu.edu
# Copyright 2021 C. McBride mcbridec@bu.edu
# Copyright 2021 J. Wang jaswang@bu.edu

all: game

game: game.cpp
	g++ game.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
