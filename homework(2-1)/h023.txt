#include<iostream>
#include<fstream>

class parity
{
private:
	unsigned int num;
public:
	parity(std::ifstream& input)
	{
		input>>num;
	}
	void calc();
};

void main()
{
	std::ifstream input;

	int cases;

	input.open("input.txt");

	input>>cases;
	
	for(int i =0; i<cases; i++)
	{
		parity lf(input);
		lf.calc();
	}
}
void parity::calc()
{
	int num_one=0;//이진법에서 1의 갯수;
	unsigned int number=num;//num의 값은 1의 갯수를 구해지는데 사용되므로  num의 값을 number에 저장해둠
	for(;;)
	{
		if(num!=0)
		{
			if(num%2==0)
			{
				num/=2;
			}
			else
			{
				num/=2;
				num_one++;
			}
		}
		else
		{
			break;
		}
	}
	if(num_one%2==1)
	{
		number+=2147483648;//2147483648=2^31;
	}
	std::cout<<number<<std::endl;
		
	
}