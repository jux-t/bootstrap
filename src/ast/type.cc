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

#include "ast/type.h"
#include "exception.h"

using namespace arua;
using namespace arua::ast;
using namespace std;

bool Type::isNumber() const {
	return false;
}

bool Type::isSigned() const {
	return false;
}

bool Type::isUnsigned() const {
	return false;
}

bool Type::isFloating() const {
	return false;
}

bool Type::isStruct() const {
	return false;
}

bool Type::isArray() const {
	return false;
}

unsigned int Type::getWidth() const {
	return 0;
}

Ptr<Type> Type::getBase() const {
	return Ptr<Type>();
}

Ptr<StructMembers> Type::getStructMembers() const {
	return Ptr<StructMembers>();
}

string Type::getStructName() const {
	return "";
}

ostream & arua::ast::operator <<(ostream &stream, const Type &value) {
	if (value.isArray()) {
		stream << '[' << value.getBase() << ']';
	} else if (value.isNumber()) {
		char symbol = 0;
		if (value.isSigned()) {
			symbol = 'i';
		} else if (value.isUnsigned()) {
			symbol = 'u';
		} else if (value.isFloating()) {
			symbol = 'f';
		} else {
			throw error << "unknown numeric type discovered!";
		}

		stream << symbol << value.getWidth();
	} else if (value.isStruct()) {
		stream << "struct " << value.getStructName() << endl;
		stream << value.getStructMembers() << endl; // TODO use a renderer for indentation
	} else {
		throw error << "unknown type variant discovered!";
	}

	return stream;
}
