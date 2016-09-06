#include <iostream>

#include "arua/bootstrap/ast.h"
#include "arua/bootstrap/ptr.h"

using namespace arua::bootstrap;
using namespace arua::bootstrap::ast;
using namespace std;

int main() {
	auto i32 = Ptr<NumberType>::make(NumberClassification::INT, 32);
	cout << i32 << endl;

	auto i1 = Ptr<NumberType>::make(NumberClassification::UINT, 1);
	auto _bool = Ptr<DerivedType>::make("bool", i1.as<Type>());
	cout << _bool << endl;

	auto _bool__arr = Ptr<ArrayType>::make(_bool.as<Type>());
	cout << _bool__arr << endl;

	// lol on this nameing.
	auto tup__i32__bool__arr = Ptr<TupleType>::make(i32.as<Type>(), _bool__arr.as<Type>());
	cout << tup__i32__bool__arr << endl;

	return 0;
}
