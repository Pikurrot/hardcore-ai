#pragma once

class Mat
{
private:
	float **data;
	int rows, cols;

public:
	Mat();
	Mat(float **data, const int rows, const int cols);
	Mat(const Mat &other);
	~Mat();

	float **getData() const { return this->data; }
	int getRows() const { return this->rows; }
	int getCols() const { return this->cols; }

	Mat &operator=(const Mat &other); // assignment

	Mat operator+(const Mat &other) const;	// sum
	Mat operator-(const Mat &other) const;	// difference
	Mat operator*(const Mat &other) const;	// element-wise product

	Mat operator+(const float scalar) const; // scalar sum
	Mat operator-(const float scalar) const; // scalar difference
	Mat operator*(const float scalar) const; // scalar product

	Mat T() const; // transpose

	Mat getRow(const int row) const;
	Mat getCol(const int col) const;
};
