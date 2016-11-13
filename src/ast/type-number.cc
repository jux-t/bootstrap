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

#include "ast/type-number.h"

using namespace arua;
using namespace arua::ast;
using namespace std;

bool TypeNumber::isNumber() const {
	return true;
}

bool TypeNumber::isSigned() const {
	return this->type == TypeNumber::BaseType::SIGNED;
}

bool TypeNumber::isUnsigned() const {
	return this->type == TypeNumber::BaseType::UNSIGNED;
}

bool TypeNumber::isFloating() const {
	return this->type == TypeNumber::BaseType::FLOAT;
}

unsigned int TypeNumber::getWidth() const {
	return this->width;
}
