#include<iostream>
#include<fstream>


class cross
{
private:
	int x1,y1;
	int x2,y2;
	int x3,y3;
	int x4,y4;
public:

	cross(std::ifstream&input)
	{
		input>>x1;
		input>>y1;
		input>>x2;
		input>>y2;
		input>>x3;
		input>>y3;
		input>>x4;
		input>>y4;
	}
	void calc()
	{
		int answer;
		int save;
		if(x1==x2)
		{
			if(y1>y2)
			{
				save = y1;
				y1=y2;
				y2=save;
			}
			if(x3>x4)
			{
				save = x3;
				x3=x4;
				x4=save;
			}
			if((y1<=y3 && y3<=y2) && (x3<=x2 && x2 <= x4))
			{
				if(y3==y2 || y3==y1 || x3==x1 || x4 == x1)//접해있는경우
				{
					answer = 2;
				}
				else//완전교차
				{
					answer = 1;
				}
			}
			else
			{
				answer = 0;
			}
		}
		else if(y1==y2)
		{
			if(x1>x2)
			{
				save = x1;
				x1=x2;
				x2=save;
			}
			if(y3>y4)
			{
				save = y3;
				y3=y4;
				y4=save;
			}
			if((x1<=x3 && x3<=x2) && (y3<=y2 && y2 <= y4))
			{
				if(y1==y4 || y1==y3 || x1==x3 || x2 == x3)//접해있는경우
				{
					answer = 2;
				}
				else//완전교차
				{
					answer = 1;
				}
			}
			else
			{
				answer = 0;
			}
		}
		std::cout<<answer<<std::endl;
	}

};

void main()
{
	std::ifstream put;

	int cases;

	put.open("input.txt");
	put>>cases;

	for(int i=0; i<cases; i++)
	{
		cross lf(put);
		lf.calc();

	}
}