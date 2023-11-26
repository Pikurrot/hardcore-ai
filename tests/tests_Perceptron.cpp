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
	}
	catch (const char *e)
	{
		std::string msg = "Perceptron constructor failed: ";
		msg += e;
		delete p;
		p = nullptr;
		throw msg.c_str();
	}
	delete p;
	p = nullptr;
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
	}
	catch (const char *e)
	{
		std::string msg = "Perceptron forward failed: ";
		msg += e;
		delete p;
		p = nullptr;
		delete inputs;
		inputs = nullptr;
		throw msg;
	}
	delete p;
	p = nullptr;
	delete inputs;
	inputs = nullptr;
}
