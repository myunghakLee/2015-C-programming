#include<iostream>
#include<fstream>

#define maximum 99

class straight_graph
{
private:
	int dot1, dot2, dot3;
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
	input>>dot1;
	input>>dot2;
	input>>dot3;
}
void  straight_graph::calc()
{
	int triangle;
	if(dot3>=dot1+dot2)
	{
		triangle = 0;
	}
	else if(dot3==dot2 && dot2==dot1)
	{
		triangle = 1;
	}
	else if(dot3*dot3==dot2*dot2 + dot1*dot1)
	{
		triangle = 2;
	}
	else if(dot2==dot1 || dot2 == dot3 || dot1==dot3)
	{
		triangle = 3;
	}
	else
	{
		triangle = 4;
	}
	std ::cout<<triangle<<std::endl;
}