#include "Perceptron.hpp"
#include "../core/linear_algebra.hpp"
#include "../core/Mat.hpp"

// Creates a Perceptron with random weights and bias.
Perceptron::Perceptron(int nInputs)
{
	this->weights = random(1, nInputs);
	this->bias = randomF();
}

// Releases the Perceptron's weights.
Perceptron::~Perceptron()
{
	delete this->weights;
	this->weights = nullptr;
}

// Forward propagation: sigmoid(inputs * weights + bias).
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
