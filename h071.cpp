#include<iostream>
#include<fstream>
#include"problem71(head).h"

void main()
{
	std::ifstream instream;
	instream.open("input.txt");

	int cases;
	instream >> cases;
	for (int i = 0; i < cases; i++)
	{
		check_distance cl(instream);
		cl.calc();
		
	}
}

						
