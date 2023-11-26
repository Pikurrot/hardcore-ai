#include "tests_Perceptron.hpp"
#include "../deep_learning/Perceptron.hpp"
#include "../core/linear_algebra.hpp"
#include "../core/Mat.hpp"
#include <string>

void testPerceptronConstructor()
{
	Perceptron *p = nullptr;
	try
	{
		p = new Perceptron(2);
		delete p;
	}
	catch (const char *e)
	{
		delete p;
		throw "testPerceptronConstructor failed: " + std::string(e);
	}
}

void testPerceptronForward()
{
	Perceptron *p = nullptr;
	Mat *inputs = nullptr;
	try
	{
		p = new Perceptron(4);
		inputs = random(1, 4);
		float output = p->forward(inputs);
		if (output < 0 || output > 1)
		{
			throw "Perceptron output out of range";
		}
		delete p;
		delete inputs;
	}
	catch (const char *e)
	{
		delete p;
		delete inputs;
		throw "Perceptron forward failed: " + std::string(e);
	}
	catch (std::string e)
	{
		delete p;
		delete inputs;
		throw "Perceptron forward failed: " + e;
	}
}
