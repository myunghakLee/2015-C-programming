						
#include<iostream>
#include <fstream>
#include "problem51(head).h"



void check_sum::put_num_partition()
{
	int knife=255;
	num_partition[0] = num>>24;
	num_partition[1] = (num>>16) & knife;
	num_partition[2] = (num>>8) & knife;
	num_partition[3] = num & knife;

}

int check_sum::check()
{
	int CHECK_SUM = num_partition[0]+num_partition[1]+num_partition[2];
	
	while(CHECK_SUM>255)
	{
		CHECK_SUM-=256;
	}
	CHECK_SUM= 255 - CHECK_SUM;

	return CHECK_SUM==num_partition[3];
}
