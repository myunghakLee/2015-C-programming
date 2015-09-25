#include<iostream>
#include<fstream>


class calc
{
private:
	int num1, num2;
public:
	calc(std::ifstream& input);
	void plus();
	void minus();
	void mult();
	void division();
	void big_number();
	void equel();

};

int main()
{
	std ::ifstream input;


	input.open("input.txt");
	int cases;

	input>>cases;

	for(int i=0; i<cases; i++)
	{
		calc lf(input);

		lf.plus();
		lf.minus();
		lf.mult();
		lf.division();
		lf.big_number();
		lf.equel();
		std::cout<<std::endl;
	}
	return 0;
}



calc ::calc(std::ifstream& input)
{
	input>>num1;
	input>>num2;
}

void calc::plus()
{
	std::cout<<num1+num2<<" ";
}
void calc::minus()
{
	std::cout<<num1-num2<<" ";
	std::cout<<abs(num1-num2)<<" ";
}
void calc::mult()
{
	std::cout<<num1*num2<<" ";
}
void calc::division()
{
	std::cout<<num1/num2<<" ";//¸ò
	std::cout<<num1%num2<<" ";//³ª¸ÓÁö
}
void calc:: big_number()
{
	int big_number;
	num1>num2?big_number=num1:big_number=num2;
	std::cout<<big_number<<" ";
}
void calc:: equel()
{
	int same;
	num1==num2?same=1:same=0;
	std::cout<<same<<" ";
}