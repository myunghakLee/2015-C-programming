#include<iostream>
#include<fstream>

class divisor
{
private:
	int number;
	int num[110];
public:
	divisor(std::ifstream& input)
	{
		input>>number;
	}
	void calc(std::ifstream& input);
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
		lf.calc(file);
	}
}

void divisor::calc(std::ifstream& input)
{
	int result =1;
	int num_zero = 0;
	int num_five=0;
	int num_two=0;
	for(int i=0; i<number;i++)
	{
		input>>num[i];
		for(;;)
		{
			if(num[i]%5==0)
			{
				num_five++;
				num[i]/=5;
			}
			else if(num[i]%2==0)
			{
				num_two++;
				num[i]/=2;
			}
			else if(num[i]>100)
			{
				num[i]%=100;
			}
			else
			{
				break;
			}
		}

		result*=num[i];
		result%=10;
	}
	if(num_two>num_five)
	{
		num_zero=num_five;
		for(int j=0; j<num_two-num_five;j++)
		{
			result*=2;
			result%=10;
		}
	
	}
	else
	{
		num_zero=num_two;
		for(int j=0; j<num_five-num_two;j++)
		{
			result*=5;
			result%=10;
		}
	
	}



	std::cout<<result%10<<" "<<num_zero<<std::endl;


}