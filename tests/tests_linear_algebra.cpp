#include "tests_linear_algebra.hpp"
#include "../core/linear_algebra.hpp"
#include "../core/Mat.hpp"
#include <iostream>
#include <cmath>
#include <string>

void testZeros()
{
	Mat *zero_matrix = zeros(4, 3);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (zero_matrix->getData()[i][j] != 0.f)
			{
				delete zero_matrix;
				throw "testZeros failed: not all elements are 0";
			}
		}
	}
	delete zero_matrix;
}

void testRandom()
{
	Mat *random_matrix = random(4, 3);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (random_matrix->getData()[i][j] < 0 || random_matrix->getData()[i][j] > 1)
			{
				delete random_matrix;
				throw "testRandom failed: not all elements are between 0 and 1";
			}
		}
	}
	delete random_matrix;
}

void testDot()
{
	Mat *a = random(4, 3);
	Mat *b = random(3, 4);
	Mat *result = nullptr;
	try
	{
		result = dot(a, b);
		if (result->getRows() != a->getRows() || result->getCols() != b->getCols())
		{
			throw "result matrix has incorrect dimensions";
		}
		delete a;
		delete b;
		delete result;
	}
	catch (const char *e)
	{
		delete a;
		delete b;
		delete result;
		throw "testDot failed: " + std::string(e);
	}
}

void testSigmoid()
{
	Mat *a = zeros(4, 3);
	Mat *result;
	try
	{
		result = sigmoid(a);
		if (result->getRows() != a->getRows() || result->getCols() != a->getCols())
		{
			throw "result matrix has incorrect dimensions";
		}
		for (int i = 0; i < result->getRows(); i++)
		{
			for (int j = 0; j < result->getCols(); j++)
			{
				if (result->getData()[i][j] != 0.5)
				{
					throw "not all elements have the correct value";
				}
			}
		}
		delete a;
		delete result;
	}
	catch(const char *e)
	{
		delete a;
		delete result;
		throw "testSigmoid failed: " + std::string(e);
	}
	catch(std::string e)
	{
		delete a;
		delete result;
		throw "testSigmoid failed: " + e;
	}
}

void testTruthTableInputs()
{
	Mat *result;
	result = TruthTableInputs(4, 2);
	if ((result->getRows() != 4 || result->getCols() != 2) ||
		(result->getData()[0][0] != 0 || result->getData()[0][1] != 0) ||
		(result->getData()[1][0] != 1 || result->getData()[1][1] != 0) ||
		(result->getData()[2][0] != 0 || result->getData()[2][1] != 1) ||
		(result->getData()[3][0] != 1 || result->getData()[3][1] != 1))
	{
		delete result;
		throw "testTruthTableInputs failed: incorrect result";
	}
	delete result;
}

void testTruthTableOutputs()
{
	int array[4] = {0, 1, 1, 0};
	Mat *result = TruthTableOutputs(array, 4);
	if ((result->getRows() != 4 || result->getCols() != 1) ||
		(result->getData()[0][0] != 0) ||
		(result->getData()[1][0] != 1) ||
		(result->getData()[2][0] != 1) ||
		(result->getData()[3][0] != 0))
	{
		delete result;
		throw "testTruthTableOutputs failed: incorrect result";
	}
	delete result;
}
