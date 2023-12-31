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
			this->setValue(i, j, other.getValue(i, j));
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

// Returns the value of a Mat element.
float Mat::getValue(const int row, const int col) const
{
	if (row < 0 || row >= this->rows)
	{
		throw "Mat getValue: Row index out of bounds";
	}
	if (col < 0 || col >= this->cols)
	{
		throw "Mat getValue: Column index out of bounds";
	}

	return this->data[row][col];
}

// Sets the value of a Mat element.
void Mat::setValue(const int row, const int col, const float value)
{
	if (row < 0 || row >= this->rows)
	{
		throw "Mat setValue: Row index out of bounds";
	}
	if (col < 0 || col >= this->cols)
	{
		throw "Mat setValue: Column index out of bounds";
	}

	this->data[row][col] = value;
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
				this->setValue(i, j, other.getValue(i, j));
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
			data[i][j] = this->getValue(i, j) + other.getValue(i, j);
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
			data[i][j] = this->getValue(i, j) - other.getValue(i, j);
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
			data[i][j] = this->getValue(i, j) * other.getValue(i, j);
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
			data[i][j] = this->getValue(i, j) + scalar;
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
			data[i][j] = this->getValue(i, j) - scalar;
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
			data[i][j] = this->getValue(i, j) * scalar;
		}
	}

	return Mat(data, this->rows, this->cols);
}

// Less than of Mat and scalar.
Mat Mat::operator<(const float scalar) const
{
	float **data = new float *[this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];

		for (int j = 0; j < this->cols; j++)
		{
			if (this->getValue(i, j) < scalar)
			{
				data[i][j] = 1.0f;
			}
			else
			{
				data[i][j] = 0.0f;
			}
		}
	}

	return Mat(data, this->rows, this->cols);
}

// Greater than of Mat and scalar.
Mat Mat::operator>(const float scalar) const
{
	float **data = new float *[this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];

		for (int j = 0; j < this->cols; j++)
		{
			if (this->getValue(i, j) > scalar)
			{
				data[i][j] = 1.0f;
			}
			else
			{
				data[i][j] = 0.0f;
			}
		}
	}

	return Mat(data, this->rows, this->cols);
}

// Less than or equal to of Mat and scalar.
Mat Mat::operator<=(const float scalar) const
{
	float **data = new float *[this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];

		for (int j = 0; j < this->cols; j++)
		{
			if (this->getValue(i, j) <= scalar)
			{
				data[i][j] = 1.0f;
			}
			else
			{
				data[i][j] = 0.0f;
			}
		}
	}

	return Mat(data, this->rows, this->cols);
}

// Greater than or equal to of Mat and scalar.
Mat Mat::operator>=(const float scalar) const
{
	float **data = new float *[this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];

		for (int j = 0; j < this->cols; j++)
		{
			if (this->getValue(i, j) >= scalar)
			{
				data[i][j] = 1.0f;
			}
			else
			{
				data[i][j] = 0.0f;
			}
		}
	}

	return Mat(data, this->rows, this->cols);
}

// Equal to of Mat and scalar.
Mat Mat::operator==(const float scalar) const
{
	float **data = new float *[this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];
		for (int j = 0; j < this->cols; j++)
		{
			if (this->getValue(i, j) == scalar)
			{
				data[i][j] = 1.0f;
			}
			else
			{
				data[i][j] = 0.0f;
			}
		}
	}

	return Mat(data, this->rows, this->cols);
}

// Not equal to of Mat and scalar.
Mat Mat::operator!=(const float scalar) const
{
	float **data = new float *[this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];
		for (int j = 0; j < this->cols; j++)
		{
			if (this->getValue(i, j) != scalar)
			{
				data[i][j] = 1.0f;
			}
			else
			{
				data[i][j] = 0.0f;
			}
		}
	}

	return Mat(data, this->rows, this->cols);
}

// Less than of Mat and Mat.
Mat Mat::operator<(const Mat &other) const
{
	if (this->rows != other.rows || this->cols != other.cols)
	{
		throw "Mat < Mat: Matrices must have the same dimensions";
	}

	float **data = new float *[this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];
		for (int j = 0; j < this->cols; j++)
		{
			if (this->getValue(i, j) < other.getValue(i, j))
			{
				data[i][j] = 1.0f;
			}
			else
			{
				data[i][j] = 0.0f;
			}
		}
	}

	return Mat(data, this->rows, this->cols);
}

// Greater than of Mat and Mat.
Mat Mat::operator>(const Mat &other) const
{
	if (this->rows != other.rows || this->cols != other.cols)
	{
		throw "Mat > Mat: Matrices must have the same dimensions";
	}

	float **data = new float *[this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];
		for (int j = 0; j < this->cols; j++)
		{
			if (this->getValue(i, j) > other.getValue(i, j))
			{
				data[i][j] = 1.0f;
			}
			else
			{
				data[i][j] = 0.0f;
			}
		}
	}

	return Mat(data, this->rows, this->cols);
}

// Less than or equal to of Mat and Mat.
Mat Mat::operator<=(const Mat &other) const
{
	if (this->rows != other.rows || this->cols != other.cols)
	{
		throw "Mat <= Mat: Matrices must have the same dimensions";
	}

	float **data = new float *[this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];
		for (int j = 0; j < this->cols; j++)
		{
			if (this->getValue(i, j) <= other.getValue(i, j))
			{
				data[i][j] = 1.0f;
			}
			else
			{
				data[i][j] = 0.0f;
			}
		}
	}

	return Mat(data, this->rows, this->cols);
}

// Greater than or equal to of Mat and Mat.
Mat Mat::operator>=(const Mat &other) const
{
	if (this->rows != other.rows || this->cols != other.cols)
	{
		throw "Mat >= Mat: Matrices must have the same dimensions";
	}

	float **data = new float *[this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];
		for (int j = 0; j < this->cols; j++)
		{
			if (this->getValue(i, j) >= other.getValue(i, j))
			{
				data[i][j] = 1.0f;
			}
			else
			{
				data[i][j] = 0.0f;
			}
		}
	}

	return Mat(data, this->rows, this->cols);
}

// Equal to of Mat and Mat.
Mat Mat::operator==(const Mat &other) const
{
	if (this->rows != other.rows || this->cols != other.cols)
	{
		throw "Mat == Mat: Matrices must have the same dimensions";
	}

	float **data = new float *[this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];
		for (int j = 0; j < this->cols; j++)
		{
			if (this->getValue(i, j) == other.getValue(i, j))
			{
				data[i][j] = 1.0f;
			}
			else
			{
				data[i][j] = 0.0f;
			}
		}
	}

	return Mat(data, this->rows, this->cols);
}

// Not equal to of Mat and Mat.
Mat Mat::operator!=(const Mat &other) const
{
	if (this->rows != other.rows || this->cols != other.cols)
	{
		throw "Mat != Mat: Matrices must have the same dimensions";
	}

	float **data = new float *[this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		data[i] = new float[this->cols];
		for (int j = 0; j < this->cols; j++)
		{
			if (this->getValue(i, j) != other.getValue(i, j))
			{
				data[i][j] = 1.0f;
			}
			else
			{
				data[i][j] = 0.0f;
			}
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
			data[i][j] = this->getValue(j, i);
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
		data[0][i] = this->getValue(row, i);
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
		data[i][0] = this->getValue(i, col);
	}

	return Mat(data, this->rows, 1);
}

// Returns a slice [start, end) of the Mat.
Mat Mat::slice(const int start, const int end) const
{
	if (start < 0 || start >= this->rows)
	{
		throw "Mat slice: Start index out of bounds";
	}
	if (end <= 0 || end > this->rows)
	{
		throw "Mat slice: End index out of bounds";
	}
	if (start >= end)
	{
		throw "Mat slice: Start index must be less than end index";
	}

	float **data = new float *[end - start];

	for (int i = 0; i < end - start; i++)
	{
		data[i] = new float[this->cols];

		for (int j = 0; j < this->cols; j++)
		{
			data[i][j] = this->getValue(i + start, j);
		}
	}

	return Mat(data, end - start, this->cols);
}