#include<iostream>
#include<fstream>

class connect_four
{
private:
	int num;
	int playing[50];
public:
	connect_four(std::ifstream & instream)
	{
		instream >> num;
		for (int i = 0; i < num; i++)
		{
			instream >> playing[i];
		}
	}
	void game_start();
	void check(char);
};



void main()
{
	std::ifstream instream;
	instream.open("input.txt");


	int a[3] = { 1, 1, 2 };

	

	int cases;
	instream >> cases;
	for (int i = 0; i < cases; i++)
	{
		connect_four game(instream);
		game.game_start();
	}

}



void connect_four::game_start()
{
	unsigned int board[6][7] = { 0 };

	////////////////////////////////////내리기(놓기)////////////////////////////////////
	for (int i = 0; i < num; i++)
	{
		playing[i]--;
		playing[i] %= 7;

		for (int j = 5; j >= 0; j--)
		{
			if (board[j][playing[i]] <= 0)
			{
				board[j][playing[i]] = (i % 2) + 1;
				break;
			}
		}
	}
	/////////////////////////////////////////////////////////////////////////////////////
	unsigned int false_board[8][9] = { 0 };

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if ((i == 0) || (i == 7) || (j == 0) || (j == 8)){ false_board[i][j] = 0; }
			else{ false_board[i][j] = board[i - 1][j - 1]; }
		}
	}

	for (int i = 1; i < 7; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			if (false_board[i][j] == false_board[i + 1][j + 1])
			{
				if ((j - i >= -2) && (j - i <= 3))
				{
					if (((false_board[i][j] == false_board[i + 1][j + 1]) && (false_board[i][j] == false_board[i + 2][j + 2]) && (false_board[i][j] == false_board[i + 3][j + 3])) && (false_board[i][j]>0))
					{
						std::cout << false_board[i][j] << std::endl;
						return;
					}

				}
			}

			if (false_board[i][j] == false_board[i + 1][j])
			{
				if (i < 4)
				{
					if (((false_board[i][j] == false_board[i + 1][j]) && (false_board[i][j] == false_board[i + 2][j]) && (false_board[i][j] == false_board[i + 3][j])) && (false_board[i][j]>0))
					{
						std::cout << false_board[i][j] << std::endl;
						return;
					}
				}
			}

			if (false_board[i][j] == false_board[i + 1][j - 1])
			{
				if ((i + j >= 5) && (i + j <= 10))
				{
					if (((false_board[i][j] == false_board[i + 1][j - 1]) && (false_board[i][j] == false_board[i + 2][j - 2]) && (false_board[i][j] == false_board[i + 3][j - 3])) && (false_board[i][j]>0))
					{
						std::cout << false_board[i][j] << std::endl;
						return;
					}
				}
			}

			if (false_board[i][j] == false_board[i][j + 1])
			{
				if (j < 5)
				{
					if (((false_board[i][j] == false_board[i][j + 1]) && (false_board[i][j] == false_board[i][j + 2]) && (false_board[i][j] == false_board[i][j + 3])) && (false_board[i][j]>0))
					{
						std::cout << false_board[i][j] << std::endl;
						return;
					}
				}
			}


		}

	}
	std::cout << 0 << std::endl;
}






						
