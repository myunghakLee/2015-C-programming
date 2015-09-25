					
/*********************************************************
*          전자정보통신대학 컴퓨터공학부                 *
*             20143086 이명학                            *
*            problem 48 : 사이저 암호문 복호기법         *
*********************************************************/


#include<iostream>
#include<fstream>

float char_percent[26] = {8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.996, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074};


class descrambling
{
private:
	char arr[600];
	int arr_percent[26];
	
public:
	descrambling(std::ifstream & instream)
	{
		instream >> arr;
	}
	int search_key_number();
	void descrambling_sentense(int key);
};


void main()
{
	std::ifstream instream;

	instream.open("input.txt");

	char a = 'a';
	char b = 'z';
	char c = 'A';
	char d = 'Z';

	int cases;
	instream >> cases;

	for (int i = 0; i < cases; i++)
	{
		descrambling as(instream);
		as.descrambling_sentense(as.search_key_number());
	}

}

int descrambling::search_key_number()
{
	int len = strlen(arr);
	int num =0;
	float arr_num[26] = {0};
	float KaiSquare[2] = {999999,9999999};
	int key = 0;
	int save;
	///////////////////////////////////////////////////////////////각 글자가 몇개씩 나오는지 판단///////////////////////////////////////////////////////////////
	for (int i = 0; i < len; i++)
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			arr_num[arr[i] - 'a']++;
			num++;
		}
		else if (arr[i] >= 'A' && arr[i] <= 'Z')
		{
			arr_num[arr[i] - 'A']++;
			num++;
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////key 값을 구함/////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 26; i++)
	{
		KaiSquare[1] = 0;
		for (int j = 0; j < 26; j++)
		{
			KaiSquare[1] += ((arr_num[(j + i) % 26] / num*100)*(arr_num[(j + i) % 26] / num*100)) / char_percent[j];
		}

		KaiSquare[1] < KaiSquare[0] ? KaiSquare[0] = KaiSquare[1] , key=i : 0;

		
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	return key;
}

void descrambling::descrambling_sentense(int key)
{
	int move = (26 - key)%26;

	for (int i = 0;; i++)
	{
		if (arr[i] == NULL)
		{
			break;
		}
		if ((arr[i] >= 'a' && arr[i] <= 'z'))
		{
			if (arr[i] + move>'z')
			{
				arr[i] -= 26;
				arr[i] += move;
			}
			else
			{
				arr[i] += move;
			}
		}
		else if (arr[i] >= 'A' && arr[i] <= 'Z')
		{
			if (arr[i] + move>90)
			{
				arr[i] -= 26;
				arr[i] += move;
			}
			else
			{
				arr[i] += move;
			}
		}
	}
	std::cout << arr << std::endl;
}
