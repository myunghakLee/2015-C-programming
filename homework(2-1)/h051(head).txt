					
#ifndef _checksum_
#define _checksum_

#include<fstream>

class check_sum
{
private:
	unsigned int num;//입력되는수
	int num_partition[4];

public:
	check_sum(std::ifstream &instream)
	{
		instream>>num;
	}
	void put_num_partition();
	int check();

};

#endif

						
