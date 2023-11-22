#pragma once
#include "Mat.hpp"
#include <random>

using namespace std;

// Return a matrix of zeros
Mat *zeros(int rows, int cols);

// Return a matrix of random values between 0 and 1
Mat *random(int rows, int cols);

// Dot product
Mat *dot(Mat *a, Mat *b);
