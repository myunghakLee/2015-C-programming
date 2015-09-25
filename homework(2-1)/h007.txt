#include<iostream>
#include<fstream>

#define maximum 100

class end_figure_calc
{
private:
	int number;
	int num[maximum];
public:
	end_figure_calc(std::ifstream& input);
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
		end_figure_calc lf(in_file);
		lf.calc();
		
	}
}
end_figure_calc ::end_figure_calc(std::ifstream& input)
{
	input>>number;
	for(int i=0; i<number; i++)
	{
		input>>num[i];
	}
}
void end_figure_calc::calc()
{
	int answer=1;
	for(int i=0; i<number; i++)
	{
		answer *= num[i]%10;
			answer %= 10;
	}
	std::cout<<answer<<std::endl;
}