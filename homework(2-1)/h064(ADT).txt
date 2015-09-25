#include"problem64.h"





void magic_square::make_magic_square_four()
{
	for (int i = 0; i < volume; i++)
	{
		for (int j = 0; j < volume; j++)
		{


			square[i][j] = i*volume + j + 1;

			for (int k = 0; k < 13; k++)
			{
				if ((abs(i - j) == k * 4))
				{
					square[i][j] = (volume*volume) - (i*volume + j);
					break;
				}
			}

			for (int k = 1; k < 25; k++)
			{
				if (i + j == k * 4-1)
				{
					square[i][j] = (volume*volume) - (i*volume + j);
					break;
				}
			}


		}
	}
}
void magic_square::make_magic_square_two()
{
	make_magic_square_odd();

	for (int i = 0; i < volume; i+=2)
	{
		if (i < volume / 2 -1)
		{
			for (int j = 0; j < volume; j+=2)///////////////////////l
			{
				type_L(i, j);
			}
		}
		else if (i == (volume / 2 - 1))
		{
				for (int j = 0; j < volume; j += 2)/////////////////////u
				{
					if (j == (volume / 2 - 1))
					{
						type_U(i,j);
					}
					else
					{
						type_L(i, j);
					}
				}
		}
		else if (i== (volume / 2 + 1))
		{
				for (int j = 0; j < volume; j += 2)/////////////////////u
				{
					if (j != (volume / 2 - 1))
					{
						type_U(i, j);
					}
					else
					{
						type_L(i, j);
					}
				}


		}
		else
		{
			for (int j = 0; j < volume; j += 2)//////////////////////x
			{
				type_X(i, j);
			}
		}
	}
}
void magic_square::make_magic_square()
{
	if (volume % 4 == 0)
	{
		make_magic_square_four();
	}
	else
	{
		make_magic_square_two();
	}
}
void magic_square::show_magic_square()
{
	for (int i = 0; i < volume;i++)
	{
		for (int j = 0; j < volume; j++)
		{
			std::cout << square[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void magic_square::make_magic_square_odd()
{
	int i, j, k;
	//////////////////////첫번째행의 중앙에 1을 넣어야 하므로////////////////////
	i = 0;
	j = volume / 2;
	///////////////////////////////////////////////////////////////////////////


	for (int k = 0; k < volume; k++)
	{
		for (int l = 0; l < volume; l++)
		{
			square[k][l] = -1;
		}
	}




	for (k = 0; k<volume*volume;)//총 volume*volume 즉 25칸을 채워야 하기에 k<volume*volume라고 하였다.
	{
		if (i<0 && j >= 0)//i는음수가 되고 j만 양수인경우
		{
			i = volume - 2;
		}
		else if (j<0 && i >= 0)//j는음수가 되고 i만 양수인경우
		{
			j = volume - 1;
		}
		else if (i<0 && j<0)//j와 i둘다 음수인경우
		{
			i += 4;
			j -=2;
		}
		else if (square[i][j] < 0)//arr[i][j]안에 아무 숫자도 없는 경우(유일하게 arr안에 숫자를 넣어주는 if문이다.)
		{
			square[i][j] = k + 1;//k는 0부터 24까지 이 if문에 들어올때마다 1씩 증가한다.
			i-=2;
			j+=2;
			k += 4;
		}
		else if (square[i][j] >0)//arr[i][j]안에 이미 숫자도 있는 경우
		{
			i += 4;
			j -= 2;
		}

		///////////////////arr[0][2] =1 인 경우는 상관 없지만 다른 경우 i나 j가 5를 넘어가는 경우가 생기기 때문에 붙여주었다.//////////////////
		i %= volume;
		j %= volume;
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}

}

void magic_square::type_L(int i, int j)
{
	square[i][j] = square[i][j+1] + 3;
	square[i + 1][j] = square[i][j + 1] + 1;
	square[i + 1][j + 1] = square[i][j + 1] + 2;
}
void magic_square::type_U(int i, int j)
{
	square[i][j + 1] += 3;
	square[i][j] = square[i][j + 1] - 3;
	square[i + 1][j] = square[i][j + 1] - 2;
	square[i + 1][j + 1] = square[i][j + 1] - 1;
}
void magic_square::type_X(int i, int j)
{
	square[i][j+1] += 3;
	square[i][j] = square[i][j+1] - 3;
	square[i + 1][j] = square[i][j+1] - 1;
	square[i + 1][j + 1] = square[i][j+1] - 2;
}

						
