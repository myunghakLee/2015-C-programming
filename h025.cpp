#include<iostream>
#include<fstream>

int compare(const void *a , const void *b);
int compare2(const void *a, const void*b);

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
	
	qsort(student, num_student, sizeof(student[0]),compare);//우선 성적을 작은순으로 나열함

	int same_score[110];
	int mod=1;//최빈값이 몇개나 나오나
	int mod_num[110];//최빈값/
	
	
	for(int i=0; i<110; i++)	{	same_score[i]= 1;	}//초기화

	int j = 0;



/////////////////////////////////////////////////////////studnet에 저장되어있는 값을 종류별로 mod_num에 저장/////////////////////////////////////
	for(int i=0; i< num_student; i++)
	{
		if(i==num_student-1)
		{
			mod_num[j]=student[i];

		}
		else if(student[i]==student[i+1])
		{
			same_score[j]++;
		}
		else
		{
			mod_num[j]=student[i];

			j++;

		}
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	same_score[j]==NULL;




	for(int i=0;i<j; i++)
	{
		if(same_score[i]==same_score[i+1])
		{
			mod++;
		}
		else
		{
			break;
		}
	}






	/////////////////////////////////save_score 에 따라  mod_num 역시 바뀌어야 하기 때문에 어쩔수 없이 bubble sort사용//////////////////////////////////////

	for(int i=0; i<j+1; i++)
	{
		for(int k=i+1; k<j+1; k++)
		{
			if(same_score[i]<same_score[k])
			{
				int save;
				save=same_score[i];
				same_score[i]=same_score[k];
				same_score[k]=save;

				save=mod_num[i];
				mod_num[i]=mod_num[k];
				mod_num[k]=save;
			}
			

			
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout<<mod<<" "<<same_score[0]<<" ";


	for(int i=0; i<mod; i++)
	{
		std::cout<<mod_num[i]<<" ";
	}
	std::cout<<std::endl;

}



int compare(const void *a, const void*b)
{
	return(*(int*)a-*(int*)b);
}

int compare2(const void *a, const void*b)
{
	return(*(int*)b-*(int*)a);
}
