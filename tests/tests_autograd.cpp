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
		ValuePtr d, e, f, g, h, i, j;
		double trueValue = 3.459437131881714;

		d = a * b;
		e = d - c;
		f = e->exp();
		g = f->pow(2);
		h = -g / 2;
		i = 1 - d - h * -1 + 1 / e;
		j = (-i)->log();

		assert(isClose(j->data(), trueValue), "output is not correct");
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
		ValuePtr d, e, f, g, h, i, j;

		d = a * b;
		e = d - c;
		f = e->exp();
		g = f->pow(2);
		h = -g / 2;
		i = 1 - d - h * -1 + 1 / e;
		j = (-i)->log();

		j->backward();
		
		assert(isClose(j->grad(), 1.0), "j.grad is not correct");
		assert(isClose(i->grad(), -0.031447455286979675), "i.grad is not correct");
		assert(isClose(h->grad(), -0.031447455286979675), "h.grad is not correct");
		assert(isClose(g->grad(), 0.015723727643489838), "g.grad is not correct");
		assert(isClose(f->grad(), 0.23236700892448425), "f.grad is not correct");
		assert(isClose(e->grad(), 1.7248347997665405), "e.grad is not correct");
		assert(isClose(d->grad(), 1.7562822103500366), "d.grad is not correct");
		assert(isClose(c->grad(), -1.7248347997665405), "c.grad is not correct");
		assert(isClose(b->grad(), 3.5125644207000732), "b.grad is not correct");
		assert(isClose(a->grad(), 5.26884651184082), "a.grad is not correct");
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
