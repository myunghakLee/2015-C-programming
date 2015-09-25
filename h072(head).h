#ifndef __problem_72__
#define __problem_72__

#include <fstream>
#include"problem72_sub(head).h"
class cross_line
{
private:
	int dot1[2];
	int dot2[2];
	int dot3[2];
	int dot4[2];
public:
	cross_line(std::ifstream&instream)
	{
		instream >> dot1[0] >> dot1[1];
		instream >> dot2[0] >> dot2[1];
		instream >> dot3[0] >> dot3[1];
		instream >> dot4[0] >> dot4[1];
	}
	void check();

};




#endif

						
