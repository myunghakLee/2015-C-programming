#include <iostream>
#include <fstream>
#include"problem61(head).h"

void main()
{
	std::ifstream instream;
	
	instream.open("input.txt");
	
	int cases;

	instream >> cases;

	for (int i = 0; i<cases; i++)
	{
		LIFE_GAME game(instream);
		game.play();
	}
}

						
