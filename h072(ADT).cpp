#include"problem72(head).h"
#include<iostream>

void cross_line::check()
{
	area ar(dot1[0], dot1[1], dot2[0], dot2[1], dot3[0], dot3[1]);
	area ar2(dot1[0], dot1[1], dot2[0], dot2[1], dot4[0], dot4[1]);
	area ar3(dot3[0], dot3[1], dot4[0], dot4[1], dot1[0], dot1[1]);
	area ar4(dot3[0], dot3[1], dot4[0], dot4[1], dot2[0], dot2[1]);

	int weight1 = ar.calc();
	int weight2 = ar2.calc();
	int weight3 = ar3.calc();
	int weight4 = ar4.calc();



	if ((weight1*weight2 < 0) && (weight3*weight4<0))
	{
		std::cout << 1 <<std::endl;
	}
	else if ((weight1*weight2 == 0) || (weight3*weight4 == 0))
	{
		std::cout << 2<<std::endl;
	}
	else
	{
		std::cout << 0 << std::endl;
	}


}

						
