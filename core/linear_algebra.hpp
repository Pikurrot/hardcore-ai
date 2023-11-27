#pragma once
#include "Mat.hpp"
#include <random>

Mat zeros(const int rows, const int cols);

float randomF();
Mat random(const int rows, const int cols);

Mat dot(const Mat &a, const Mat &b);

float sigmoid(const float x);
Mat sigmoid(const Mat &x);

Mat TruthTableInputs(const int rows, const int cols);
Mat TruthTableOutputs(const int *array, const int rows);
