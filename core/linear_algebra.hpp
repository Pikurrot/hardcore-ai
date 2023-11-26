#pragma once
#include "Mat.hpp"
#include <random>

using namespace std;

Mat *zeros(int rows, int cols);

float randomF();
Mat *random(int rows, int cols);

Mat *dot(Mat *a, Mat *b);

float sigmoid(float x);
Mat *sigmoid(Mat *x);

Mat *TruthTableInputs(int rows, int cols);
Mat *TruthTableOutputs(int *array, int rows);
