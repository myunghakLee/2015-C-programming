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
	for(int i=0; i<size; i++)
	{
		for(int j=0; j < size; j++)
		{
			if(  ((i+j)>=n/2) && ((i+j)<=3*n/2) && ((j-i)<=n/2)&&((j-i)>=-n/2) )
			{
				cell[i][j]='+';
			}
			else
			{
				cell[i][j]='*';
			}
		}
	}
	for(int i=0; i<size; i++)
	{
		for(int j=0; j < size; j++)
		{
			std::cout<<cell[i][j];
		}
		std::cout<<std::endl;
	}



}