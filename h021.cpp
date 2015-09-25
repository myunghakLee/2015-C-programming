#include<iostream>
#include<fstream>

class divisor
{
private:
	int num;
public:
	divisor(std::ifstream& input)
	{
		input>>num;
	}
	void calc();
};

void main()
{
	std::ifstream file;

	file.open("input.txt");

	int cases;
	file>>cases;

	for(int i = 0; i< cases; i++)
	{
		divisor lf(file);
		lf.calc();
	}
}

void divisor::calc()
{

	int num_divisor=0;//약수의 개수

	for(int i=2; i<num; i++)
	{
		if(num%i==0)
		{
			num_divisor++;
		
		}
	}
	if(num_divisor==0)
	{
	std::cout<<"1"<<std::endl;
	}
	else
	{
	std::cout<<"0"<<std::endl;
	}
}