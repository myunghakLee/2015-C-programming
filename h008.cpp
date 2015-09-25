#include<iostream>
#include<fstream>



class time_calc
{
private:
	int worker;
	int S_hour, S_min, S_sec;//start
	int F_hour, F_min, F_sec;//finish
public:
	time_calc(std::ifstream& input)
	{

	}
	void calc(std::ifstream& input);
};

void main()
{
	std::ifstream input;

	input.open("input.txt");

	int cases;

	input>>cases;

	for(int i=0; i<cases; i++)
	{
		time_calc lf(input);
		lf.calc(input);

	}
}

void time_calc::calc(std::ifstream& input)
{
	int day=0;
	int hour=0;
	int min=0;
	int sec=0;

	input>> worker;
	for(int i = 0; i < worker; i++)
	{
		input>>S_hour;
		input>>S_min;
		input>>S_sec;
		input>>F_hour;
		input>>F_min;
		input>>F_sec;


		sec+= F_sec-S_sec;
		min+= F_min-S_min;
		hour+= F_hour-S_hour;
	
		if(sec<0)
		{
			min--;
			sec+=60;
		}
		else if(sec>=60)
		{
			sec-=60;
			min++;
		}
		if(min<0)
		{
			hour--;
			min+=60;
		}
		else if(min>=60)
		{
			hour++;
			min-=60;
		}

		if(hour>=24)
		{
			day++;
			hour-=24;
		}
	}
	
	std::cout<<day<<" "<<hour<<" "<<min<<" "<<sec<<std::endl; 
}