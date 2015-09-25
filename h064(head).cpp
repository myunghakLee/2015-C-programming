#include<iostream>
#include<fstream>

class magic_square
{
private:
	int volume;
	int square[60][60];
public:
	magic_square(std::ifstream &instream)
	{
		instream >> volume;
	}
	void make_magic_square();
	void make_magic_square_four();
	void make_magic_square_two();
	void make_magic_square_odd();
	void show_magic_square();


	void type_L(int i, int j);
	void type_U(int i, int j);
	void type_X(int i, int j);

};

						
