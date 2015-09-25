#include<iostream>
#include"problem61(head).h"


void LIFE_GAME::play()
{
	
	char Ccell[110][110];
	int alive = 0;// 조건검사에서 이웃이 얼마나 살아남았나
	int teria = 0;//최후에 살아남은 박테리아수

	for (int j = 0; j < 110; j++)
	{
		for (int i = 0; i < 110; i++)
		{
			Ccell[i][j] = 0;
		}
	}
	///////////////////////////////////////////////////////////////////////////////
	for (int m = 1; m<Ns + 1; m++)
	{
		for (int n = 1; n<Ng + 1; n++)
		{
			Ccell[m][n] = cell[m][n];
			if (Ccell[m][n] == 'x')
			{
				Ccell[m][n] = 'X';
			}
			else if (Ccell[m][n] == 'o')
			{
				Ccell[m][n] = 'O';
			}
		}
	}


	for (int m = 1; m<Ns + 1; m++)
	{
		for (int n = 1; n<Ng + 1; n++)
		{
			cell[m][n] = cell[m][n];
			if (cell[m][n] == 'x')
			{
				cell[m][n] = 'X';
			}
			else if (cell[m][n] == 'o')
			{
				cell[m][n] = 'O';
			}
		}
	}


	for (int l = 0; l<time; l++)
	{
		////////////////////////////살아있는 이웃 수 판단/////////////
		for (int j = 1; j<Ns + 1; j++)
		{
			for (int k = 1; k<Ng + 1; k++)
			{
				alive = 0;
				for (int m = -1; m<2; m++)
				{
					for (int n = -1; n<2; n++)
					{
						if ((n == 0) && (m == 0))
						{
						}
						else
						{
							if (cell[j + m][k + n] == 'O')
							{
								alive = alive + 1;
							}
						}
					}
				}
				/////////////////////////////////////////////////
				if ((alive<2) && (cell[j][k] == 'O'))
				{
					Ccell[j][k] = Ccell[j][k] + 9;
				}
				else if ((cell[j][k] == 'O') && (alive>1) && (alive<4))
				{
				}
				else if ((cell[j][k] == 'X') && (alive == 3))
				{
					Ccell[j][k] = Ccell[j][k] - 9;
				}
				else if ((cell[j][k] == 'O') && (alive>3))
				{
					Ccell[j][k] = Ccell[j][k] + 9;
				}
			}
		}
		for (int m = 1; m<Ns + 1; m++)
		{
			for (int n = 1; n<Ng + 1; n++)
			{
				cell[m][n] = Ccell[m][n];
			}
		}
	}
	teria = 0;
	for (int m = 1; m<Ns + 1; m++)
	{
		for (int n = 1; n<Ng + 1; n++)
		{
			if ((cell[m][n] == 'O') || (cell[m][n] =='o'))
			{
				teria = teria + 1;
			}
		}
	}
	std::cout << teria << std::endl;
	for (int m = 1; m<Ns + 1; m++)
	{
		for (int n = 1; n<Ng + 1; n++)
		{
			std::cout << cell[m][n];
		}
		std::cout << std::endl;
	}

}

