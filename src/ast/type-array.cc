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

bool TypeArray::isArray() const {
	return true;
}

Ptr<Type> TypeArray::getBase() const {
	return this->base;
}
