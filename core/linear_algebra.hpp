#pragma once
#include "Mat.hpp"
#include <random>

using namespace std;

// Return a matrix of zeros
Mat *zeros(int rows, int cols);

// Return a random value between 0 and 1
float random();
Mat *random(int rows, int cols);

// Dot product
Mat *dot(Mat *a, Mat *b);

// Sigmoid
float sigmoid(float x);
Mat *sigmoid(Mat *x);
