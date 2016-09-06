#include <iostream>

#include "arua/bootstrap/ast.h"
#include "arua/bootstrap/ptr.h"

using namespace arua::bootstrap;
using namespace arua::bootstrap::ast;
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
	cout << fn_main << endl;

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
