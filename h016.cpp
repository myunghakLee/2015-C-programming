#include<iostream>
#include<fstream>

class DOR_D//distance of rectangle and dot
{
private:
	int x1,y1;//dot1
	int x2,y2;//dot2
	int dot_x, dot_y;
public:
	DOR_D(std::ifstream& put)
	{
		put>>x1;
		put>>y1;
		put>>x2;
		put>>y2;
		put>>dot_x;
		put>>dot_y;
	}
	void distance()
	{
		int SLdistance =0;//직선(straight line)*****제곱
		int RAdistance= 0;//직각(right angle)
		if(dot_y<=y2 && dot_y>=y1 && dot_x<=x2 &&dot_x>=x1)//점이 사각형의 안쪽에 있을때
		{
			SLdistance = 0;
			RAdistance = 0;
		}
		else if(dot_x<=x2 &&dot_x>=x1)//점이 사각형의 바로 위 혹은 아래에 있을때
		{
			RAdistance = abs(dot_y-y2) >abs(dot_y-y1) ? abs(dot_y-y1) : abs(dot_y-y2);
			SLdistance = RAdistance*RAdistance;
		}
		else if(dot_y<=y2 && dot_y>=y1)//점이 사각형의 바로 옆에 있을때
		{
			RAdistance = abs(dot_x-x2) >abs(dot_x-x1) ? abs(dot_x-x1) : abs(dot_x-x2);
			SLdistance = RAdistance*RAdistance;
		}
		else if(dot_x>x2)//점이 사각형의 오른쪽에 있을 때
		{
			if(dot_y>y2)//점이 사각형의 위에있을 때
			{
				SLdistance=(dot_x-x2)*(dot_x-x2) + (dot_y-y2)*(dot_y-y2);
				RAdistance=dot_x-x2+dot_y-y2;
			}
			else if(dot_y<y1)//점이 사각형의 아래에 있을 때
			{
				SLdistance=(dot_x-x2)*(dot_x-x2) + (dot_y-y1)*(dot_y-y1);
				RAdistance=dot_x-x2+y1-dot_y;
			}
		}
		else if(dot_x<x1)//점이 사각형의 왼쪽에 있을때
		{
			if(dot_y>y2)//점이 사각형의 위에있을 때
			{
				SLdistance=(dot_x-x1)*(dot_x-x1) + (dot_y-y2)*(dot_y-y2);
				RAdistance=x1-dot_x+dot_y-y2;
			}
			else if(dot_y<y1)//점이 사각형의 아레에 있을 때
			{
				SLdistance=(dot_x-x1)*(dot_x-x1) + (dot_y-y1)*(dot_y-y1);
				RAdistance=x1-dot_x+y1-dot_y;
			}		
		}
		std :: cout<<SLdistance<<" " <<RAdistance<<std::endl;
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
		DOR_D distance(put);
		distance.distance();

	}
}