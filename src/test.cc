/*
	      ____    _____   __   _  ____
	     |    \  |     | |  | | ||    \
	     |     \ |     \ |  |_| ||     \
	     |__|\__\|__|\__\|______||__|\__\

	            arua bootstrap ast
	      copyright (c) 2016, josh junon
	    github.com/arua-lang/bootstrap-ast
	               mit license
*/

#include <iostream>

#include "ast.h"
#include "ptr.h"

using namespace arua;
using namespace arua::ast;
using namespace std;

int safeMain() {
	// root scope
	auto scope = Ptr<Scope>::make();

	auto i32 = Ptr<NumberType>::make(NumberClassification::INT, 32);

	// the below types are actually how strings will be represented in Arua.
	auto u8 = Ptr<NumberType>::make(NumberClassification::UINT, 8);
	auto u8_arr = Ptr<ArrayType>::make(u8.as<Type>());
	auto str8 = Ptr<DerivedType>::make("str8", u8_arr.as<Type>());
	// TODO(junon) implement aliases, add `str` as an alias to `str8`

	auto u16 = Ptr<NumberType>::make(NumberClassification::UINT, 16);
	auto u16_arr = Ptr<ArrayType>::make(u16.as<Type>());
	auto str16 = Ptr<DerivedType>::make("str16", u16_arr.as<Type>());

	auto u32 = Ptr<NumberType>::make(NumberClassification::UINT, 32);
	auto u32_arr = Ptr<ArrayType>::make(u32.as<Type>());
	auto str32 = Ptr<DerivedType>::make("str32", u32_arr.as<Type>());

	scope->addType(str8);
	scope->addType(str16);
	scope->addType(str32);

	auto fn_main = Ptr<FnType>::make(i32.as<Type>(), vector<Ptr<Type>>({str8.as<Type>()}));

	auto main = Ptr<DerivedType>::make("main", fn_main.as<Type>());
	scope->addType(main);
	cout << main << endl;

	return 0;
}

int main() {
	try {
		return safeMain();
	} catch (const Exception &ex) {
		cerr << "arua error: " << ex.what() << endl;
		return EXIT_FAILURE;
	}
}
