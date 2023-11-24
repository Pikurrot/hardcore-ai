#include "Perceptron.hpp"
#include "../core/linear_algebra.hpp"
#include "../core/Mat.hpp"

Perceptron::Perceptron(int nInputs)
{
	this->weights = random(1, nInputs);
	this->bias = random();
}

Perceptron::~Perceptron()
{
	delete this->weights;
	this->weights = nullptr;
}
