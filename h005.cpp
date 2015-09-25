#include<iostream>
#include<fstream>

class integer_calc
{
private:
	int begin;
	int final;
public:
	integer_calc(std::ifstream& input);
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
		integer_calc lf(in_file);
		lf.calc();
		std::cout<<std::endl;
	}
	
}
integer_calc ::integer_calc(std::ifstream& input)
{
	input>>begin;
	input>>final;
}
void integer_calc::calc()
{
	
	std::cout<<(final+begin)*(final-begin+1)/2;
}