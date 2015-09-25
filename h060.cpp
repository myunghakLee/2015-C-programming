#include<iostream>
#include"problem60(head).h"

void main()
{
	char a[3];
	a[0] = '.';
	a[1] = '.';
	a[2] = 0;
	int cc = strcmp(a, "..");


	std::ifstream instream;
	instream.open("input.txt");

	int cases;
	instream >> cases;

	for (int i = 0; i < cases; i++)
	{
		mors mo(instream);
		mo.changing();
	}
}

