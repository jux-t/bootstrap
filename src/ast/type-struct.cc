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

#include "ast/type-struct.h"

using namespace arua;
using namespace arua::ast;
using namespace std;

bool TypeStruct::isStruct() const {
	return true;
}

vector<Ptr<DeclVar>> TypeStruct::getStructMembers() const {
	return this->members;
}

string TypeStruct::getStructName() const {
	return this->name;
}
