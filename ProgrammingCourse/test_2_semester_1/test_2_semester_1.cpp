#include "MF_library.h"

#include <iostream>
using namespace std;

#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));

	cout << "Test 2 semester 2" << endl << "Author: Micha Fularz" << endl << endl << endl;

	char znak = '0';

	do
	{
		showMenu();
		znak = chooseOption();
		switch (znak)
		{
		case '1':
			{
				//exercise_1_prepare();
				exercise_1();
			}
			break;
		case '2':
			{
				exercise_2();
			}
			break;
		case '3':
			{

			}
			break;
		case '4':
			{
			}
			break;
		case 'x':
		case 'X':
			cout << "Bye, bye, you will be missed!" << endl;
			break;
		default:
			cout << "Wrong choice. You die." << endl;
			break;
		}
	} while (znak != 'x' && znak != 'X');

	std::cin.sync();		// Flush The Input Buffer Just In Case
	std::cin.ignore();		// There's No Need To Actually Store The Users Input

	return 0;
}