#pragma once

#include "../core/Mat.hpp"
# include <vector>

class Perceptron
{
private:
	Mat *w;
	float b;
	float alpha; // learning rate
	vector<float> costs;

public:
	Perceptron(int n, float alpha = 0.01);
	~Perceptron();

	void updateCosts(float cost) { this->costs.push_back(cost); }

	float forward(Mat *x); // forward propagation
	float backward(Mat *x, float y_true); // backpropagation
};
