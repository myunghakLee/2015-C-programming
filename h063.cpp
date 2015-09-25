#include<iostream>
#include"problem63(head).h"



void main()
{
	std::ifstream instream;

	instream.open("input.txt");

	int cases;
	instream >> cases;
	for (int i = 0; i < cases; i++)
	{
		magic_square ma(instream);
		ma.make_magic_square();
		ma.print_magic_square();
	}
}









						
