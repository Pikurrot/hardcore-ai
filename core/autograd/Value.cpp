#include "core/autograd/Value.hpp"
#include <functional>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using std::shared_ptr;
using std::make_shared;
using ValuePtr = shared_ptr<Value>;

ValuePtr Value::pow(double exponent)
{
	ValuePtr res = make_shared<Value>(
		std::pow(this->data(), exponent),
		std::vector<ValuePtr>{ shared_from_this() },
		this->requiresGrad()
	);

	if (this->requiresGrad()) 
	{
		res->_backward = [this, res, exponent]() {
			this->setGrad(this->grad() + exponent * std::pow(this->data(), exponent - 1) * res->grad());
		};
		this->gradCount++;
	}

	return res;
}

ValuePtr Value::exp()
{
	ValuePtr res = make_shared<Value>(
		std::exp(this->data()),
		std::vector<ValuePtr>{ shared_from_this() },
		this->requiresGrad()
	);

	if (this->requiresGrad()) 
	{
		res->_backward = [this, res]() {
			this->setGrad(this->grad() + std::exp(this->data()) * res->grad());
		};
		this->gradCount++;
	}

	return res;
}

ValuePtr Value::log()
{
	ValuePtr res = make_shared<Value>(
		std::log(this->data()),
		std::vector<ValuePtr>{ shared_from_this() },
		this->requiresGrad()
	);

	if (this->requiresGrad()) 
	{
		res->_backward = [this, res]() {
			this->setGrad(this->grad() + 1 / this->data() * res->grad());
		};
		this->gradCount++;
	}

	return res;
}

void Value::backward()
{
	std::queue<ValuePtr> leaves;
	std::unordered_set<ValuePtr> visited;
	std::unordered_map<ValuePtr, int> gradCount;
	std::vector<ValuePtr> topo;
	leaves.push(shared_from_this());
	gradCount[shared_from_this()] = 0;

	while (!leaves.empty()) {
		auto leaf = leaves.front();
		leaves.pop();

		// there are more paths to leaf
		if (gradCount[leaf] < leaf->gradCount) continue;

		topo.push_back(leaf);
		visited.insert(leaf);

		for (auto child : leaf->children()) {
			if (visited.find(child) != visited.end()) continue;
			leaves.push(child);

			if (gradCount.find(child) == gradCount.end()) gradCount[child] = 1;
			else gradCount[child]++;
		}
	}

	// compute gradients
	this->setGrad(1);
	for (auto it = topo.begin(); it != topo.end(); ++it)
		(*it)->_backward();
}

ValuePtr value(double data, int requiresGrad)
{
	return make_shared<Value>(data, requiresGrad);
}

ValuePtr operator+(ValuePtr lhs, ValuePtr rhs)
{
	ValuePtr res = make_shared<Value>(
		lhs->data() + rhs->data(), 
		std::vector<ValuePtr>{lhs, rhs},
		lhs->requiresGrad() || rhs->requiresGrad()
	);

	res->_backward = [res, lhs, rhs]() {
		if (lhs->requiresGrad()) lhs->setGrad(lhs->grad() + res->grad());
		if (rhs->requiresGrad()) rhs->setGrad(rhs->grad() + res->grad());
	};
	lhs->gradCount += lhs->requiresGrad();
	rhs->gradCount += rhs->requiresGrad();

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
		std::vector<ValuePtr>{lhs, rhs},
		lhs->requiresGrad() || rhs->requiresGrad()
	);

	res->_backward = [res, lhs, rhs]() {
		if (lhs->requiresGrad()) lhs->setGrad(lhs->grad() + rhs->data() * res->grad());
		if (rhs->requiresGrad()) rhs->setGrad(rhs->grad() + lhs->data() * res->grad());
	};
	lhs->gradCount += lhs->requiresGrad();
	rhs->gradCount += rhs->requiresGrad();

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

ValuePtr sigmoid(ValuePtr x)
{
	ValuePtr res = make_shared<Value>(
		1 / (1 + std::exp(-x->data())),
		std::vector<ValuePtr>{x},
		x->requiresGrad()
	);

	if (x->requiresGrad()) 
	{
		res->_backward = [res, x]() {
			x->setGrad(x->grad() + res->data() * (1 - res->data()) * res->grad());
		};
		x->gradCount++;
	}

	return res;
}

ValuePtr tanh(ValuePtr x)
{
	ValuePtr res = make_shared<Value>(
		std::tanh(x->data()),
		std::vector<ValuePtr>{x},
		x->requiresGrad()
	);

	if (x->requiresGrad()) 
	{
		res->_backward = [res, x]() {
			x->setGrad(x->grad() + (1 - std::pow(res->data(), 2)) * res->grad());
		};
		x->gradCount++;
	}

	return res;
}

ValuePtr relu(ValuePtr x)
{
	ValuePtr res = make_shared<Value>(
		std::max(0.0, x->data()),
		std::vector<ValuePtr>{x},
		x->requiresGrad()
	);

	if (x->requiresGrad() && res->data() > 0) 
	{
		res->_backward = [res, x]() {
			x->setGrad(x->grad() + res->grad());
		};
		x->gradCount++;
	}

	return res;
}

ValuePtr leakyRelu(ValuePtr x, double alpha)
{
	ValuePtr res = make_shared<Value>(
		x->data() > 0 ? x->data() : alpha * x->data(),
		std::vector<ValuePtr>{x},
		x->requiresGrad()
	);

	if (x->requiresGrad() && res->data() > 0) 
	{
		res->_backward = [res, x, alpha]() {
			x->setGrad(x->grad() + (x->data() > 0 ? 1.0 : alpha) * res->grad());
		};
		x->gradCount++;
	}

	return res;
}
