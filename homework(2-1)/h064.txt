#include"problem64.h"

void main()
{
	std::ifstream instream;

	instream.open("input.txt");

	int cases;
	instream >> cases;
	for (int i = 0; i < cases; i++)
	{
		magic_square ma(instream);
		ma.make_magic_square();
		ma.show_magic_square();
	}
}

						
