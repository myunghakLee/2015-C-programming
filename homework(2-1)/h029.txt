#include<iostream>
#include<fstream>

class week
{
private:
	int year;
	int month;
	int day;
public:
	week(std::ifstream& input)
	{
		input>>year;
		input>>month;
		input>>day;
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
		week lf(input);
		lf.calc();
	}
}

void week::calc()
{
	int D_day = 0;

	for(int i = 1582; i< year; i++)//연도
	{
		D_day+=365;
		if( (i%4==0) && ((i%100!=0)||(i%400==0)))//윤년일 경우
		{
			 D_day++;
		}
	}
	for(int i=1; i<month; i++)//월
	{
		if((i==1)||(i==3)||(i==5)||(i==7)||(i==8)||(i==10)||(i==12))
		{
			D_day+=31;
		}
		else if((i==4)||(i==6)||(i==9)||(i==11))
		{
			D_day+=30;
		}
		else
		{
			if( (year%4==0) && ((year%100!=0)||(year%400==0)))//윤년일 경우
			{
				D_day++;
			}
			D_day+=28;
		}
	}
	D_day+=(day-1);//일
	D_day+=5;//금요일 부터 시작했으므로
	D_day%=7;

	std::cout<<D_day<<std::endl;
}