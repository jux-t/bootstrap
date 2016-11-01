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

#include "ast/type-array.h"

using namespace arua;
using namespace arua::ast;
using namespace std;

ArrayType::ArrayType(Ptr<Type> base)
		: baseType(base) {
}

string ArrayType::getTypeString() const {
	return "type:array";
}

string ArrayType::getValueString() const {
	return this->baseType->toString();
}

TypeClassification ArrayType::getTypeClassification() const {
	return TypeClassification::ARRAY;
}

void ArrayType::assertValidForScope(const Scope &scope) const {
	this->baseType->assertValidForScope(scope);
}

Ptr<Type> ArrayType::getBaseType() const {
	return this->baseType;
}
