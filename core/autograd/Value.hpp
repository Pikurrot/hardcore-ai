#pragma once
#include <functional>
#include <vector>
#include <memory>

struct Value;
using std::shared_ptr;
using std::make_shared;
using ValuePtr = shared_ptr<Value>;

struct Value : public std::enable_shared_from_this<Value>
{
private:
	double _data;
	double _grad;
	std::vector<ValuePtr> _children;
	int _requiresGrad;

public:
	Value(double data, int requiresGrad = 0)
		: _data(data), _grad(0), _requiresGrad(requiresGrad), _backward{[]() {}} {};
	Value(double data, std::vector<ValuePtr> children, int requiresGrad = 0)
		: _data(data), _grad(0), _children{children}, _requiresGrad(requiresGrad), _backward{[]() {}} {};

	std::function<void()> _backward;
	int gradCount = 0;

	double data() const { return this->_data; }
	double grad() const { return this->_grad; }
	const std::vector<ValuePtr>& children() const { return _children; }
	int requiresGrad() const { return this->_requiresGrad; }
	void setGrad(double grad) { this->_grad = grad; }
	
	std::vector<ValuePtr> getChildren() const { return this->_children; }

	ValuePtr pow(double exponent);
	ValuePtr exp();
	ValuePtr log();

	void backward();
};

ValuePtr value(double data, int requiresGrad = 0);

ValuePtr operator+(ValuePtr lhs, ValuePtr rhs);
ValuePtr operator+(ValuePtr lhs, double val);
ValuePtr operator+(double val, ValuePtr rhs);
ValuePtr operator*(ValuePtr lhs, ValuePtr rhs);
ValuePtr operator*(ValuePtr lhs, double val);
ValuePtr operator*(double val, ValuePtr rhs);
ValuePtr operator-(ValuePtr rhs);
ValuePtr operator-(ValuePtr lhs, ValuePtr rhs);
ValuePtr operator-(ValuePtr lhs, double val);
ValuePtr operator-(double val, ValuePtr rhs);
ValuePtr operator/(ValuePtr lhs, ValuePtr rhs);
ValuePtr operator/(ValuePtr lhs, double val);
ValuePtr operator/(double val, ValuePtr rhs);

// Activation functions

ValuePtr sigmoid(ValuePtr x);
ValuePtr tanh(ValuePtr x);
ValuePtr relu(ValuePtr x);
ValuePtr leakyRelu(ValuePtr x, double alpha = 0.01);
