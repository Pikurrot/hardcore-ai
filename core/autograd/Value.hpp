#pragma once
#include <functional>
#include <vector>
#include <memory>

using std::shared_ptr;
using std::make_shared;
using ValuePtr = shared_ptr<Value>;

class Value : public std::enable_shared_from_this<Value>
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
};

Value operator+(ValuePtr lhs, ValuePtr rhs);
