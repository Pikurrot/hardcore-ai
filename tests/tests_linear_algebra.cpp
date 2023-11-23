#include "tests_linear_algebra.hpp"
#include "../core/linear_algebra.hpp"
#include "../core/Mat.hpp"
#include <iostream>
#include <cmath>

void testZeros()
{
	Mat *zero_matrix = zeros(3, 3);
	for (int i = 0; i < 3; i++)
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
	Mat *random_matrix = random(3, 3);
	for (int i = 0; i < 3; i++)
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
	Mat *a = random(3, 3);
	Mat *b = random(3, 3);
	Mat *result = dot(a, b);
	if (result->getRows() != a->getRows() || result->getCols() != b->getCols())
	{
		throw "testDot failed";
	}
}
