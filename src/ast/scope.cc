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
#include "arua/bootstrap/ast/scope.h"
#include "arua/bootstrap/ast/type-array.h"
#include "arua/bootstrap/ast/type-derived.h"
#include "arua/bootstrap/ast/type-number.h"
#include "arua/bootstrap/ast/type-tuple.h"

using namespace arua::bootstrap;
using namespace arua::bootstrap::ast;
using namespace std;

string Scope::getTypeString() const {
	return "scope:root";
}

string Scope::getValueString() const {
	return "t:" + to_string(this->types.size());
}

Ptr<DerivedType> Scope::resolve(string name) const {
	auto itr = this->types.find(name);
	if (itr == this->types.end()) {
		throw ast::error << "could not resolve type in current scope: " << name;
	}

	return itr->second;
}

bool Scope::canResolve(string name) const {
	return this->types.count(name);
}

void Scope::addType(Ptr<DerivedType> type) {
	auto itr = this->types.find(type->getName());
	if (itr != this->types.end()) {
		throw ast::error
			<< "could not add type " << type->getName() << " with base type " << type->toString()
			<< "; already registered under same name as " << itr->second->toString();
	}

	// make sure that every type this added type is made up of is also registered within
	// this scope. see the documentation notes on the method we call here.
	try {
		// we get the base type here because of coursse the type being added right now
		// isn't part of the current scope; we're more interested in the type it's derived
		// off of.
		type->getBaseType()->assertValidForScope(*this);
	} catch (AstException &ex) {
		throw ast::error << "could not add type " << type << " to scope " << *this << ": " << ex;
	}

	this->types.insert(map<string, Ptr<DerivedType>>::value_type(type->getName(), type));
}
