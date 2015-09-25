#include<iostream>
#include<fstream>


#define num_maximum  1229//10000보다 작은 소수의 개수
#define maximum_prime_number 9973//10000이하의 소수중 가장 큰수


void find_prime_number(int *prime_number);

class prime_factorization
{
private:
	int num;
public:
	prime_factorization(std::ifstream &input)
	{
		input>>num;
	}
	void calc(int *factor);
};

void main()
{
	std:: ifstream input;
	input.open("input.txt");

	int cases;
	int prime_number[num_maximum];
	input>>cases;

	
	find_prime_number(&prime_number[0]);
	for(int i=0; i< cases; i++)
	{
		prime_factorization lf(input);
		lf.calc(&prime_number[0]);
	}
}

void find_prime_number(int *prime_number)
{
	int k = 1;
	prime_number[0] = 2;
	for(int i =2; i<maximum_prime_number+1; i++)
	{
		for(int j=2; j<i; j++)
		{
			if(i%j==0)
			{
				break;
			}

			if(j==i-1)
			{
				prime_number[k] = i;
				k++;
			}
		}
	}

	
}

void prime_factorization::calc(int *prime_number)
{
	int factor[1000];
	int num_factor[1000];
	int num_factors = 0;
	int k=0;

	for(int i =0; i<1000; i++)
	{
		num_factor[i] =0;
	}

	for(int i=0; i<num_maximum; i++)
	{
		if(num%prime_number[i]==0)
		{
			num_factor[k]++;
			num/=prime_number[i];

			if(num%prime_number[i]!=0)
			{
				
				factor[k] = prime_number[i];
				num_factors++;
				k++;
			}
			else
			{
				i--;
			}
			
		}
	}
	std::cout<<num_factors<<" ";
	for(int i=0; i<num_factors; i++)
	{
		std::cout<<factor[i]<<" "<<num_factor[i]<<" ";
	}
	std::cout<<std::endl;
}