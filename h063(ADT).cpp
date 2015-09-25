#include"problem63(head).h"

void magic_square :: make_magic_square()
{
	int i, j, k;
	//////////////////////첫번째행의 중앙에 1을 넣어야 하므로////////////////////
	i = 0;
	j = volume / 2;
	///////////////////////////////////////////////////////////////////////////


	for (k = 0; k<volume*volume;)//총 volume*volume 즉 25칸을 채워야 하기에 k<volume*volume라고 하였다.
	{
		if (i<0 && j >= 0)//i는음수가 되고 j만 양수인경우
		{
			i = volume - 1;
		}
		else if (j<0 && i >= 0)//j는음수가 되고 i만 양수인경우
		{
			j = volume - 1;
		}
		else if (i<0 && j<0)//j와 i둘다 음수인경우
		{
			i += 2;
			j--;
		}
		else if (arr[i][j] < 0)//arr[i][j]안에 아무 숫자도 없는 경우(유일하게 arr안에 숫자를 넣어주는 if문이다.)
		{
			arr[i][j] = k + 1;//k는 0부터 24까지 이 if문에 들어올때마다 1씩 증가한다.
			i--;
			j++;
			k++;
		}
		else if (arr[i][j] >0)//arr[i][j]안에 이미 숫자도 있는 경우
		{
			i += 2;
			j--;
		}

		///////////////////arr[0][2] =1 인 경우는 상관 없지만 다른 경우 i나 j가 5를 넘어가는 경우가 생기기 때문에 붙여주었다.//////////////////
		i %= volume;
		j %= volume;
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}

}
void magic_square :: print_magic_square()//arr을 출력하라
{
	int i, j;

	for (i = 0; i<volume; i++)
	{
		for (j = 0; j<volume; j++)
		{
			std::cout << arr[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

						
