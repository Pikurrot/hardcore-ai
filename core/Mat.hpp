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
};
