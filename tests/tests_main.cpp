#include "tests_linear_algebra.hpp"
#include "tests_Mat.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	try
	{
		if (argc == 1)
		{
			// If no arguments are provided, run all tests
			testZeros();
			testRandom();
			testDot();
			testMatConstructor();
			testMatAddition();
			std::cout << "All tests passed!\n";
		}
		else
		{
			// Otherwise, run the specified tests
			for (int i = 1; i < argc; i++)
			{
				std::string test_name = argv[i];
				if (test_name == "linear_algebra")
				{
					testZeros();
					testRandom();
					testDot();
				}
				else if (test_name == "Mat")
				{
					testMatConstructor();
					testMatAddition();
				}
			}
			std::cout << "Specified tests passed!\n";
		}
	}
	catch (const char *error)
	{
		std::cerr << error << "\n";
	}
	return 0;
}
