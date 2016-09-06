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

	// make sure all of the base types are also in the current scope hierarchy
	this->validateAllTypes(type->getBaseType(), type.as<Type>());

	this->types.insert(map<string, Ptr<DerivedType>>::value_type(type->getName(), type));
}

void Scope::validateAllTypes(Ptr<Type> type, Ptr<Type> top) const {
	switch (type->getTypeClassification()) {
	case TypeClassification::NUMBER:
		// numbers are supreme primitives and thus are always 'valid' in any scope.
		break;

	case TypeClassification::DERIVED:
		if (!this->canResolve(type.as<DerivedType>()->getName())) {
			throw ast::error
				<< "could not add type " << top << " to scope " << *this
				<< "; an ancestor isn't within the current scope or any of its parents: "
				<< type;
		}

		// we don't need to recurse any further here as the call that added the type that ultimately
		// passed the above check would have checked the base type. because of that, we can assume
		// all derived types that are registered with us are clean.
		break;

	case TypeClassification::ARRAY:
		this->validateAllTypes(type.as<ArrayType>()->getBaseType().as<Type>(), top);
		break;

	case TypeClassification::TUPLE:
		for (Ptr<Type> &childType : type.as<TupleType>()->getTypes()) {
			this->validateAllTypes(childType, top);
		}
		break;

	default:
		throw ast::error << "unknown type classification for type " << type << ": " << (int) type->getTypeClassification();
	}
}
