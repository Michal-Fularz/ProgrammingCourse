#include "StudentsProblems.h"

#include <iostream>

int main(void)
{
	// symptomps: version with OpenMP enabled is much slower
	// INVESTIGATION:
	// - this program allocates a lot of 2d tables, which is very, very slow when run with debugging (shortcut: F5). For measuring purposes programs should be run without debugging (shortcut: CTRL + F5)
	// - program is using recursion, which spawns a lot of threads. Solution - first function call should be done with pragma and then sequential version should be used. For details look into the source file.
	//problem_2014_2015_determinant_Laplace_expansion();


	// TODO - the problem is not solved yet :/
	problem_2014_2015_merge_sort_recursion();

	std::cout << "Press enter to continue..." << std::endl;
	std::cin.sync();		// Flush The Input Buffer Just In Case
	std::cin.ignore();		// There's No Need To Actually Store The Users Input

	return 1;
}