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
		throw "testPerceptronForward failed: " + std::string(e);
	}
	catch (std::string e)
	{
		throw "testPerceptronForward failed: " + e;
	}
}

void testPerceptronBackward()
{
	try
	{
		Perceptron p(4);
		Mat inputs = random(1, 4);
		float yTrue = 1;
		float yPred1 = p.forward(inputs);
		float cost1 = p.backward(inputs, yPred1, yTrue);
		float yPred2 = p.forward(inputs);
		float cost2 = p.backward(inputs, yPred2, yTrue);
		if (cost1 < 0 || cost2 < 0)
		{
			throw "Perceptron cost is negative";
		}
		else if (cost1 <= cost2)
		{
			throw "Perceptron cost did not decrease";
		}
		else if (yTrue - yPred1 <= yTrue - yPred2)
		{
			throw "Perceptron prediction did not improve";
		}
	}
	catch (const char *e)
	{
		throw "testPerceptronBackward failed: " + std::string(e);
	}
	catch (std::string e)
	{
		throw "testPerceptronBackward failed: " + e;
	}
}
