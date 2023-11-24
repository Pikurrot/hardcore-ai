#pragma once

using namespace std;

class Mat
{
private:
	float **data;
	int rows, cols;

public:
	Mat(float **data, int rows, int cols);
	~Mat();

	// getters
	float **getData() { return this->data; }
	int getRows() { return this->rows; }
	int getCols() { return this->cols; }

	// Mat operators
	Mat *operator+(Mat *other);	// sum
	Mat *operator-(Mat *other);	// difference
	Mat *operator*(Mat *other);	// element-wise product

	// Scalar operators
	Mat *operator+(float scalar); // sum
	Mat *operator-(float scalar); // difference
	Mat *operator*(float scalar); // product

	// Transpose
	Mat *T();
};
