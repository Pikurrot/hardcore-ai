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

public:
	Value(double data) 
		: _data(data), _grad(0), _backward{[]() {}} {};
	Value(double data, std::vector<ValuePtr> children)
		: _data(data), _grad(0), _children{children}, _backward{[]() {}} {};

	std::function<void()> _backward;

	double data() const { return this->_data; }
	double grad() const { return this->_grad; }
	const std::vector<ValuePtr>& children() const { return _children; }
	void setGrad(double grad) { this->_grad = grad; }
	
	std::vector<ValuePtr> getChildren() const { return this->_children; }

	ValuePtr pow(double exponent);
	ValuePtr exp();

	void backward();
};

ValuePtr value(double data);

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
