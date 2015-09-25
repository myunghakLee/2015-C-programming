#include<iostream>
#include<fstream>

using namespace std;
class digital_clock
{
private:
	int hours;
	int minutes;
	char PM_AM[3];
	char garage;
	int ago;
public:
	digital_clock(std::ifstream &instream)
	{
		instream >> hours>>garage>>minutes>>PM_AM>>ago;
	}
	void calc();
};


						
