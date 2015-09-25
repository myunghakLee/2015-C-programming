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
	int num_one=0;//���������� 1�� ����;
	unsigned int number=num;//num�� ���� 1�� ������ �������µ� ���ǹǷ�  num�� ���� number�� �����ص�
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