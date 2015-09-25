#include<iostream>
#include<fstream>

#define maximum_size 100

int band[4*maximum_size];


class broken_diagonal
{
private:
	int volume;//크기
	int matrix[maximum_size][maximum_size];

public:
	broken_diagonal(std::ifstream & input)
	{
		input>> volume;
		for(int i=0; i<volume; i++)
		{
			for(int j=0; j<volume; j++)
			{
				input>>matrix[i][j];
			}
		}
	}
	void input_band();// 각 대각선의 합을 band배열에 넣음
	void calc();
};

void main()
{
	std::ifstream input;

	input.open("input.txt");

	int cases;
	input>>cases;

	for(int i=0; i<cases; i++)
	{
		broken_diagonal lf(input);
		lf.input_band();
		lf.calc();
	}
}

void broken_diagonal::input_band()
{
	for(int i=0; i<4*volume-2; i++)
	{
		band[i]=0;
	}

	for(int i=0;i<volume;i++)
	{
		for(int j=0; j< volume; j++)
		{
			for(int k=-volume+1; k<volume;k++)
			{
				if(i-j==k)
				{
					band[volume+i-j-1]+=matrix[i][j];
					break;
				}
			}
			for(int k=0; k<2*volume-1; k++)
			{
				if(i+j==k)
				{
					band[2*volume+i+j-1]+=matrix[i][j];
					break;
				}
			}
		}
	}
}

void broken_diagonal:: calc()
{
	int broken_diagonal[200];
	int maximum_broken_diagonal;
	 
	for(int i=0; i<volume; i++)
	{
		if(i==volume-1)
		{
			broken_diagonal[i]=band[i];
		}
		else
		{
			broken_diagonal[i]= band[i]+band[i+volume];
		}
	}

	for(int i= volume; i<2*volume; i++)
	{
		if(i==2*volume-1)
		{
			broken_diagonal[i]=band[i+volume-1];
		}
		else
		{
			broken_diagonal[i]= band[i+volume-1]+band[i+2*volume-1];
		}
	}
	
	maximum_broken_diagonal = broken_diagonal[0];
	
	for(int i=1; i<2*volume-1; i++)
	{
		maximum_broken_diagonal<broken_diagonal[i] ? maximum_broken_diagonal=broken_diagonal[i] : 0;
	}
	std::cout<<maximum_broken_diagonal<<std::endl;
}