#include "tests_Perceptron.hpp"
#include "../deep_learning/Perceptron.hpp"
#include "../core/linear_algebra.hpp"
#include "../core/Mat.hpp"

void testPerceptronConstructor()
{
	Perceptron *p = new Perceptron(2);
	delete p;
	p = nullptr;
}

void testPerceptronForward()
{
	Perceptron *p = new Perceptron(2);
	Mat *inputs = random(1, 4);
	float output = p->forward(inputs);
	delete p;
	p = nullptr;
	delete inputs;
	inputs = nullptr;
}
