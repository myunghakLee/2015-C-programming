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
	int sum_divisor=0;//약수의 합
	int num_divisor=0;//약수의 개수

	for(int i=1; i<num; i++)
	{
		if(num%i==0)
		{
			num_divisor++;
			sum_divisor += i;
		}
	}
	std::cout<<num_divisor<<" "<<sum_divisor<<std::endl;
}