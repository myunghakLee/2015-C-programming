#include<iostream>
#include<fstream>


class moving_average
{
private:
	int num_num;//숫자의 개수
	int period;
	int num[256];
public:
	moving_average(std::ifstream &input)
	{
		input>>num_num;
		for(int i=0; i<num_num; i++)
		{
			input>>num[i];
		}
		input>>period;
	}
	void calc();
};

void main()
{
	std::ifstream input;

	input.open("input.txt");

	int cases;
	input>>cases;

	for(int i=0; i<cases; i++)
	{
		moving_average lf(input);
		lf.calc();
	}
}

void moving_average::calc()
{
	int sum = 0;

	std::cout<<num_num-period+1<<" ";//이동평균의 갯수
	for(int i = 0;i<num_num-period+1; i++)
	{
		for(int j=i; j<i+period; j++)
		{
			sum += num[j];
		}
		sum/=period;
		std::cout<<sum<<" ";
		sum=0;
	}
	std::cout<<std::endl;
}