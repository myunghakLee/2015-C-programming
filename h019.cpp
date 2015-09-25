#include<iostream>
#include<fstream>


class area
{
private:
	int shape;
	int x[220],y[220];
public:
	area(std::ifstream&input)
	{
		input>>shape;
		for(int i = 0; i<shape; i++)
		{
			input>>x[i];
			input>>y[i];
		}	

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
	int signedarea = 0;
	int direction;//�ð����or�ݽð����

	for(int i= 1; i<shape-1; i++)
	{
		signedarea +=(x[i]-x[0])*(y[i+1]-y[0])-(x[i+1]-x[0])*(y[i]-y[0]);//���� ���� : http://darkpgmr.tistory.com/86
	}


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