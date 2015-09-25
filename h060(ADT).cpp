#include<iostream>
#include"problem60(head).h"

void mors::changing()
{
	int temp = 0;
	int temp2 = 0;
	char a[100];
	while (mark[temp] > 0)
	{
		while ((mark[temp] > 0) && (mark[temp] != '|') && (mark[temp] != '#'))
		{
			a[temp2++] = mark[temp++];
			
		}
		a[temp2] = 0;
		sub_changing(a);
		for (int i = 0; i < temp2; i++){ a[i] = NULL; }
		if (mark[temp] == '#')
		{
			std::cout << "_";
			temp++;
		}
		else if (mark[temp] == '|')
		{
			temp++;
		}
		temp2 = 0;
	}
	std::cout <<std:: endl;

}

void mors::sub_changing(char a[])
{
	if (!strcmp(a, ".-")){ std::cout << "A"; }
	else if (!strcmp(a, "-...")){ std::cout << "B"; }
	else if (!strcmp(a, "-.-.")){ std::cout << "C"; }
	else if (!strcmp(a, "-..")){ std::cout << "D"; }
	else if (!strcmp(a, ".")){ std::cout << "E"; }
	else if (!strcmp(a, "..-.")){ std::cout << "F"; }
	else if (!strcmp(a, "--.")){ std::cout << "G"; }
	else if (!strcmp(a, "....")){ std::cout << "H"; }
	else if (!strcmp(a, "..")){ std::cout << "I"; }
	else if (!strcmp(a, ".---")){ std::cout << "J"; }
	else if (!strcmp(a, "-.-")){ std::cout << "K"; }
	else if (!strcmp(a, ".-..")){ std::cout << "L"; }
	else if (!strcmp(a, "--")){ std::cout << "M"; }
	else if (!strcmp(a, "-.")){ std::cout << "N"; }
	else if (!strcmp(a, "---")){ std::cout << "O"; }
	else if (!strcmp(a, ".--.")){ std::cout << "P"; }
	else if (!strcmp(a, "--.-")){ std::cout << "Q"; }
	else if (!strcmp(a, ".-.")){ std::cout << "R"; }
	else if (!strcmp(a, "...")){ std::cout << "S"; }
	else if (!strcmp(a, "-")){ std::cout << "T"; }
	else if (!strcmp(a, "..-")){ std::cout << "U"; }
	else if (!strcmp(a, "...-")){ std::cout << "V"; }
	else if (!strcmp(a, ".--")){ std::cout << "W"; }
	else if (!strcmp(a, "-..-")){ std::cout << "X"; }
	else if (!strcmp(a, "-.--")){ std::cout << "Y"; }
	else if (!strcmp(a, "--..")){ std::cout << "Z"; }
	else if (!strcmp(a, "#")){ std::cout << "_"; }
}



