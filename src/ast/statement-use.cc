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

#include "ast/statement-use.h"

using namespace arua;
using namespace arua::ast;
using namespace std;

Ptr<Path> StatementUse::getImport() const {
	return this->import;
}

string StatementUse::getAlias() const {
	return this->alias;
}

ostream & arua::ast::operator <<(ostream &stream, const StatementUse &value) {
	stream << "use " << value.import;
	if (!value.alias.empty()) {
		stream << " as " << value.alias;
	}
	return stream;
}
