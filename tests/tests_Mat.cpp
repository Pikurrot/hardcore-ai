#include "../core/Mat.hpp"
#include <iostream>

void testMatConstructor()
{
	// Create a 2x2 matrix
	float **data = new float *[2];
	data[0] = new float[2]{1.0f, 2.0f};
	data[1] = new float[2]{3.0f, 4.0f};

	// Create a Mat object
	Mat mat(data, 2, 2);

	// Check the values of the Mat object
	if (mat.getData()[0][0] != 1.0f || mat.getData()[0][1] != 2.0f || mat.getData()[1][0] != 3.0f || mat.getData()[1][1] != 4.0f)
	{
		throw "testMatConstructor failed";
	}
}

void testMatAddition()
{
	// Create two 2x2 matrices
	float **data1 = new float *[2];
	data1[0] = new float[2]{1.0f, 2.0f};
	data1[1] = new float[2]{3.0f, 4.0f};

	float **data2 = new float *[2];
	data2[0] = new float[2]{5.0f, 6.0f};
	data2[1] = new float[2]{7.0f, 8.0f};

	// Create Mat objects
	Mat *mat1 = new Mat(data1, 2, 2);
	Mat *mat2 = new Mat(data2, 2, 2);

	// Add the matrices
	Mat *result = *mat1 + mat2;

	// Check the result
	if (result->getData()[0][0] != 6.0f || result->getData()[0][1] != 8.0f || result->getData()[1][0] != 10.0f || result->getData()[1][1] != 12.0f)
	{
		throw "testMatAddition failed";
	}

	delete mat1;
	delete mat2;
	delete result;
}
