#ifndef __magic_square__
#define __magic_square__

#include<iostream>
#include<fstream>
class magic_square
{
private:
	int volume;
	int arr[50][50];
public:
	magic_square(std::ifstream & instream)
	{
		instream >> volume;
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				arr[i][j] = -1;
			}
		}
	}
	void make_magic_square();
	void print_magic_square();
};




#endif

						
