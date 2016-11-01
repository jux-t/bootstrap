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

#include "ast/exception.h"
#include "ast/scope-nested.h"
#include "ast/type-derived.h"

using namespace arua;
using namespace arua::ast;
using namespace std;

NestedScope::NestedScope(Ptr<Scope> parent)
		: parent(parent) {
	// sanity check
	if (this == parent.operator->()) {
		throw ast::error << "refusing to make a nested scope with itself as a parent";
	}
}

string NestedScope::getTypeString() const {
	return "scope:nested";
}

string NestedScope::getValueString() const {
	return this->Scope::getValueString() + " p:" + this->parent->toString();
}

Ptr<DerivedType> NestedScope::resolve(string name) const {
	auto itr = this->types.find(name);
	if (itr == this->types.end()) {
		return this->parent->resolve(name);
	}

	return itr->second;
}

bool NestedScope::canResolve(string name) const {
	if (this->types.count(name)) {
		return true;
	}

	return this->parent->canResolve(name);
}
