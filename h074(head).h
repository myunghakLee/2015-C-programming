#ifndef __DATE_1_
#define __DATE_1_

class date1
{
private:
	int year, month, day;
public:
	date1(int y, int m, int d) : year(y), month(m), day(d)
	{}
	int getDayOfMonth() const{ return month; }
	int getDayOfYear() const{ return year; }
	int getDayOfDay() const { return day; }



	bool isLeapYear() const;
	int getDayOfWeek() const;
};



#endif

						
