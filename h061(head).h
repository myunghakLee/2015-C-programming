#ifndef _LIFE_GAME_
#define _LIFE_GAME_


#include<fstream>
class LIFE_GAME
{
private:
	int Ng, Ns;//Ng=가로의 칸수 Ns= 세로의 칸수
	int time;//time은 세대가 얼마나 지났는지
	char cell[110][110];
public:
	LIFE_GAME(std::ifstream & instream)
	{
		instream >> Ns >> Ng >> time;
		for (int j = 0; j < 110; j++)
		{
			for (int i = 0; i < 110; i++)
			{
				cell[i][j] = 0;
			}
		}

		for (int j = 0; j<Ns + 2; j++)///////////////////////////cell 안에input값 입력////////////////
		{
			for (int k = 0; k<Ng + 2; k++)
			{
				if ((j == 0) || (k == 0) || (j == Ns + 1) || (k == Ng + 1))
				{
					cell[j][k] = 'X';
				}
				/////////////////////////////////////////////////
				else
				{
					instream >> cell[j][k];
					if ((cell[j][k] == 32) || (cell[j][k] == 10))
					{
						for (;;)
						{
							instream >> cell[j][k];
							if ((cell[j][k] != 32) && (cell[j][k] != 10))
							{
								break;
							}
						}
					}
				}
			}
		}

	}
	void play();

};

#endif

						
