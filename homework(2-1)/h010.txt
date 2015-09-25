#include<iostream>
#include<fstream>

void main()
{
	std::ifstream input;

	int cases;
	int cell=0;
	int volum;

	input.open("input.txt");

	input>>cases;
	for(int z = 0; z<cases; z++)
	{
		input>>volum;
		for(int i = 0 ; i<volum; i++)
		{
			cell=i+1;
			for(int j = 0; j<i+1;j++)
			{
				std::cout<<cell<<" ";
				cell+=volum-j-1;
			}
			std::cout<<std::endl;
		}
	}
}