#include<fstream>

class read_number
{
private:
	char num[11];
	int check;
	int check2;
	char Reading[30][30];
	int temp;

public:
	read_number(std::ifstream &instream)
	{
		instream >> num;
		check2=0;
		check = 1;
		temp = 0;
		for (int i = 0; i < 30; i++) 
		{
			Reading[i][0] = NULL;
		}
	
	}
	void sub_reading(int, int,char a[], int la);
	void reading();
	void select(char, char, char);


};

