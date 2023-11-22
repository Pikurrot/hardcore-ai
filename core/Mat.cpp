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
