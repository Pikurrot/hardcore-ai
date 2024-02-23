#pragma once
#include <cmath>

int isClose(double a, double b, double atol = 1e-5, double rtol = 1e-5)
{
	return std::abs(a - b) <= (atol + rtol * std::abs(b));
}

void assert(bool condition, const char* message)
{
	if (!condition) throw message;
}
