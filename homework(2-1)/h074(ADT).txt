#include"problem74(head).h"



bool date1:: isLeapYear() const
{
	if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))//윤년일 경우
	{
		return true;
	}
	return false;
}
int  date1::getDayOfWeek()  const
{
	int week = 0;

	for (int i = 1582; i< year; i++)//연도
	{
		week += 365;
		if ((i % 4 == 0) && ((i % 100 != 0) || (i % 400 == 0)))//윤년일 경우
		{
			week++;
		}
	}
	for (int i = 1; i<month; i++)//월
	{
		if ((i == 1) || (i == 3) || (i == 5) || (i == 7) || (i == 8) || (i == 10) || (i == 12))
		{
			week += 31;
		}
		else if ((i == 4) || (i == 6) || (i == 9) || (i == 11))
		{
			week += 30;
		}
		else
		{
			if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))//윤년일 경우
			{
				week++;
			}
			week += 28;
		}
	}
	
	week += (day-1);

	week += 5;//금요일 부터 시작했으므로
	week %= 7;

	return week;
}

						
