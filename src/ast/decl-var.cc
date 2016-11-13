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

#include "ast/decl-var.h"
#include "ast/type.h"

using namespace arua;
using namespace arua::ast;
using namespace std;

bool DeclVar::isReference() const {
	return this->reference;
}

bool DeclVar::isMutable() const {
	return this->mut;
}

bool DeclVar::isNullable() const {
	return this->nullable;
}

string DeclVar::getIdentifier() const {
	return this->identifier;
}

Ptr<Type> DeclVar::getType() const {
	return this->type;
}

ostream & arua::ast::operator <<(ostream &stream, const DeclVar &value) {
	stream << value.identifier << " ";
	if (value.mut) {
		stream << "!";
	}
	if (value.reference) {
		stream << "&";

		if (value.nullable) {
			stream << "&";
		}
	}
	
	return stream << value.type;
}
