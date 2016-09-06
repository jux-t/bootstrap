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

	return 0;
}
