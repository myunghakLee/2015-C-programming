#include"problem71(head).h"
#include<iostream>
void check_distance::calc()
{
	int len1;
	int len2;
	int len3;
	int len4;
	len1 = abs(dot1[0] - dot2[0]) + abs(dot1[1] - dot2[1]);

	len2 = (dot1[0] - dot2[0])*(dot1[0] - dot2[0]) + (dot1[1] - dot2[1])*(dot1[1] - dot2[1]);

	len3 = abs(dot1[0] - dot1[1])*2;

	len4 = (dot1[0] - dot1[1])*(dot1[0] - dot1[1])*2;



	bool same;
	same = ((dot1[0] == dot2[0]) && (dot1[1] == dot2[1]));

	std::cout << same << " " << len2 << " " << len1 << " " << len4 << " " << len3 << std::endl;

}

						
