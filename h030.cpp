#include<iostream>
#include<fstream>

class calender
{
private:
	int year;
	int month;
public:
	calender(std::ifstream& input)
	{
		input>>year;
		input>>month;
	}
	int week();
	void print_calender(int week);

};

void main()
{
	std::ifstream input;
	input.open("input.txt");
	int cases;
	input>>cases;

	for(int i=0; i<cases; i++)
	{
		calender lf(input);
		int week = lf.week();
		lf.print_calender(week);

	}
}

int calender::week()
{
	int week = 0;

	for(int i = 1582; i< year; i++)//연도
	{
		week+=365;
		if( (i%4==0) && ((i%100!=0)||(i%400==0)))//윤년일 경우
		{
			week++;
		}
	}
	for(int i=1; i<month; i++)//월
	{
		if((i==1)||(i==3)||(i==5)||(i==7)||(i==8)||(i==10)||(i==12))
		{
			week+=31;
		}
		else if((i==4)||(i==6)||(i==9)||(i==11))
		{
			week+=30;
		}
		else
		{
			if( (year%4==0) && ((year%100!=0)||(year%400==0)))//윤년일 경우
			{
				week++;
			}
			week+=28;
		}
	}
	week+=5;//금요일 부터 시작했으므로

	week%=7;

	return week;
}
void calender:: print_calender(int week)
{
	int month_day=0;//각 월별로 몇일까지 있는지

	std::cout<<year<<" "<<month<<std::endl;

	if((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12))
	{
		month_day=31;
	}
	else if((month==4)||(month==6)||(month==9)||(month==11))
	{
		month_day+=30;
	}
	else
	{
		month_day+=28;
		if( (year%4==0) && ((year%100!=0)||(year%400==0)))//윤년일 경우
		{
			month_day++;
		}
	}




	for(int i = 0; i<week;i++)
	{
		std::cout<<0<<" ";
	}

	for(int i=1; i<month_day+1; i++)
	{

		
		if(((i+week)%7==0)&&(i!=month_day))
		{
			std::cout<<i;
			std::cout<<std::endl;
		}
		else
		{
			std::cout<<i<<" ";
		
		}
	}
	for(int i=0;i<(7-(month_day+week)%7);i++)
	{
		if((7-(month_day+week)%7) == 7)
		{
			break;
		}
		if(i ==(7-(month_day+week)%7)-1 )
		{
			std::cout<<"0";
		}
		else
		{
			std::cout<<"0"<<" ";
		
		}

	}
	std::cout<<std::endl;
}