#pragma once

#include "../core/Mat.hpp"

class Perceptron
{
private:
	Mat *weights;
	float bias;

public:
	Perceptron(int nInputs);
	~Perceptron();
};
