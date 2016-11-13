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

#include "ast/struct-members.h"
#include "ast/type.h"

using namespace arua;
using namespace arua::ast;
using namespace std;

ostream & arua::ast::operator <<(ostream &stream, const StructMembers &value) {
	for (const Ptr<DeclVar> &dvar : value.members) {
		stream << dvar << endl;
	}

	return stream;
}
