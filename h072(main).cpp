#include<iostream>
#include"problem72(head).h"


void main()
{
	std::ifstream instream;

	int cases;

	instream.open("input.txt");
	instream >> cases;

	for (int i = 0; i < cases; i++)
	{
		cross_line cr(instream);
		cr.check();

	}
}

						
