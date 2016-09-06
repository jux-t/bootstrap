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

#include "arua/bootstrap/ast/type-derived.h"

using namespace arua::bootstrap;
using namespace arua::bootstrap::ast;
using namespace std;

DerivedType::DerivedType(string name, Ptr<Type> base)
		: name(name)
		, baseType(base) {
}

string DerivedType::getTypeString() const {
	return "type:derived";
}

string DerivedType::getValueString() const {
	return this->name + " <- " + this->baseType->toString();
}

TypeClassification DerivedType::getTypeClassification() const {
	return TypeClassification::DERIVED;
}

Ptr<Type> DerivedType::getBaseType() const {
	return this->baseType;
}

string DerivedType::getName() const {
	return this->name;
}
