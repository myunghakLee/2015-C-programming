#include<iostream>
#include<fstream>
#include<cstdlib>
#include"problem74(head).h"

using namespace std;

void main()
{
	ifstream instream;
	int cases;

	instream.open("input.txt");

	instream >> cases;
	for (int i = 0; i < cases; i++)
	{
		int year, month, day;

		instream >> year >> month >> day;

		date1 cl(year, month, day);
		std::cout << cl.getDayOfYear() << " " << cl.getDayOfMonth() << " " << cl.getDayOfDay() << std::endl;
		std::cout << cl.isLeapYear() << " " << cl.getDayOfWeek() << std::endl;



		instream >> year >> month >> day;

		date1 cl2(year, month, day);
		std::cout << cl2.getDayOfYear() << " " << cl2.getDayOfMonth() << " " << cl2.getDayOfDay() << std::endl;
		std::cout << cl2.isLeapYear() << " " << cl2.getDayOfWeek() << std::endl;



		instream >> year >> month >> day;

		date1 cl3(year, month, day);
		std::cout << cl3.getDayOfYear() << " " << cl3.getDayOfMonth() << " " << cl3.getDayOfDay() << std::endl;
		std::cout << cl3.isLeapYear() << " " << cl3.getDayOfWeek() << std::endl;
	}

}

						
