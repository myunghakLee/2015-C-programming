#include<iostream>
#include<fstream>


class easter
{
private:
	int year;
public:
	easter(std::ifstream& input);
	void easter_calc();
};


int main()
{
	int cases;
	std::ifstream input;

	input.open("input.txt");
	input>>cases;
	

	
	for(int i=0; i<cases;i++)
	{
		easter lf(input);
		lf.easter_calc();
	}
	return 0;

}

easter::easter(std::ifstream& input)
{
	input>>year;
}
void easter ::easter_calc()
{
	
	int c=year/100;		//¼¼±â
	int n=year-(year/19)*19;
	int t=(c-17)/25;
	int i=(c-(c/4)-(c-t)/3)+(n*19+15);
	int j=i-(i/30)*30;
	int k=j-(j/28)*(1-j/28)*(29/(j+1))*((21-n)/11);
	int l=(year+year/4+j+2)-c+(c/4);
	int p=l-((l/7)*7);
	int q=k-p;
	int result_month=(q+40)/44+3;
	int result_day=q+28-((result_month/4)*31);
	std::cout<<result_month<<" "<<result_day<<std::endl;
}


