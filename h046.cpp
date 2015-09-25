/*********************************************************
*          전자정보통신대학 컴퓨터공학부                  *
*             20143086 이명학                            *
*            problem 46 : 실수표현                         *
*********************************************************/
 
 
 
#include<iostream>
#include<fstream>
 
class ExpressRN// 실수표현(express real number)
{
private:
	char num[300];
public:
	ExpressRN(std::ifstream &instream)
	{
		instream>>num;
	}
	void examination();
};
 
void main()
{    
	int cases;
 
	std::ifstream instream;
 
	instream.open("input.txt");
 
	instream>>cases;
 
	for(int i=0; i<cases; i++)
	{
		ExpressRN ex(instream);
		ex.examination();
 
	}
}
 
 
void ExpressRN::examination()
{
	int dot=0;
	int e=0;
	int len= strlen(num);
	int answer =1;
	int copherE=0;
	int copherdot=0;

	for(int i=0; i<len; i++)
	{
		if(num[i]<='9' && num[i]>='0')
		{
		
		}
		else if(num[i] == 'e' || num[i] == 'E')
		{
			e++;
			if(e>1)
			{
				answer =0;
				break;
			}
			else if(!(num[i+1] == '+'|| num[i+1] == '-' || (num[i+1]<='9' && num[i+1]>='0')))
			{
				answer =0;
				break;
			}
			copherE=i;
			
		}
		else if(num[i] == '.')
		{
			dot++;
			if(dot>1)
			{
				answer=0;
				break;
			}
			else if((num[i+1] == 'e' ||num[i+1] == 'E') && i==0)
			{
				answer =0;
				break;
			}
			copherdot=i;
		}
		else if(num[i]=='+'||num[i]=='-')
		{}
		else
		{
			answer =0;
		}
	
	}
 
	if((dot==0 && e==0) ||(num[len-1] == 'e' || num[len-1] == 'E') )
	{
		answer =0;
	}
	if(len==1 && dot==1)
	{
		answer =0;
	}
	if(((num[0] == 'E' || num[0] == 'e')) && (dot==0 || num[len-1]=='.'))
	{
		answer =0;
	}
	if(num[len-1]=='+'||num[len-1]=='-')
	{
		answer =0;
	}
	if(num[0]=='+'||num[0]=='-')
	{
		answer =0;
	}
	if(copherdot>copherE && e==1 && dot==1)
	{
		answer =0;
	}
	for(int k=0; k<len;k++)
	{
		num[k] = -3;
	}
	
	std::cout<<answer<<std::endl;
}

						
