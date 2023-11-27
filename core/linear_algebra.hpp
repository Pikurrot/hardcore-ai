#pragma once
#include "Mat.hpp"
#include <random>

Mat zeros(const int rows, const int cols);

float randomF();
Mat random(const int rows, const int cols);

Mat dot(const Mat &a, const Mat &b);

float sigmoid(const float x);
Mat sigmoid(const Mat &x);

Mat truthTableInputs(const int rows, const int cols);
Mat truthTableOutputs(const int *array, const int rows);

Mat operator+(const float a, const Mat &b);
Mat operator-(const float a, const Mat &b);
Mat operator*(const float a, const Mat &b);
Mat operator/(const float a, const Mat &b);
