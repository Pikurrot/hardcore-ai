#pragma once

#include "../core/Mat.hpp"
# include <vector>

class Perceptron
{
private:
	Mat w;
	float b;
	float alpha; // learning rate
	std::vector<float> costs;

public:
	Perceptron(const int n, const float alpha = 0.01);
	~Perceptron();

	void updateCosts(const float cost) { this->costs.push_back(cost); }
	std::vector<float> getCosts() const { return this->costs; }

	float forward(const Mat &x) const;	// forward propagation
	float backward(const Mat &x, const float yPred, const float yTrue); // backpropagation
	void train(const Mat &x, const Mat &yTrue, const int epochs = 100); // train using backpropagation
};
