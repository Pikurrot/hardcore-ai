#include "../core/Mat.hpp"
#include <iostream>

void testMatConstructor()
{
	float **data = new float *[2];
	data[0] = new float[2]{1.0f, 2.0f};
	data[1] = new float[2]{3.0f, 4.0f};

	Mat mat(data, 2, 2);

	if (mat.getData()[0][0] != 1.0f || mat.getData()[0][1] != 2.0f || mat.getData()[1][0] != 3.0f || mat.getData()[1][1] != 4.0f)
	{
		throw "testMatConstructor failed: result has incorrect values";
	}

	Mat mat2;
}

void testMatAddition()
{
	float **data1 = new float *[2];
	data1[0] = new float[2]{1.0f, 2.0f};
	data1[1] = new float[2]{3.0f, 4.0f};

	float **data2 = new float *[2];
	data2[0] = new float[2]{5.0f, 6.0f};
	data2[1] = new float[2]{7.0f, 8.0f};

	Mat mat1(data1, 2, 2);
	Mat mat2(data2, 2, 2);

	try
	{
		Mat result = mat1 + mat2;

		if (result.getValue(0, 0) != 6.0f || result.getValue(0, 1) != 8.0f || result.getValue(1, 0) != 10.0f || result.getValue(1, 1) != 12.0f)
		{
			throw "result has incorrect values";
		}
	}
	catch (const char *e)
	{
		throw "testMatAddition failed: " + std::string(e);
	}
}

void testMatSubtraction()
{
	float **data1 = new float *[2];
	data1[0] = new float[2]{1.0f, 2.0f};
	data1[1] = new float[2]{3.0f, 4.0f};

	float **data2 = new float *[2];
	data2[0] = new float[2]{5.0f, 6.0f};
	data2[1] = new float[2]{7.0f, 8.0f};

	Mat mat1(data1, 2, 2);
	Mat mat2(data2, 2, 2);

	try
	{
		Mat result = mat1 - mat2;

		if (result.getValue(0, 0) != -4.0f || result.getValue(0, 1) != -4.0f || result.getValue(1, 0) != -4.0f || result.getValue(1, 1) != -4.0f)
		{
			throw "result has incorrect values";
		}
	}
	catch (const char *e)
	{
		throw "testMatSubtraction failed: " + std::string(e);
	}
}

void testMatElementWiseProduct()
{
	float **data1 = new float *[2];
	data1[0] = new float[2]{1.0f, 2.0f};
	data1[1] = new float[2]{3.0f, 4.0f};

	float **data2 = new float *[2];
	data2[0] = new float[2]{5.0f, 6.0f};
	data2[1] = new float[2]{7.0f, 8.0f};

	Mat mat1(data1, 2, 2);
	Mat mat2(data2, 2, 2);

	try
	{
		Mat result = mat1 * mat2;

		if (result.getValue(0, 0) != 5.0f || result.getValue(0, 1) != 12.0f || result.getValue(1, 0) != 21.0f || result.getValue(1, 1) != 32.0f)
		{
			throw "result has incorrect values";
		}
	}
	catch (const char *e)
	{
		throw "testMatElementWiseProduct failed: " + std::string(e);
	}
}

void testMatScalarAddition()
{
	float **data = new float *[2];
	data[0] = new float[2]{1.0f, 2.0f};
	data[1] = new float[2]{3.0f, 4.0f};

	Mat mat(data, 2, 2);

	try
	{
		Mat result = mat + 1.0f;

		if (result.getValue(0, 0) != 2.0f || result.getValue(0, 1) != 3.0f || result.getValue(1, 0) != 4.0f || result.getValue(1, 1) != 5.0f)
		{
			throw "result has incorrect values";
		}
	}
	catch (const char *e)
	{
		throw "testMatScalarAddition failed: " + std::string(e);
	}
}

void testMatScalarSubtraction()
{
	float **data = new float *[2];
	data[0] = new float[2]{1.0f, 2.0f};
	data[1] = new float[2]{3.0f, 4.0f};

	Mat mat(data, 2, 2);

	try
	{
		Mat result = mat - 1.0f;

		if (result.getValue(0, 0) != 0.0f || result.getValue(0, 1) != 1.0f || result.getValue(1, 0) != 2.0f || result.getValue(1, 1) != 3.0f)
		{
			throw "result has incorrect values";
		}
	}
	catch (const char *e)
	{
		throw "testMatScalarSubtraction failed: " + std::string(e);
	}
}

void testMatScalarProduct()
{
	float **data = new float *[2];
	data[0] = new float[2]{1.0f, 2.0f};
	data[1] = new float[2]{3.0f, 4.0f};

	Mat mat(data, 2, 2);

	try
	{
		Mat result = mat * 2.0f;

		if (result.getValue(0, 0) != 2.0f || result.getValue(0, 1) != 4.0f || result.getValue(1, 0) != 6.0f || result.getValue(1, 1) != 8.0f)
		{
			throw "result has incorrect values";
		}
	}
	catch (const char *e)
	{
		throw "testMatScalarProduct failed: " + std::string(e);
	}
}

void testMatT()
{
	float **data = new float *[2];
	data[0] = new float[2]{1.0f, 2.0f};
	data[1] = new float[2]{3.0f, 4.0f};

	Mat mat(data, 2, 2);

	try
	{
		Mat result = mat.T();

		if (result.getValue(0, 0) != 1.0f || result.getValue(0, 1) != 3.0f || result.getValue(1, 0) != 2.0f || result.getValue(1, 1) != 4.0f)
		{
			throw "result has incorrect values";
		}
	}
	catch (const char *e)
	{
		throw "testMatT failed: " + std::string(e);
	}
}

void testMatGetRow()
{
	float **data = new float *[2];
	data[0] = new float[2]{1.0f, 2.0f};
	data[1] = new float[2]{3.0f, 4.0f};

	Mat mat(data, 2, 2);

	try
	{
		Mat result = mat.getRow(0);

		if (result.getValue(0, 0) != 1.0f || result.getValue(0, 1) != 2.0f)
		{
			throw "result has incorrect values";
		}
	}
	catch (const char *e)
	{
		throw "testMatGetRow failed: " + std::string(e);
	}
}

void testMatGetCol()
{
	float **data = new float *[2];
	data[0] = new float[2]{1.0f, 2.0f};
	data[1] = new float[2]{3.0f, 4.0f};

	Mat mat(data, 2, 2);

	try
	{
		Mat result = mat.getCol(0);

		if (result.getValue(0, 0) != 1.0f || result.getValue(1, 0) != 3.0f)
		{
			throw "result has incorrect values";
		}
	}
	catch (const char *e)
	{
		throw "testMatGetCol failed: " + std::string(e);
	}
}
