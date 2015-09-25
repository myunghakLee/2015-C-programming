#include<iostream>
#include<fstream>

int compare(const void *a, const void*b);

class hamming
{
private:
	int num_hamming;
public:
	hamming(std:: ifstream & input)
	{
		input>>num_hamming;
	}
	void find_hamming();
};

void main()
{
	std::ifstream input;

	input.open("input.txt");
	int cases;
	input>>cases;

	for(int i=0; i<cases; i++)
	{
		hamming lf(input);
		lf.find_hamming();
	}
}

void hamming::find_hamming()
{
	int hamming[1550];
	int k =0;
	int z= 0;
	hamming[0]= 1;
	for(int i = 0; i<num_hamming+150;)//num_haming에 150을 더해주지 않을 경우 맨 마지막 자리가 (haming[num_haming-2])*5가 될 위험이 있으므로
	{
		z=0;
		i++;
		hamming[i]= hamming[k]*2;
		for(int j= i-1; j>0; j--)
		{
			if(hamming[j]==hamming[i])
			{
				hamming[i]=NULL;
				i--;
				z++;
				break;
			}
		}
		i++;
		hamming[i]= hamming[k]*3;
		for(int j= i-1; j>0; j--)
		{
			if(hamming[j]==hamming[i])
			{
				hamming[i]=NULL;
				i--;
				z++;
				break;
			}
		}
		i++;
		hamming[i]= hamming[k]*5;
		for(int j= i-1; j>0; j--)
		{
			if(hamming[j]==hamming[i])
			{
				hamming[i]=NULL;
				i--;
				z++;
				break;
			}
		}

		z>0?z=1:z=0;

		qsort(hamming,i,sizeof(hamming[0]),compare);
		z=0;
	
		k++;
	}
	
	
	
		std::cout<<hamming[num_hamming-1]<<std::endl;

		
}

int compare(const void *a, const void*b)
{
	return(*(int*)a-*(int*)b);
}
