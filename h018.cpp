#include<iostream>
#include<fstream>


class area
{
private:
	int x1,y1;
	int x2,y2;
	int x3,y3;
public:
	area(std::ifstream&input)
	{
		input>>x1;
		input>>y1;
		input>>x2;
		input>>y2;
		input>>x3;
		input>>y3;
	}
	void calc();
	
};

void main()
{
	std::ifstream put;

	int cases;

	put.open("input.txt");
	put>>cases;

	for(int i=0; i<cases; i++)
	{
		area lf(put);
		lf.calc();

	}
}

void area::calc()
{
	int signedarea = (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);//����*2
	int direction;//�ð����or�ݽð����

	if(signedarea>0)//�ݽð����
	{
		direction=1;
	}
	else if(signedarea==0)//�ﰢ���� �ȸ������, ������ ������ ������
	{
		direction = 0;
	}
	else//�ð����
	{
		direction = -1;
	}
	std::cout<<abs(signedarea)<<" " <<direction<<std::endl;
}