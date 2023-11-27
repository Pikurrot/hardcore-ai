#include "tests_Perceptron.hpp"
#include "../deep_learning/Perceptron.hpp"
#include "../core/linear_algebra.hpp"
#include "../core/Mat.hpp"
#include <string>
#include <iostream>

void testPerceptronConstructor()
{
	Perceptron p(2);
}

void testPerceptronForward()
{
	try
	{
		Perceptron p(4);
		Mat inputs = random(1, 4);
		float output = p.forward(inputs);
		if (output < 0 || output > 1)
		{
			throw "Perceptron output out of range";
		}
	}
	catch (const char *e)
	{
		throw "Perceptron forward failed: " + std::string(e);
	}
	catch (std::string e)
	{
		throw "Perceptron forward failed: " + e;
	}
}
