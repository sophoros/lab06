final: go_fish.o deck.o card.o player.o
	g++ -otest go_fish.o deck.o card.o player.o
driver: go_fish.cpp deck.h card.h player.h
	g++ -std=c++11 -std=c++0x -c go_fish.cpp
deck.o: deck.cpp deck.h card.h
	g++ -std=c++11 -std=c++0x -c deck.cpp
card.o: card.cpp card.h
	g++ -std=c++11 -std=c++0x -c card.cpp
player.o: player.cpp player.h card.h
	g++ -std=c++11 -std=c++0x -c player.cpp