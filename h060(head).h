#ifndef _checksum_
#define _checksum_

#include<fstream>


class mors
{
private:
	char mark[2000];
public:
	mors(std::ifstream & instream)
	{
		instream >> mark;
	}
	void changing();
	void sub_changing(char[]);



};



#endif

