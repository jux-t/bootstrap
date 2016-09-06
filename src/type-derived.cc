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

#include "arua/bootstrap/ast/exception.h"
#include "arua/bootstrap/ast/type-derived.h"

using namespace arua::bootstrap;
using namespace arua::bootstrap::ast;
using namespace std;

DerivedType::DerivedType(string name, Ptr<Type> base)
		: name(name)
		, baseType(base) {
	// sanity checks
	if (name.empty()) {
		throw ast::error << "derived type names must have at least one character: " << *this;
	}

	if (this == baseType.operator->()) {
		// absolutely do not try to toString() *this here. :)
		throw ast::error << "derived types cannot be derivations of themselves";
	}
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

void DerivedType::assertValidForScope(const Scope &scope) const {
	if (!scope.canResolve(this->name)) {
		throw ast::error << "derived type is not resolvable in this scope: " << *this;
	}

	// we don't need to recurse any further here as the call that added the type that ultimately
	// passed the above check (this type) would have checked the base type. because of that, we
	// can assume all derived types that are registered with us are clean.
}

Ptr<Type> DerivedType::getBaseType() const {
	return this->baseType;
}

string DerivedType::getName() const {
	return this->name;
}
