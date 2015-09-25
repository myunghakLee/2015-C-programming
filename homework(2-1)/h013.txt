#include<iostream>
#include<fstream>

#define maximum 99

class straight_graph
{
private:
	char cell[maximum][maximum];
	int size;
public:
	straight_graph(std::ifstream& input);
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
		straight_graph lf(in_file);
		lf.calc();

	}
}
straight_graph :: straight_graph(std::ifstream& input)
{
	input>>size;
}
void  straight_graph::calc()
{
	int n=size-1;
	for(int i=0; i<size; i++)
	{
		for(int j=0; j < size; j++)
		{
			if( i== size/2 && j==size/2 )
			{
				cell[i][j] = 'O';
			}
			else if(i==size/2)
			{
				cell[i][j]='+';
			}
			else if(j==size/2)
			{
				cell[i][j]='I';
			}
			else if(i+j==size-1)
			{
				cell[i][j]='*';
			}
			else
			{
				cell[i][j]='.';
			}
		}
	}



	/////////////////////////////////////////////////////////////////Ãâ·Â//////////////////////////////////////////////////////
	for(int i=0; i<size; i++)
	{
		for(int j=0; j < size; j++)
		{
			std::cout<<cell[i][j];
		}
		std::cout<<std::endl;
	}



}