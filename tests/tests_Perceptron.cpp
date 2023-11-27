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

void testPerceptronTrain()
{
	try
	{
		Perceptron p(2, 1);
		Mat inputs = truthTableInputs(4, 2);
		Mat yTrue = truthTableOutputs(new int[4]{0, 0, 0, 1}, 4);
		p.train(inputs, yTrue, 10000);
		Mat yPred = zeros(4, 1);
		for (int i = 0; i < inputs.getRows(); i++)
		{
			yPred.setValue(i, 0, p.forward(inputs.getRow(i)));
		}

		std::cout << "Perceptron costs:" << std::endl;
		float prevCost = p.getCosts()[0];
		std::cout << prevCost;
		for (long unsigned int i = 1; i < p.getCosts().size(); i+=1000)
		{
			float cost = p.getCosts()[i];
			char diff = cost < prevCost ? '-' : '+';
			prevCost = cost;
			std::cout << diff << " " << cost << " ";
		}
		std::cout << std::endl;

		std::cout << "Perceptron outputs:" << std::endl;
		for (int i = 0; i < inputs.getRows(); i++)
		{
			std::cout << yPred.getValue(i, 0) << " ";
		}
		std::cout << std::endl;

		std::cout << "True outputs:" << std::endl;
		for (int i = 0; i < yTrue.getRows(); i++)
		{
			std::cout << yTrue.getValue(i, 0) << " ";
		}
		std::cout << std::endl;

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
