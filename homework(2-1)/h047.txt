				
/*********************************************************
*          전자정보통신대학 컴퓨터공학부                   *
*             20143086 이명학                             *
*            problem 47 : 시이저 암호 기법                *
*********************************************************/

#include<iostream>
#include<fstream>

class sizer_secret
{
private:
	int move;
	char sentence[150];
public:
	sizer_secret(std::ifstream & input)
	{
		input>>move;
		input>>sentence;
	}
	void calc();
};


void main()
{
	std::ifstream input;

	input.open("input.txt");

	int cases;

	input>> cases;

	for(int i=0; i<cases; i++)
	{
		sizer_secret lf(input);
		lf.calc();
	}

}

void sizer_secret ::calc()
{
	for(int i=0;;i++)
	{
		if(sentence[i]==NULL)
		{
			break;
		}




		if((sentence[i]>96 && sentence[i]<123))
		{
			
			if(sentence[i]+move>122)
			{
				sentence[i] -= 26;
				sentence[i]+=move;
			}
			else
			{
				sentence[i]+=move;
			}
		}

		else if(sentence[i]>64 && sentence[i]<91)
		{
			
			if(sentence[i]+move>90)
			{
				sentence[i] -= 26;
				sentence[i]+=move;
			}
			else
			{
				sentence[i]+=move;
			}

		}
	}


	std::cout<<sentence<<std::endl;
}
