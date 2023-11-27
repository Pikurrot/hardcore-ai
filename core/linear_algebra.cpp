#include "linear_algebra.hpp"
#include "Mat.hpp"
#include <random>
#include <string>

// Returns a new Mat of zeros.
Mat zeros(const int rows, const int cols)
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

	return Mat(data, rows, cols);
}

// Returns a random float between 0 and 1.
float randomF()
{
	return (float)rand() / RAND_MAX;
}

// Returns a new Mat of random floats between 0 and 1.
Mat random(const int rows, const int cols)
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

	return Mat(data, rows, cols);
}

// Returns a new Mat, the dot product of a and b.
Mat dot(const Mat &a, const Mat &b)
{
	if (a.getCols() != b.getRows())
	{
		throw "Mat dot: Matrices must have compatible dimensions";
	}

	float **data = new float *[a.getRows()];

	for (int i = 0; i < a.getRows(); i++)
	{
		data[i] = new float[b.getCols()];

		for (int j = 0; j < b.getCols(); j++)
		{
			data[i][j] = 0;

			for (int k = 0; k < a.getCols(); k++)
			{
				data[i][j] += a.getValue(i, k) * b.getValue(k, j);
			}
		}
	}

	return Mat(data, a.getRows(), b.getCols());
}

// Returns the sigmoid of x.
float sigmoid(const float x)
{
	try
	{
		return 1 / (1 + exp(-x));
	}
	catch (const char *e)
	{
		throw "sigmoid: " + std::string(e);
	}
}

// Returns a new Mat, the sigmoid of x.
Mat sigmoid(const Mat &x)
{
	float **data = new float *[x.getRows()];

	try
	{
		for (int i = 0; i < x.getRows(); i++)
		{
			data[i] = new float[x.getCols()];

			for (int j = 0; j < x.getCols(); j++)
			{
				data[i][j] = sigmoid(x.getValue(i, j));
			}
		}

		return Mat(data, x.getRows(), x.getCols());
	}
	catch (const char *e)
	{
		delete data;
		throw "sigmoid: " + std::string(e);
	}
	catch (std::string e)
	{
		delete data;
		throw "sigmoid: " + e;
	}
}

// Returns the inputs of a truth table of specified dimensions.
Mat truthTableInputs(const int rows, const int cols)
{
	float **data = new float *[rows];

	for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];

		for (int j = 0; j < cols; j++)
		{
			data[i][j] = (i >> j) & 1;
		}
	}

	return Mat(data, rows, cols);
}

// Returns the outputs in a truth table shape
Mat truthTableOutputs(const int *array, const int rows)
{
	float **data = new float *[rows];

	for (int i = 0; i < rows; i++)
	{
		data[i] = new float[1];
		data[i][0] = array[i];
	}

	return Mat(data, rows, 1);
}

// Sum of scalar and Mat
Mat operator+(const float scalar, const Mat &other)
{
	return other + scalar;
}

// Difference of scalar and Mat
Mat operator-(const float scalar, const Mat &other)
{
	float **data = new float *[other.getRows()];

	for (int i = 0; i < other.getRows(); i++)
	{
		data[i] = new float[other.getCols()];

		for (int j = 0; j < other.getCols(); j++)
		{
			data[i][j] = scalar - other.getValue(i, j);
		}
	}

	return Mat(data, other.getRows(), other.getCols());
}

// Product of scalar and Mat
Mat operator*(const float scalar, const Mat &other)
{
	return other * scalar;
}

// Division of scalar and Mat
Mat operator/(const float scalar, const Mat &other)
{
	float **data = new float *[other.getRows()];

	for (int i = 0; i < other.getRows(); i++)
	{
		data[i] = new float[other.getCols()];

		for (int j = 0; j < other.getCols(); j++)
		{
			data[i][j] = scalar / other.getValue(i, j);
		}
	}

	return Mat(data, other.getRows(), other.getCols());
}
