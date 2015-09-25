#include<iostream>
#include<fstream>

class num_adjust
{
private:
	int	get_num;//숫자를 몇개 받아올건지
	char num[30][5];
	int strike[30];
	int ball[30];
public:
	num_adjust(std::ifstream& input)
	{
		input>>get_num;
		for(int i=0; i<get_num; i++)
		{
			input>>num[i];
			input>>strike[i];
			input>>ball[i];
		}

	}
	void num_found();
};

void main()
{
	std::ifstream input;

	input.open("input.txt");

	int cases;

	input>>cases;

	for(int i=0; i<cases; i++)
	{
		num_adjust lf(input);
		lf.num_found();
	}

}
void num_adjust ::num_found()
{
	int num_strike=0;
	int num_ball=0;
	int answer;
	int num_answer=0;

	for(int i=0; i<10000; i++)
	{
		int pan[4]= {0,0,0,0};
		int m=0;

		int num2[4];
		num2[0]=i/1000+48;//i의 천의자리
		num2[1]=i/100%10+48;//i의 백의자리
		num2[2]=i/10%10+48;//i의 십의자리
		num2[3]=i%10+48;//i의 일의자리
		for(int j=0; j<get_num; j++)
		{
			num_ball = 0;
			num_strike = 0;
			for(int k =0; k<4; k++)
			{
				for(int l = 0; l<4; l++)
				{	
					m=l;//이미 ball로 판정된 자리가 다시 ball로 판정하는데 쓰이는 것을 막기 위하여				ex) 5554 에 4볼 = 답이 없다
					if(num[j][k]==num2[l] && pan[m]==0)
					{
						if(num[j][k]==num2[k])
						{
							num_strike++;
						}
						else

						{
							num_ball++;
						}
						pan[m]++;
						break;
					}

				}

			}
			if(num_ball != ball[j] || num_strike != strike[j])
			{
				break;
			}

			if(j==get_num-1)
			{
				answer = i;
				num_answer++;
			}
			pan[0] = 0;
			pan[1] = 0;
			pan[2] = 0;
			pan[3] = 0;
			num_ball = 0;
			num_strike = 0;
		}
	}
	if(num_answer ==0)
	{
		std::cout<<-2<<std::endl;
	}
	else if(num_answer==1)
	{
		std::cout<<answer<<std::endl;
	}
	else
	{
		std::cout<<-1<<std::endl;
	}

}