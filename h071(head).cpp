#ifndef __problem71__
#define __problem71__

#include<fstream>

class check_distance
{
private:
	int dot1[2];
	int dot2[2];
public:
	check_distance(std::ifstream &instream)
	{
		instream >> dot1[0] >> dot1[1];
		instream >> dot2[0] >> dot2[1];
	}
	void calc();
};

#endif

						
