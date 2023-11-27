#include "Mat.hpp"

using namespace std;

Mat::Mat()
{
	this->data = nullptr;
	this->rows = 0;
	this->cols = 0;
}

// Creates a 2D Mat object given a 2D array of floats.
Mat::Mat(float **data, const int rows, const int cols) : data(data), rows(rows), cols(cols)
{
}

// Creates a copy of a 2D Mat object.
Mat::Mat(const Mat &other)
{
	this->rows = other.rows;
	this->cols = other.cols;
	this->data = new float *[this->rows];
	for (int i = 0; i < rows; i++)
	{
		this->data[i] = new float[cols];
		for (int j = 0; j < cols; j++)
		{
			this->data[i][j] = other.data[i][j];
		}
	}
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

// Copies the data from another Mat.
Mat &Mat::operator=(const Mat &other)
{
	if (this != &other)
	{
		for (int i = 0; i < this->rows; i++)
		{
			delete[] this->data[i];
		}
		delete[] this->data;

		rows = other.rows;
		cols = other.cols;
		data = new float *[rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new float[cols];
			for (int j = 0; j < cols; j++)
			{
				data[i][j] = other.data[i][j];
			}
		}
	}
	return *this;
}

// Sum of Mat and Mat.
Mat Mat::operator+(const Mat &other) const
{
	if (this->rows != other.rows || this->cols != other.cols)
	{
		throw "Mat + Mat: Matrices must have the same dimensions";
	}

	float **data = new float *[this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];

		for (int j = 0; j < this->cols; j++)
		{
			data[i][j] = this->data[i][j] + other.data[i][j];
		}
	}

	return Mat(data, this->rows, this->cols);
}

// Difference of Mat and Mat.
Mat Mat::operator-(const Mat &other) const
{
	if (this->rows != other.rows || this->cols != other.cols)
	{
		throw "Mat - Mat: Matrices must have the same dimensions";
	}

	float **data = new float *[this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];

		for (int j = 0; j < this->cols; j++)
		{
			data[i][j] = this->data[i][j] - other.data[i][j];
		}
	}

	return Mat(data, this->rows, this->cols);
}

// Element-wise product of Mat and Mat.
Mat Mat::operator*(const Mat &other) const
{
	if (this->rows != other.rows || this->cols != other.cols)
	{
		throw "Mat * Mat: Matrices must have the same dimensions";
	}

	float **data = new float *[this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];

		for (int j = 0; j < this->cols; j++)
		{
			data[i][j] = this->data[i][j] * other.data[i][j];
		}
	}

	return Mat(data, this->rows, this->cols);
}

// Sum of Mat and scalar.
Mat Mat::operator+(const float scalar) const
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

	return Mat(data, this->rows, this->cols);
}

// Difference of Mat and scalar.
Mat Mat::operator-(const float scalar) const
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

	return Mat(data, this->rows, this->cols);
}

// Product of Mat and scalar.
Mat Mat::operator*(const float scalar) const
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

	return Mat(data, this->rows, this->cols);
}

// Transpose of Mat.
Mat Mat::T() const
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

	return Mat(data, this->cols, this->rows);
}

// Returns a row of the Mat.
Mat Mat::getRow(const int row) const
{
	if (row < 0 || row >= this->rows)
	{
		throw "Mat getRow: Row index out of bounds";
	}

	float **data = new float *[1];
	data[0] = new float[this->cols];

	for (int i = 0; i < this->cols; i++)
	{
		data[0][i] = this->data[row][i];
	}

	return Mat(data, 1, this->cols);
}

// Returns a column of the Mat.
Mat Mat::getCol(const int col) const
{
	if (col < 0 || col >= this->cols)
	{
		throw "Mat getCol: Column index out of bounds";
	}

	float **data = new float *[this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[1];
		data[i][0] = this->data[i][col];
	}

	return Mat(data, this->rows, 1);
}
