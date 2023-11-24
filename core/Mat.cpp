#include "Mat.hpp"

using namespace std;

// Constructor
Mat::Mat(float **data, int rows, int cols)
{
	this->data = data;
	this->rows = rows;
	this->cols = cols;
}

// Destructor
Mat::~Mat()
{
	for (int i = 0; i < this->rows; i++)
	{
		delete[] this->data[i];
	}

	delete[] this->data;
	this->data = nullptr;
}

// Sum
Mat *Mat::operator+(Mat *other)
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
			data[i][j] = this->data[i][j] + other->data[i][j];
		}
	}

	return new Mat(data, this->rows, this->cols);
}

// Difference
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

// Element-wise product
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

// Sum
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

// Difference
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

// Product
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
