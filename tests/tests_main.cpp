#include "tests_linear_algebra.hpp"
#include "tests_Mat.hpp"
#include "tests_Perceptron.hpp"
#include "tests_autograd.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	try
	{
		if (argc == 1)
		{
			// If no arguments are provided, run all tests
			std::cout << "Running all tests..." << std::endl;
			runTestsLinearAlgebra();
			runTestsMat();
			runTestsPerceptron();
			runTestsAutograd();
			std::cout << "All tests passed!" << std::endl;
		}
		else
		{
			// Otherwise, run the specified tests
			for (int i = 1; i < argc; i++)
			{
				std::string test_name = argv[i];
				if (test_name == "linear_algebra")
				{
					runTestsLinearAlgebra();
				}
				else if (test_name == "Mat")
				{
					runTestsMat();
				}
				else if (test_name == "Perceptron")
				{
					runTestsPerceptron();
				}
				else if (test_name == "autograd")
				{
					runTestsAutograd();
				}
				else
				{
					throw "Invalid test name";
				}
			}
			std::cout << "Specified tests passed!" << std::endl;
		}
	}
	catch (const char *error)
	{
		std::cerr << error << std::endl;
	}
	catch (std::string error)
	{
		std::cerr << error << std::endl;
	}
	catch (...)
	{
		std::cerr << "An unknown error occurred" << std::endl;
	}
	return 0;
}
