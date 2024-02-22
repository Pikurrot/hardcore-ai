#include "tests_Perceptron.hpp"
#include "../deep_learning/Perceptron.hpp"
#include "../core/linear_algebra.hpp"
#include "../core/Mat.hpp"
#include <string>
#include <iostream>
#include <cmath>

void testPerceptronConstructor()
{
	Perceptron p(2);
}

void testPerceptronForward()
{
	try
	{
		Perceptron p(4);
		Mat x = random(1, 4);
		Mat yPred = p.forward(x);
		if (any(yPred < 0) || any(yPred > 1))
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
		Mat inputs = zeros(1, 4) + 1;
		Mat yTrue = zeros(1, 1) + 1;
		Mat yPred1 = p.forward(inputs);
		float cost1 = p.backward(inputs, yPred1, yTrue);
		Mat yPred2 = p.forward(inputs);
		float cost2 = p.backward(inputs, yPred2, yTrue);
		if (cost1 < 0 || cost2 < 0)
		{
			throw "Perceptron cost is negative";
		}
		else if (cost1 <= cost2)
		{
			throw "Perceptron cost did not decrease";
		}
		else if (any(yTrue - yPred1 <= yTrue - yPred2))
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

void testPerceptronTrain()
{
	try
	{
		Perceptron p(2, 1);
		Mat inputs = truthTableInputs(4, 2);
		Mat yTrue = truthTableOutputs(new int[4]{0, 0, 0, 1}, 4);
		p.train(inputs, yTrue, 10000, 2);
		Mat yPred = p.forward(inputs);

		float epsilon = 0.05;
		if (std::abs(yPred.getValue(0, 0) - yTrue.getValue(0, 0)) > epsilon ||
			std::abs(yPred.getValue(1, 0) - yTrue.getValue(1, 0)) > epsilon ||
			std::abs(yPred.getValue(2, 0) - yTrue.getValue(2, 0)) > epsilon ||
			std::abs(yPred.getValue(3, 0) - yTrue.getValue(3, 0)) > epsilon)
		{
			throw "Perceptron did not learn the AND function";
		}
	}
	catch (const char *e)
	{
		throw "testPerceptronTrain failed: " + std::string(e);
	}
	catch (std::string e)
	{
		throw "testPerceptronTrain failed: " + e;
	}
}

void runTestsPerceptron()
{
	testPerceptronConstructor();
	testPerceptronForward();
	testPerceptronBackward();
	testPerceptronTrain();
}
