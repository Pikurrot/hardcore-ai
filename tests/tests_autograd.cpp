#include "core/autograd/Value.hpp"
#include "tests/tests_autograd.hpp"
#include "tests/tests_misc.hpp"
#include <iostream>
#include <string>
#include <cmath>

void runTestsAutograd()
{
	testOperators();
	testBackward();
}

void testOperators()
{
	try
	{
		ValuePtr a = value(2.0);
		ValuePtr b = value(3.0);
		ValuePtr c = value(4.0);
		ValuePtr d, e, f, g, h, i;
		double trueValue = -31.799076080322266;

		d = a * b;
		e = d - c;
		f = e->exp();
		g = f->pow(2);
		h = -g / 2;
		i = 1 - d - h * -1 + 1 / e;

		assert(isClose(i->data(), trueValue), "output is not correct");
	}
	catch (const char *e)
	{
		throw "testOperators failed: " + std::string(e);
	}
	catch (std::string e)
	{
		throw "testOperators failed: " + e;
	}
}

void testBackward()
{
	try
	{
		ValuePtr a = value(2.0);
		ValuePtr b = value(3.0);
		ValuePtr c = value(4.0);
		ValuePtr d, e, f, g, h, i;

		d = a * b;
		e = d - c;
		f = e->exp();
		g = f->pow(2);
		h = -g / 2;
		i = 1 - d - h * -1 + 1 / e;

		i->backward();
		
		assert(isClose(i->grad(), 1), "i.grad is not correct");
		assert(isClose(h->grad(), 1), "h.grad is not correct");
		assert(isClose(g->grad(), -0.5), "g.grad is not correct");
		assert(isClose(f->grad(), -7.3891), "f.grad is not correct");
		assert(isClose(e->grad(), -54.8482), "e.grad is not correct");
		assert(isClose(d->grad(), -55.8482), "d.grad is not correct");
		assert(isClose(c->grad(), 54.8482), "c.grad is not correct");
		assert(isClose(b->grad(), -111.6963), "b.grad is not correct");
		assert(isClose(a->grad(), -167.5445), "a.grad is not correct");
	}
	catch (const char *e)
	{
		throw "testBackward failed: " + std::string(e);
	}
	catch (std::string e)
	{
		throw "testBackward failed: " + e;
	}
}
