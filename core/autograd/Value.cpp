#include "core/autograd/Value.hpp"
#include <functional>
#include <vector>

using std::shared_ptr;
using std::make_shared;
using ValuePtr = shared_ptr<Value>;

Value operator+(ValuePtr lhs, ValuePtr rhs)
{
	ValuePtr res = make_shared<Value>(
		lhs->data() + rhs->data(), 
		std::vector<ValuePtr>{lhs, rhs}
	);

	res->_backward = [res, lhs, rhs]() {
		lhs->setGrad(lhs->grad() + res->grad());
		rhs->setGrad(rhs->grad() + res->grad());
	};

	return *res;
}
