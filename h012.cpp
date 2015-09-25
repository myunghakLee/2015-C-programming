#include<iostream>
#include<fstream>

#define maximum 99

class diamond
{
private:
	char cell[maximum][maximum];
	int size;
public:
	diamond(std::ifstream& input);
	void calc();
};

void main()
{
	std::ifstream in_file;

	in_file.open("input.txt");

	int cases;

	in_file>>cases;
	for(int i=0; i<cases; i++)
	{
		diamond lf(in_file);
		lf.calc();

	}
}
diamond :: diamond(std::ifstream& input)
{
	input>>size;
}
void  diamond::calc()
{
	int n=size-1;
	////////////////////////////////////////////////////////첫줄부터 가운대줄 전까지//////////////////////////////////////////////////
	for(int i=0; i<size/2; i++)
	{
		for(int j=0; j < size; j++)
		{
			if(  ((j-i)>=0)&&(i+j<size))
			{
				if((j-i)%2==0)
				{
					cell[i][j]= '*';
				}
				else
				{
					cell[i][j]='+';
				}
			}
			else
			{
				cell[i][j]='-';
			}
		}
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////









	////////////////////////////////////////////////////////////////가운데줄 입력/////////////////////////////////////////////////
	for(int i = 0; i< size/2; i++)
	{
		cell[size/2][i]='-';
	}
	cell[size/2][size/2] = '*';
	for(int i = size/2+1; i< size; i++)
	{
		cell[size/2][i]='-';
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////









	////////////////////////////////////////////////////////가운데줄 다음부터 마지막줄까지//////////////////////////////////////////////////////
	for(int i=size/2+1; i<size; i++)
	{
		for(int j=0; j < size; j++)
		{
			if(  ( (j+i)>size-2)&&(j-i)<1 )
			{
				if((j-i)%2==0)
				{
					cell[i][j]= '*';
				}
				else
				{
					cell[i][j]='+';
				}
			}
			else
			{
				cell[i][j]='-';
			}
		}
	}



	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






	/////////////////////////////////////////////////////////////////출력//////////////////////////////////////////////////////
	for(int i=0; i<size; i++)
	{
		for(int j=0; j < size; j++)
		{
			std::cout<<cell[i][j];
		}
		std::cout<<std::endl;
	}



}