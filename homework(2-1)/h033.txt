#include<iostream>
#include<fstream>

#define maximum_size 100

class sum_matrix
{
private:
	int row, column;
	int matrix1[maximum_size][maximum_size];
	int matrix2[maximum_size][maximum_size];
public:
	sum_matrix(std::ifstream &input);
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
		sum_matrix lf(input);
		lf.calc();
	}
}




sum_matrix::sum_matrix(std::ifstream &input)
{
	input>>row;
	input>>column;

	for(int i =0; i<row;i++)
	{
		for(int j=0; j<column; j++)
		{
			input>>matrix1[i][j];
		}
	}
	for(int i =0; i<row;i++)
	{
		for(int j=0; j<column; j++)
		{
			input>>matrix2[i][j];
		}
	}
}

void sum_matrix::calc()
{
	int sum_matrix[maximum_size][maximum_size];
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
		{
			sum_matrix[i][j]=matrix1[i][j]+matrix2[i][j];	
		}
	}

	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
		{
			std::cout<<sum_matrix[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
