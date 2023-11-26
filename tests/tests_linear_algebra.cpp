#include "tests_linear_algebra.hpp"
#include "../core/linear_algebra.hpp"
#include "../core/Mat.hpp"
#include <iostream>
#include <cmath>

void testZeros()
{
	Mat *zero_matrix = zeros(4, 3);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (zero_matrix->getData()[i][j] != 0)
			{
				throw "testZeros failed";
			}
		}
	}
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
				throw "testRandom failed";
			}
		}
	}
}

void testDot()
{
	Mat *a = random(4, 3);
	Mat *b = random(3, 4);
	Mat *result = dot(a, b);
	if (result->getRows() != a->getRows() || result->getCols() != b->getCols())
	{
		throw "testDot failed";
	}
}

void testSigmoid()
{
	Mat *a = zeros(4, 3);
	Mat *result = sigmoid(a);
	if (result->getRows() != a->getRows() || result->getCols() != a->getCols())
	{
		throw "testSigmoid failed";
	}
	for (int i = 0; i < result->getRows(); i++)
	{
		for (int j = 0; j < result->getCols(); j++)
		{
			if (result->getData()[i][j] != 0.5)
			{
				throw "testSigmoid failed";
			}
		}
	}
}

void testTruthTableInputs()
{
	Mat *result = TruthTableInputs(4, 2);
	if ((result->getRows() != 4 || result->getCols() != 2) ||
		(result->getData()[0][0] != 0 || result->getData()[0][1] != 0) ||
		(result->getData()[1][0] != 1 || result->getData()[1][1] != 0) ||
		(result->getData()[2][0] != 0 || result->getData()[2][1] != 1) ||
		(result->getData()[3][0] != 1 || result->getData()[3][1] != 1))
	{
		throw "testTruthTableInputs failed";
	}
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
		throw "testTruthTableOutputs failed";
	}
}
