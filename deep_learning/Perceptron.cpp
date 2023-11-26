#include "Perceptron.hpp"
#include "../core/linear_algebra.hpp"
#include "../core/Mat.hpp"
#include <vector>

// Creates a Perceptron with random weights and bias.
Perceptron::Perceptron(int n, float alpha)
{
	this->w = random(1, n);
	this->b = randomF();
	this->alpha = alpha;
}

// Releases the Perceptron's weights.
Perceptron::~Perceptron()
{
	delete this->w;
}

// Forward propagation: sigmoid(x*w + b).
float Perceptron::forward(Mat *x)
{
	Mat *weighted;
	float weightedSum;

	try
	{
		weighted = dot(this->w, x->T());
		weightedSum = weighted->getData()[0][0] + this->b;
		delete weighted;
		return sigmoid(weightedSum);
	}
	catch (const char *e)
	{
		delete weighted;
		throw "Perceptron forward: " + std::string(e);
	}
	catch (std::string e)
	{
		delete weighted;
		throw "Perceptron forward: " + e;
	}
}

// Backpropagation: adjusts the weights and bias. Returns the cost.
float Perceptron::backward(Mat *x, float yTrue)
{
	float yPred = this->forward(x);

	// Compute derivatives
	float dcost_dypred = -(yTrue - yPred);
	float dypred_dweightedSum = yPred * (1 - yPred);
	Mat *dweightedSum_dw = x->T();
	float dweightedSum_db = 1;

	// Compute gradients
	Mat *dcost_dw = *dweightedSum_dw * (dcost_dypred * dypred_dweightedSum);
	float dcost_db = dcost_dypred * dypred_dweightedSum * dweightedSum_db;

	// Adjust weights and bias
	this->w = *this->w - (*dcost_dw * this->alpha);
	this->b = this->b - (dcost_db * this->alpha);

	delete dcost_dw;
	dcost_dw = nullptr;

	// Return cost (before adjustment)
	float cost = 0.5 * (yTrue - yPred) * (yTrue - yPred);
	return cost;
}