game: cards main.cpp
	g++ main.cpp -c -o main.o
	g++ main.o cards.o -o game
	
cards: cards.cpp cards.h
	g++ cards.cpp  -c -o cards.o 

test: cards testcards.cpp testcards.h
	g++ testcards.cpp -c -o testcards.o
	g++ testcards.o cards.o -o testcards

