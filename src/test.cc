#include <iostream>

#include "arua/bootstrap/ast.h"
#include "arua/bootstrap/ptr.h"

using namespace arua::bootstrap;
using namespace arua::bootstrap::ast;
using namespace std;

int safeMain() {
	auto i32 = Ptr<NumberType>::make(NumberClassification::INT, 32);
	cout << i32 << endl;

	auto i1 = Ptr<NumberType>::make(NumberClassification::UINT, 1);
	auto _bool = Ptr<DerivedType>::make("bool", i1.as<Type>());
	cout << _bool << endl;

	auto _bool__arr = Ptr<ArrayType>::make(_bool.as<Type>());
	cout << _bool__arr << endl;

	// lol on this naming.
	auto tup__i32__bool__arr = Ptr<TupleType>::make(i32.as<Type>(), _bool__arr.as<Type>());
	cout << tup__i32__bool__arr << endl;

	auto root_scope = Ptr<Scope>::make();
	root_scope->addType(_bool);
	cout << root_scope << endl;

	auto nested_scope = Ptr<NestedScope>::make(root_scope);
	auto bitset = Ptr<DerivedType>::make("bitset", _bool__arr.as<Type>()); // don't worry, not an actual bitset.
	nested_scope->addType(bitset);
	cout << nested_scope << endl;

	return 0;
}

int main() {
	try {
		return safeMain();
	} catch (const AstException &ex) {
		cerr << "arua error: " << ex.what() << endl;
		return EXIT_FAILURE;
	}
}
