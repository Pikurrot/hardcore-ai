#pragma once

class Mat
{
private:
	float **data;
	int rows, cols;

public:
	Mat(float **data, int rows, int cols);
	~Mat();

	float **getData() { return this->data; }
	int getRows() { return this->rows; }
	int getCols() { return this->cols; }

	Mat *operator+(Mat *other);	// sum
	Mat *operator-(Mat *other);	// difference
	Mat *operator*(Mat *other);	// element-wise product

	Mat *operator+(float scalar); // scalar sum
	Mat *operator-(float scalar); // scalar difference
	Mat *operator*(float scalar); // scalar product

	Mat *T(); // transpose
};
