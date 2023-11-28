#include "tests_linear_algebra.hpp"
#include "tests_Mat.hpp"
#include "tests_Perceptron.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	try
	{
		if (argc == 1)
		{
			// If no arguments are provided, run all tests
			std::cout << "Running testZeros()..." << std::endl;
			testZeros();
			std::cout << "Running testRandom()..." << std::endl;
			testRandom();
			std::cout << "Running testDot()..." << std::endl;
			testDot();
			std::cout << "Running testTruthTableInputs()..." << std::endl;
			testTruthTableInputs();
			std::cout << "Running testTruthTableOutputs()..." << std::endl;
			testTruthTableOutputs();
			std::cout << "Running testAll()..." << std::endl;
			testAll();
			std::cout << "Running testAny()..." << std::endl;
			testAny();
			std::cout << "Running testSigmoid()..." << std::endl;
			testSigmoid();
			std::cout << "Running testMatConstructor()..." << std::endl;
			testMatConstructor();
			std::cout << "Running testMatAddition()..." << std::endl;
			testMatAddition();
			std::cout << "Running testMatSubtraction()..." << std::endl;
			testMatSubtraction();
			std::cout << "Running testMatElementWiseProduct()..." << std::endl;
			testMatElementWiseProduct();
			std::cout << "Running testMatScalarAddition()..." << std::endl;
			testMatScalarAddition();
			std::cout << "Running testMatScalarSubtraction()..." << std::endl;
			testMatScalarSubtraction();
			std::cout << "Running testMatScalarProduct()..." << std::endl;
			testMatScalarProduct();
			std::cout << "Running testMatLessThan()..." << std::endl;
			testMatLessThan();
			std::cout << "Running testMatGreaterThan()..." << std::endl;
			testMatGreaterThan();
			std::cout << "Running testMatLessThanOrEqual()..." << std::endl;
			testMatLessThanOrEqual();
			std::cout << "Running testMatGreaterThanOrEqual()..." << std::endl;
			testMatGreaterThanOrEqual();
			std::cout << "Running testMatEqual()..." << std::endl;
			testMatEqual();
			std::cout << "Running testMatNotEqual()..." << std::endl;
			testMatNotEqual();
			std::cout << "Running testMatLessThanMat()..." << std::endl;
			testMatLessThanMat();
			std::cout << "Running testMatGreaterThanMat()..." << std::endl;
			testMatGreaterThanMat();
			std::cout << "Running testMatLessThanOrEqualMat()..." << std::endl;
			testMatLessThanOrEqualMat();
			std::cout << "Running testMatGreaterThanOrEqualMat()..." << std::endl;
			testMatGreaterThanOrEqualMat();
			std::cout << "Running testMatEqualMat()..." << std::endl;
			testMatEqualMat();
			std::cout << "Running testMatNotEqualMat()..." << std::endl;
			testMatNotEqualMat();
			std::cout << "Running testMatT()..." << std::endl;
			testMatT();
			std::cout << "Running testMatGetRow()..." << std::endl;
			testMatGetRow();
			std::cout << "Running testMatGetCol()..." << std::endl;
			testMatGetCol();
			std::cout << "Running testPerceptronConstructor()..." << std::endl;
			testPerceptronConstructor();
			std::cout << "Running testPerceptronForward()..." << std::endl;
			testPerceptronForward();
			std::cout << "Running testPerceptronBackward()..." << std::endl;
			testPerceptronBackward();
			std::cout << "Running testPerceptronTrain()..." << std::endl;
			testPerceptronTrain();
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
					testZeros();
					testRandom();
					testDot();
					testSigmoid();
					testTruthTableInputs();
					testTruthTableOutputs();
					testAll();
					testAny();
				}
				else if (test_name == "Mat")
				{
					testMatConstructor();
					testMatAddition();
					testMatSubtraction();
					testMatElementWiseProduct();
					testMatScalarAddition();
					testMatScalarSubtraction();
					testMatScalarProduct();
					testMatLessThan();
					testMatGreaterThan();
					testMatLessThanOrEqual();
					testMatGreaterThanOrEqual();
					testMatEqual();
					testMatNotEqual();
					testMatLessThanMat();
					testMatGreaterThanMat();
					testMatLessThanOrEqualMat();
					testMatGreaterThanOrEqualMat();
					testMatEqualMat();
					testMatNotEqualMat();
					testMatT();
					testMatGetRow();
					testMatGetCol();
				}
				else if (test_name == "Perceptron")
				{
					testPerceptronConstructor();
					testPerceptronForward();
					testPerceptronBackward();
					testPerceptronTrain();
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
