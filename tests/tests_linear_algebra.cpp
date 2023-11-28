#include "tests_linear_algebra.hpp"
#include "../core/linear_algebra.hpp"
#include "../core/Mat.hpp"
#include <iostream>
#include <cmath>
#include <string>

void testZeros()
{
	Mat zero_matrix = zeros(4, 3);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (zero_matrix.getValue(i, j) != 0.f)
			{
				throw "testZeros failed: not all elements are 0";
			}
		}
	}
}

void testRandom()
{
	Mat random_matrix = random(4, 3);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (random_matrix.getValue(i, j) < 0 || random_matrix.getValue(i, j) > 1)
			{
				throw "testRandom failed: not all elements are between 0 and 1";
			}
		}
	}
}

void testDot()
{
	Mat a = random(4, 3);
	Mat b = random(3, 4);
	try
	{
		Mat result = dot(a, b);
		if (result.getRows() != a.getRows() || result.getCols() != b.getCols())
		{
			throw "result matrix has incorrect dimensions";
		}
	}
	catch (const char *e)
	{
		throw "testDot failed: " + std::string(e);
	}
}

void testSigmoid()
{
	Mat a = zeros(4, 3);
	try
	{
		Mat result = sigmoid(a);
		if (result.getRows() != a.getRows() || result.getCols() != a.getCols())
		{
			throw "result matrix has incorrect dimensions";
		}
		for (int i = 0; i < result.getRows(); i++)
		{
			for (int j = 0; j < result.getCols(); j++)
			{
				if (result.getValue(i, j) != 0.5)
				{
					throw "not all elements have the correct value";
				}
			}
		}
	}
	catch(const char *e)
	{
		throw "testSigmoid failed: " + std::string(e);
	}
	catch(std::string e)
	{
		throw "testSigmoid failed: " + e;
	}
}

void testTruthTableInputs()
{
	Mat result = truthTableInputs(4, 2);
	if ((result.getRows() != 4 || result.getCols() != 2) ||
		(result.getValue(0, 0) != 0 || result.getValue(0, 1) != 0) ||
		(result.getValue(1, 0) != 1 || result.getValue(1, 1) != 0) ||
		(result.getValue(2, 0) != 0 || result.getValue(2, 1) != 1) ||
		(result.getValue(3, 0) != 1 || result.getValue(3, 1) != 1))
	{
		throw "testTruthTableInputs failed: incorrect result";
	}
}

void testTruthTableOutputs()
{
	int array[4] = {0, 1, 1, 0};
	Mat result = truthTableOutputs(array, 4);
	if ((result.getRows() != 4 || result.getCols() != 1) ||
		(result.getValue(0, 0) != 0) ||
		(result.getValue(1, 0) != 1) ||
		(result.getValue(2, 0) != 1) ||
		(result.getValue(3, 0) != 0))
	{
		throw "testTruthTableOutputs failed: incorrect result";
	}
}

void testAll()
{
	Mat a = zeros(4, 3);
	if (all(a))
	{
		throw "testAll failed: all elements are 0 but all() returned true";
	}
	a = random(4, 3);
	if (!all(a))
	{
		throw "testAll failed: there are no 0 elements but all() returned false";
	}
}

void testAny()
{
	Mat a = zeros(4, 3);
	if (any(a))
	{
		throw "testAny failed: all elements are 0 but any() returned true";
	}
	a = random(4, 3);
	if (!any(a))
	{
		throw "testAny failed: there are no 0 elements but any() returned false";
	}
}
