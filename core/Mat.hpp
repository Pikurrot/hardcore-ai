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

	Mat *operator+(Mat *other);	// sum
};
