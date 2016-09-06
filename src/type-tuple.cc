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

#include <sstream>

#include "arua/bootstrap/ast/type-tuple.h"

using namespace arua::bootstrap;
using namespace arua::bootstrap::ast;
using namespace std;

TupleType::TupleType(initializer_list<Ptr<Type>> types)
		: types(types) {
}

TupleType::TupleType(vector<Ptr<Type>> types)
		: types(types) {
}

string TupleType::getTypeString() const {
	return "type:tuple";
}

string TupleType::getValueString() const {
	stringstream ss;
	ss << "(";

	string comma = "";
	for (const Ptr<Type> &type : this->types) {
		ss << comma << type->toString();
		comma = ", ";
	}

	ss << ")";
	return ss.str();
}

TypeClassification TupleType::getTypeClassification() const {
	return TypeClassification::TUPLE;
}

vector<Ptr<Type>> TupleType::getTypes() const {
	return this->types;
}
