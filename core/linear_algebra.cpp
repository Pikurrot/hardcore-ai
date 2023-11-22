#include "linear_algebra.hpp"
#include "Mat.hpp"
#include <random>

using namespace std;

// Return a matrix of zeros
Mat *zeros(int rows, int cols)
{
	float **data = new float *[rows];

	for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];

		for (int j = 0; j < cols; j++)
		{
			data[i][j] = 0;
		}
	}

	return new Mat(data, rows, cols);
}

// Return a matrix of random values between 0 and 1
Mat *random(int rows, int cols)
{
	float **data = new float *[rows];

	for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];

		for (int j = 0; j < cols; j++)
		{
			data[i][j] = (float)rand() / RAND_MAX;
		}
	}

	return new Mat(data, rows, cols);
}

// Dot product
Mat *dot(Mat *a, Mat *b)
{
	if (a->getCols() != b->getRows())
	{
		throw "Matrices must have compatible dimensions";
	}

	float **data = new float *[a->getRows()];

	for (int i = 0; i < a->getRows(); i++)
	{
		data[i] = new float[b->getCols()];

		for (int j = 0; j < b->getCols(); j++)
		{
			data[i][j] = 0;

			for (int k = 0; k < a->getCols(); k++)
			{
				data[i][j] += a->getData()[i][k] * b->getData()[k][j];
			}
		}
	}

	return new Mat(data, a->getRows(), b->getCols());
}
