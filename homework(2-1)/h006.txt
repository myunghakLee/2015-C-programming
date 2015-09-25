#include<iostream>
#include<fstream>

class integer_calc
{
private:
	int n;
	int num[10000];
public:
	integer_calc(std::ifstream& input);
	void big_small();
};

void main()
{
	std::ifstream in_file;

	in_file.open("input.txt");

	int cases;
	
	in_file>>cases;
	for(int i=0; i<cases; i++)
	{
		integer_calc lf(in_file);
		lf.big_small();
	
	}
	
}	
integer_calc ::integer_calc(std::ifstream& input)
{
	input>>n;
	for(int i=0; i<n;i++)
	{
		input >>num[i];
	}
}
void integer_calc::big_small()
{
	int big_number=num[0];
	int small_number=num[0];

	for(int i=0; i<n-1;i++)
	{
		if(big_number<num[i+1])
		{
			big_number=num[i+1];
		}
		else if(small_number>num[i+1])
		{
			small_number = num[i+1];
		}
		
	}
	std::cout<<big_number<<" "<<small_number<<std :: endl;
}