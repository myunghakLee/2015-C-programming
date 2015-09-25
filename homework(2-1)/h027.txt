#include<iostream>
#include<fstream>


void binary_notation(unsigned long int *num);

class set_calc
{
private:
	int num_num1;
	int num_num2;
	int num1[200];
	int num2[200];
public:
	set_calc(std::ifstream & input)
	{
		input>>num_num1;
		for(int i =0; i< num_num1; i++)
		{
			input>>num1[i];
		}
		input>>num_num2;
		for(int i =0; i<num_num2; i++)
		{
			input>>num2[i];
		}
	}
	void calc();
};



void main()
{
	std:: ifstream file;

	file.open("input.txt");
	int cases;

	file>>cases;

	for(int i=0; i<cases; i++)
	{
		set_calc lf(file);
		lf.calc();
	}
}

void set_calc :: calc()
{
	unsigned long int set1[5]={0,0,0,0,0};
	unsigned long int set2[5]={0,0,0,0,0};
	unsigned long int intersection[5];//교집합
	unsigned long int sum_set[5];//합집합
	unsigned long int difference_set[5];//차집합


	for(int i = 0; i<num_num1; i++)
	{
		if(num1[i]<32)
		{
			set1[0]+= 1<<num1[i];
		}
		else if(num1[i]<64)
		{
			set1[1]+= 1<< (num1[i]-32);
		}
		else if(num1[i]<96)
		{
			set1[2]+= 1<< (num1[i]-64);
		}
		else if(num1[i]<128)
		{
			set1[3]+= 1<< (num1[i]-96);
		}
		else
		{
			set1[4]+= 1<< (num1[i]-128);
		}
	}

	for(int i = 0; i< num_num2; i++)
	{
		if(num2[i]<32)
		{
			set2[0]+= 1<<num2[i];
		}
		else if(num2[i]<64)
		{
			set2[1]+= 1<< (num2[i]-32);
		}
		else if(num2[i]<96)
		{
			set2[2]+= 1<< (num2[i]-64);
		}
		else if(num2[i]<128)
		{
			set2[3]+= 1<< (num2[i]-96);
		}
		else
		{
			set2[4]+= 1<< (num2[i]-128);
		}
	}
	for(int i =0; i<5; i++)
	{
		intersection[i] = set1[i] & set2[i];
		sum_set[i] = set1[i] | set2[i];
		difference_set[i] = set1[i] & (~set2[i]) ;
	}
	
	
	binary_notation(&intersection[0]);
	binary_notation(&sum_set[0]);
	binary_notation(&difference_set[0]);

}

void binary_notation(unsigned long int *num)
{	
	int num_one=0;//이진법에서 1의 갯수;
	int element[200];//원소
	int j=0;
	int k;

	for(int i = 0; i<133; i++)
	{
			i<32?k=0:i<64?k=1:i<96?k=2:i<128?k=3:k=4;

			if(num!=0)
			{
				if(num[k]%2==0)
				{
					num[k]/=2;
				}
				else
				{
					num[k]/=2;
					element[j]=i;
					num_one++;
					j++;
				}
			}
			else
			{
				break;
			}
		

		
	}
	std::cout<<num_one<<" ";

	for(int i = 0; i<num_one; i++)
	{
		std::cout<<element[i]<<" ";
	}
	std::cout<<std::endl;
}