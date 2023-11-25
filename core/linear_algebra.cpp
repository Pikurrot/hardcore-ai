#include "linear_algebra.hpp"
#include "Mat.hpp"
#include <random>

using namespace std;

// Returns a matrix of zeros.
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

// Returns a random float between 0 and 1.
float randomF()
{
	return (float)rand() / RAND_MAX;
}

// Returns a matrix of random floats between 0 and 1.
Mat *random(int rows, int cols)
{
	float **data = new float *[rows];

	for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];

		for (int j = 0; j < cols; j++)
		{
			data[i][j] = randomF();
		}
	}

	return new Mat(data, rows, cols);
}

// Returns a new Mat, the dot product of a and b.
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

// Returns the sigmoid of x.
float sigmoid(float x)
{
	return 1 / (1 + exp(-x));
}

// Returns a new Mat, the sigmoid of x.
Mat *sigmoid(Mat *x)
{
	float **data = new float *[x->getRows()];

	for (int i = 0; i < x->getRows(); i++)
	{
		data[i] = new float[x->getCols()];

		for (int j = 0; j < x->getCols(); j++)
		{
			data[i][j] = sigmoid(x->getData()[i][j]);
		}
	}

	return new Mat(data, x->getRows(), x->getCols());
}
