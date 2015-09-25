#include<iostream>
#include<fstream>

#define maximum_size 100

class mult_matrix
{
private:
	int row1, column1;
	int row2, column2;
	int matrix1[maximum_size][maximum_size];
	int matrix2[maximum_size][maximum_size];
public:
	mult_matrix(std::ifstream &input);
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
		mult_matrix lf(input);
		lf.calc();
	}
}




mult_matrix::mult_matrix(std::ifstream &input)
{
	input>>row1;
	input>>column1;
	row2=column1;
	input>>column2;
	for(int i =0; i<row1;i++)
	{
		for(int j=0; j<column1; j++)
		{
			input>>matrix1[i][j];
		}
	}
	for(int i =0; i<row2;i++)
	{
		for(int j=0; j<column2; j++)
		{
			input>>matrix2[i][j];
		}
	}
}

void mult_matrix::calc()
{
	int mult_matrix[maximum_size][maximum_size];
	int mult=0;
	for(int i=0; i<row1; i++)
	{
		for(int k=0; k<column2; k++)
		{
			for(int j=0; j< column1; j++)
			{
				mult+= matrix1[i][j]*matrix2[j][k];
			}
			mult_matrix[i][k]=mult;
			mult=0;
		}
		
	}

	for(int i=0; i<row1; i++)
	{
		for(int j=0; j<column2; j++)
		{
			std::cout<<mult_matrix[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
