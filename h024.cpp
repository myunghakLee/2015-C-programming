#include<iostream>
#include<fstream>

int compare(const void *a , const void *b);

class score
{
private:
	int num_student;
	int student[110];
public:
	score(std::ifstream& input)
	{
		input>>num_student;
		for(int i = 0; i<num_student; i++)
		{
			input>>student[i];
		}
	}
	void calc();
};

void main()
{
	std::ifstream input;

	int cases;

	input.open("input.txt");

	input>>cases;

	for(int i =0; i<cases; i++)
	{
		score lf(input);
		lf.calc();
	}
}
void score::calc()
{
	qsort(student, num_student, sizeof(student[0]),compare);

	int same_score[110];
	for(int i=0; i<110; i++)
	{
		same_score[i]= 1;
	}

	int j = 0;

	for(int i=0; i< num_student; i++)
	{
		if(i==num_student-1)
		{
			std::cout<<student[i]<<" "<<same_score[j];
		}
		else if(student[i]==student[i+1])
		{
			same_score[j]++;
		}
		else
		{
			std::cout<<student[i]<<" "<<same_score[j]<<" ";
			j++;
			
		}
	}
	std::cout<<std::endl;



}



int compare(const void *a, const void*b)
{
	return(*(int*)a-*(int*)b);
}
