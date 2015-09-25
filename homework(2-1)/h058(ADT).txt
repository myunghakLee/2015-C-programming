#include<iostream>
#include"problme58(head).h"


void read_number:: sub_reading(int number,int len, char a[], int la)
{
	check2 = 0;

	if (len >= number)
	{
		
		select(0, 0, num[len - number]);
		
		if (num[len - number] != 0)
			strcpy_s(Reading[temp++], "Hundred");
	}


	if (len >= (number-1))
	{
	
		if (num[len - (number - 1)] != 1)	
			select(0, num[len - (number - 1)], 0);

	}

	if (len >= (number-2))
	{
		
		
		if (len >= (number - 1))
		{
			if (num[len - (number - 1)] == 1)
			{
				select(0, num[len - (number - 1)], num[len - (number - 2)]);
				
			}
			else
				select(0, 0, num[len - (number - 2)]);

		}
		else if (len == (number - 2))
		{
			
			select(0, 0, num[len - (number - 2)]);
		}
	


		if (check2 != 3)
		{
			
			strcpy_s(Reading[temp++], a);
		}

	
	}

}










void read_number::reading()
{
	int len = strlen(num);
	for (int i = 0; i < len; i++)
	{
		num[i] -= '0';
	}

	if (len >= 10)
	{
		select(0, 0, num[0]);
		if (num[0]!=0)
			strcpy_s(Reading[temp++], "Billion");

		
	}


	sub_reading(9, len, "Million",1);
	sub_reading(6, len, "Thousand",1);
	sub_reading(3, len, "",0);

	int temp2 = 0;
	while (Reading[temp2][0]>0)
	{
		std::cout << Reading[temp2++];

		if (Reading[temp2][0]>0)
		{
			std::cout << "_";
		}
	}

//////////////////////////////////////////////////////////////////
	
	


	std::cout << std::endl;

}





void read_number::select(char a, char b, char c)
{
	int number = a * 100 + b * 10 + c;



	switch (number)
	{
	case 0: check = 0; check2++; break;
	case 1:strcpy_s(Reading[temp++],"One"); break;
	case 2:strcpy_s(Reading[temp++], "Two"); break;
	case 3:strcpy_s(Reading[temp++], "Three"); break;
	case 4:strcpy_s(Reading[temp++], "Four"); break;
	case 5:strcpy_s(Reading[temp++], "Five"); break;
	case 6:strcpy_s(Reading[temp++], "Six"); break;
	case 7:strcpy_s(Reading[temp++], "Seven"); break;
	case 8:strcpy_s(Reading[temp++], "Eight"); break;
	case 9:strcpy_s(Reading[temp++], "Nine"); break;
	case 10:strcpy_s(Reading[temp++], "Ten"); break;
	case 11:strcpy_s(Reading[temp++], "Eleven"); break;
	case 12: strcpy_s(Reading[temp++], "Twelve"); break;
	case 13: strcpy_s(Reading[temp++], "Thirteen"); break;
	case 14:strcpy_s(Reading[temp++], "Fourteen"); break;
	case 15:strcpy_s(Reading[temp++], "Fifteen"); break;
	case 16:strcpy_s(Reading[temp++], "Sixteen"); break;
	case 17:strcpy_s(Reading[temp++], "Seventeen"); break;
	case 18:strcpy_s(Reading[temp++], "Eighteen"); break;
	case 19:strcpy_s(Reading[temp++], "Nineteen"); break;
	case 20:strcpy_s(Reading[temp++], "Twenty"); break;
	case 30:strcpy_s(Reading[temp++], "Thirty"); break;
	case 40:strcpy_s(Reading[temp++], "Forty"); break;
	case 50:strcpy_s(Reading[temp++], "Fifty"); break;
	case 60:strcpy_s(Reading[temp++], "Sixty"); break;
	case 70:strcpy_s(Reading[temp++], "Seventy"); break;
	case 80:strcpy_s(Reading[temp++], "Eighty"); break;
	case 90:strcpy_s(Reading[temp++], "Ninety"); break;

	}



}

