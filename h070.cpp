#include"problem70(head).h"

void main()
{
	ifstream instream;
	instream.open("input.txt");
	int cases;

	instream >> cases;

	for (int i = 0; i < cases; i++)
	{
		digital_clock di(instream);
		di.calc();
	}


}

						
