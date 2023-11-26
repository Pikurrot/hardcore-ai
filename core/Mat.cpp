#include "Mat.hpp"

using namespace std;

// Creates a 2D Mat object given a 2D array of floats.
Mat::Mat(float **data, int rows, int cols)
{
	this->data = data;
	this->rows = rows;
	this->cols = cols;
}

// Releases the Mat's data.
Mat::~Mat()
{
	for (int i = 0; i < this->rows; i++)
	{
		delete[] this->data[i];
	}

	delete[] this->data;
}

// Sum of Mat and Mat.
Mat *Mat::operator+(Mat *other)
{
	if (this->rows != other->rows || this->cols != other->cols)
	{
		throw "Mat +: Matrices must have the same dimensions";
	}

	float **data = new float *[this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];

		for (int j = 0; j < this->cols; j++)
		{
			data[i][j] = this->data[i][j] + other->data[i][j];
		}
	}

	return new Mat(data, this->rows, this->cols);
}

// Difference of Mat and Mat.
Mat *Mat::operator-(Mat *other)
{
	if (this->rows != other->rows || this->cols != other->cols)
	{
		throw "Matrices must have the same dimensions";
	}

	float **data = new float *[this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];

		for (int j = 0; j < this->cols; j++)
		{
			data[i][j] = this->data[i][j] - other->data[i][j];
		}
	}

	return new Mat(data, this->rows, this->cols);
}

// Element-wise product of Mat and Mat.
Mat *Mat::operator*(Mat *other)
{
	if (this->rows != other->rows || this->cols != other->cols)
	{
		throw "Matrices must have the same dimensions";
	}

	float **data = new float *[this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];

		for (int j = 0; j < this->cols; j++)
		{
			data[i][j] = this->data[i][j] * other->data[i][j];
		}
	}

	return new Mat(data, this->rows, this->cols);
}

// Sum of Mat and scalar.
Mat *Mat::operator+(float scalar)
{
	float **data = new float *[this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];

		for (int j = 0; j < this->cols; j++)
		{
			data[i][j] = this->data[i][j] + scalar;
		}
	}

	return new Mat(data, this->rows, this->cols);
}

// Difference of Mat and scalar.
Mat *Mat::operator-(float scalar)
{
	float **data = new float *[this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];

		for (int j = 0; j < this->cols; j++)
		{
			data[i][j] = this->data[i][j] - scalar;
		}
	}

	return new Mat(data, this->rows, this->cols);
}

// Product of Mat and scalar.
Mat *Mat::operator*(float scalar)
{
	float **data = new float *[this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];

		for (int j = 0; j < this->cols; j++)
		{
			data[i][j] = this->data[i][j] * scalar;
		}
	}

	return new Mat(data, this->rows, this->cols);
}

// Transpose of Mat.
Mat *Mat::T()
{
	float **data = new float *[this->cols];

	for (int i = 0; i < this->cols; i++)
	{
		data[i] = new float[this->rows];

		for (int j = 0; j < this->rows; j++)
		{
			data[i][j] = this->data[j][i];
		}
	}

	return new Mat(data, this->cols, this->rows);
}
