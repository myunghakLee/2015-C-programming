#ifndef __width_TRYANGLE__
#define __width_TRYANGLE__

#include<iostream>
#include<fstream>


class area
{
private:
	int x1, y1;
	int x2, y2;
	int x3, y3;
public:
	area(int dot1_x, int dot1_y, int dot2_x, int dot2_y, int dot3_x, int dot3_y) :x1(dot1_x), y1(dot1_y), x2(dot2_x), y2(dot2_y), x3(dot3_x), y3(dot3_y)
	{}
	int calc();

};


#endif

						
