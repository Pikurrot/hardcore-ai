#include "core/autograd/Value.hpp"
#include <functional>
#include <vector>
#include <cmath>

using std::shared_ptr;
using std::make_shared;
using ValuePtr = shared_ptr<Value>;

ValuePtr Value::pow(double exponent)
{
	ValuePtr res = make_shared<Value>(
		std::pow(this->data(), exponent),
		std::vector<ValuePtr>{ shared_from_this() }
	);

	res->_backward = [this, res, exponent]() {
		this->setGrad(this->grad() + exponent * std::pow(res->data(), exponent - 1) * res->grad());
	};

	return res;
}

ValuePtr Value::exp()
{
	ValuePtr res = make_shared<Value>(
		std::exp(this->data()),
		std::vector<ValuePtr>{ shared_from_this() }
	);

	res->_backward = [this, res]() {
		this->setGrad(this->grad() + std::exp(this->data()) * res->grad());
	};

	return res;
}

ValuePtr operator+(ValuePtr lhs, ValuePtr rhs)
{
	ValuePtr res = make_shared<Value>(
		lhs->data() + rhs->data(), 
		std::vector<ValuePtr>{lhs, rhs}
	);

	res->_backward = [res, lhs, rhs]() {
		lhs->setGrad(lhs->grad() + res->grad());
		rhs->setGrad(rhs->grad() + res->grad());
	};

	return res;
}

ValuePtr operator+(ValuePtr lhs, double val)
{
	ValuePtr rhs = make_shared<Value>(val);
	return lhs + rhs;
}

ValuePtr operator+(double val, ValuePtr rhs)
{
	ValuePtr lhs = make_shared<Value>(val);
	return lhs + rhs;
}

ValuePtr operator*(ValuePtr lhs, ValuePtr rhs)
{
	ValuePtr res = make_shared<Value>(
		lhs->data() * rhs->data(),
		std::vector<ValuePtr>{lhs, rhs}
	);

	res->_backward = [res, lhs, rhs]() {
		lhs->setGrad(lhs->grad() + rhs->data() * res->grad());
		rhs->setGrad(rhs->grad() + lhs->data() * res->grad());
	};

	return res;
}

ValuePtr operator*(ValuePtr lhs, double val)
{
	ValuePtr rhs = make_shared<Value>(val);
	return lhs * rhs;
}

ValuePtr operator*(double val, ValuePtr rhs)
{
	ValuePtr lhs = make_shared<Value>(val);
	return lhs * rhs;
}

ValuePtr operator-(ValuePtr rhs) { return rhs * -1; }

ValuePtr operator-(ValuePtr lhs, ValuePtr rhs) { return lhs + (-rhs); }

ValuePtr operator-(ValuePtr lhs, double val) { return lhs + (-val); }

ValuePtr operator-(double val, ValuePtr rhs) { return val + (-rhs); }

ValuePtr operator/(ValuePtr lhs, ValuePtr rhs) { return lhs * rhs->pow(-1); }

ValuePtr operator/(ValuePtr lhs, double val) { return lhs * (1 / val); }

ValuePtr operator/(double val, ValuePtr rhs) { return val * rhs->pow(-1); }
