#include"problem70(head).h"

#define day (24*60)
#define half_day (12*60)

void digital_clock::calc()
{
	int ago_minutes = 0;
	char ago_PM_AM[3];
	int ago_hours = 0;
	if (hours == 12)
	{
		hours = 0;
	}

	ago_minutes += (hours * 60) + minutes;
	


	if (PM_AM[0] == 'P')
	{
		ago_hours += 12;
	}


	while (ago < 0)
	{
		ago += day;
	}


	ago_minutes += ago;

	while (ago_minutes >= 60)
	{
		ago_hours++;
		ago_minutes -= 60;
	}


	while (ago_hours > 24)
	{
		ago_hours -= 24;
	}

	if (ago_hours > 11 && ago_hours<24)
	{
		strcpy_s(ago_PM_AM, "PM");
	}
	else
	{
		strcpy_s(ago_PM_AM, "AM");
	}

	if (ago_hours > 12)
	{
		ago_hours -= 12;
	}

	if (ago_hours == 0)
	{
		ago_hours = 12;
	}






	if (ago_hours > 9)
	{
		std::cout << ago_hours << ":";
	}
	else
	{
		std::cout << "0" << ago_hours << ":";
	}

	if (ago_minutes > 9)
	{
		std::cout << ago_minutes;
	}
	else
	{
		std::cout << "0" << ago_minutes;
	}

	std::cout << ago_PM_AM << std::endl;


}



						
