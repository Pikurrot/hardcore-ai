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
		ValuePtr d, e, f, g, h, i, j, k, l, m, n;
		double trueValue = 0.748489499092102;

		d = a * b;
		e = d - c;
		f = e->exp();
		g = f->pow(2);
		h = -g / 2;
		i = 1 - d - h * -1 + 1 / e;
		j = (-i)->log();
		k = sigmoid(j);
		l = tanh(k);
		m = relu(l);
		n = leakyRelu(m);

		assert(isClose(n->data(), trueValue), "output is not correct");
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
		ValuePtr a = value(2.0, 1);
		ValuePtr b = value(3.0, 1);
		ValuePtr c = value(4.0, 1);
		ValuePtr d, e, f, g, h, i, j, k, l, m, n;

		d = a * b;
		e = d - c;
		f = e->exp();
		g = f->pow(2);
		h = -g / 2;
		i = 1 - d - h * -1 + 1 / e;
		j = (-i)->log();
		k = sigmoid(j);
		l = tanh(k);
		m = relu(l);
		n = leakyRelu(m);

		n->backward();
		
		assert(isClose(n->grad(), 1.0), "n.grad is not correct");
		assert(isClose(m->grad(), 1.0), "m.grad is not correct");
		assert(isClose(l->grad(), 1.0), "l.grad is not correct");
		assert(isClose(k->grad(), 0.43976345658302307), "k.grad is not correct");
		assert(isClose(j->grad(), 0.012998992577195168), "j.grad is not correct");
		assert(isClose(i->grad(), -0.0004087852139491588), "i.grad is not correct");
		assert(isClose(h->grad(), -0.0004087852139491588), "h.grad is not correct");
		assert(isClose(g->grad(), 0.0002043926069745794), "g.grad is not correct");
		assert(isClose(f->grad(), 0.0030205368530005217), "f.grad is not correct");
		assert(isClose(e->grad(), 0.022421112284064293), "e.grad is not correct");
		assert(isClose(d->grad(), 0.022829897701740265), "d.grad is not correct");
		assert(isClose(c->grad(), -0.022421112284064293), "c.grad is not correct");
		assert(isClose(b->grad(), 0.04565979540348053), "b.grad is not correct");
		assert(isClose(a->grad(), 0.0684896931052208), "a.grad is not correct");
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
