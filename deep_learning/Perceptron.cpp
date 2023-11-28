#include "Perceptron.hpp"
#include "../core/linear_algebra.hpp"
#include "../core/Mat.hpp"
#include <vector>
#include <iostream>

// Creates a Perceptron with random weights and bias.
Perceptron::Perceptron(int n, float alpha)
{
	this->w = random(1, n);
	this->b = random(1, 1);
	this->alpha = alpha;
}

// Releases the Perceptron's weights.
Perceptron::~Perceptron()
{
}

// Forward propagation: sigmoid(x*w + b).
Mat Perceptron::forward(const Mat &x) const
{
	try
	{
		return sigmoid(dot(x, this->w.T()) + this->b.getValue(0, 0));
	}
	catch (const char *e)
	{
		throw "Perceptron forward: " + std::string(e);
	}
	catch (std::string e)
	{
		throw "Perceptron forward: " + e;
	}
}

// Backpropagation: adjusts the weights and bias. Returns the cost.
float Perceptron::backward(const Mat &x, const Mat &yPred, const Mat &yTrue)
{
	try
	{
		Mat error = yTrue - yPred;
		// Compute derivatives
		Mat dcost_dypred = error * -1;
		Mat dypred_dweightedSum = yPred * (1 - yPred);
		Mat dweightedSum_dw = x;
		float dweightedSum_db = 1;

		// Compute gradients
		Mat dcost_dw = dot((dcost_dypred * dypred_dweightedSum).T(), dweightedSum_dw);
		Mat dcost_db = dot(dcost_dypred.T(), dypred_dweightedSum) * dweightedSum_db;

		// Adjust weights and bias
		this->w = this->w - (dcost_dw * this->alpha);
		this->b = this->b - (dcost_db * this->alpha);

		// Return cost (before adjustment)
		int n = yTrue.getRows();
		float cost = 1. / (2. * n) * dot(error.T(), error).getValue(0, 0); // MSE
		return cost;
	}
	catch (const char *e)
	{
		throw "Perceptron backward: " + std::string(e);
	}
	catch (std::string e)
	{
		throw "Perceptron backward: " + e;
	}
}

// Trains the Perceptron on the given data.
void Perceptron::train(const Mat &x, const Mat &yTrue, const int epochs, const int batchSize)
{
	try
	{
		int _batchSize = std::min(batchSize, x.getRows());
		for (int epoch = 0; epoch < epochs; epoch++)
		{
			for (int i = 0; i < x.getRows(); i += _batchSize)
			{
				Mat xBatch = x.slice(i, i + _batchSize);
				Mat yTrueBatch = yTrue.slice(i, i + _batchSize);
				Mat yPredBatch = this->forward(xBatch);
				float cost = this->backward(xBatch, yPredBatch, yTrueBatch);
				this->updateCosts(cost);
			}
		}
	}
	catch (const char *e)
	{
		throw "Perceptron train: " + std::string(e);
	}
	catch (std::string e)
	{
		throw "Perceptron train: " + e;
	}
}
