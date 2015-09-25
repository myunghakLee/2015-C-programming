#include<iostream>
#include<fstream>
#include"problme58(head).h"

void main()
{
	std::ifstream instream;

	instream.open("input.txt");

	int cases;
	
	
	instream >> cases;
	for (int i = 0; i < cases; i++)
	{
		read_number re(instream);
		re.reading();
	}

}

