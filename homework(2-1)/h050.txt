					
							
/*********************************************************
*          전자정보통신대학 컴퓨터공학부                   *
*             20143086 이명학                             *
*            problem 50 : 숫자의 진법 변환                 *
*********************************************************/


#include<iostream>
#include<fstream>
#include<cstring>

class ChangeNumSystem
{
private:
	int change_from;
	int change_to;
	char num[50];
public:
	ChangeNumSystem(std::ifstream &input)
	{
		input>>change_from;
		input>>num;
		input>>change_to;
	}
	int ChangeDecimalSystem();//십진수로 변환
	void ChangeSystem(int number);//진수변환
};


void main()
{
	std::ifstream input;
	input.open("input.txt");

	int cases;

	input>>cases;

	for(int i=0; i<cases; i++)
	{
		ChangeNumSystem lf(input);
		int number = lf.ChangeDecimalSystem();//num을 10진수로 변환시 number에저장
		lf.ChangeSystem(number);
	}
}

int ChangeNumSystem ::ChangeDecimalSystem()
{
	int length = strlen(num);
	int ten_num = 0;
	int plus = 1;
	int number[100];
	//////////////////////////////////////////////////십진법으로 바꾸기/////////////////////////////////////////////////
	for(int i=0; i<length; i++)
	{
		if(num[i]>='a')
		{
			num[i]-=87;
		}
		else
		{
			num[i]-=48;
		}
	}

	for(int i=0; i<length; i++)
	{
		number[i]= num[i];
	}
	for(int i=2; i<17; i++)//2~16진법중 몇 진법인지 판별
	{
		if(change_from == i)// num이 i진법일때
		{
			for(int j=0;j<length;j++)
			{



				for(int k=0; k<length-j-1; k++)
				{

					number[j]*=i;
				}

				ten_num += number[j];

			}
		}
	}


	//////////////////////////////////////////////////////////////////////////////////////////
	return ten_num;
}
void ChangeNumSystem ::ChangeSystem(int number)
{
	char save[50];
	char answer[50];
	int count=0;
	for(int i=0;;i++)
	{
		if(number ==0)
		{
			break;
		}

		else
		{
			save[i]=number%change_to;
			number/=change_to;
			count++;
		}
	}
	for(int i=0; i<count; i++)
	{
		answer[i]=save[count-i-1]+48;
		if(answer[i]>'9')
		{
			answer[i]+=39;
		}
	}

	for(int i=0; i<count; i++)
	{
		std::cout<<answer[i];
	}
	std::cout<<std::endl;
}


						
