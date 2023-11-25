#include "Perceptron.hpp"
#include "../core/linear_algebra.hpp"
#include "../core/Mat.hpp"

Perceptron::Perceptron(int nInputs)
{
	this->weights = random(1, nInputs);
	this->bias = randomF();
}

Perceptron::~Perceptron()
{
	delete this->weights;
	this->weights = nullptr;
}

// Forward propagation
float Perceptron::forward(Mat *inputs)
{
	Mat *weighted;
	float weightedSum;

	weighted = dot(this->weights, inputs->T());
	weightedSum = weighted->getData()[0][0] + this->bias;
	delete weighted;
	weighted = nullptr;
	return sigmoid(weightedSum);
}
