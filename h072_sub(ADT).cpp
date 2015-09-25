#include<iostream>
#include<fstream>

#include"problem72_sub(head).h"



int area::calc()
{
	int signedarea = (x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1);//ºÎÇÇ*2

	return signedarea;
}

						
