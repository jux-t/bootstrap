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

#include "ast/module.h"

using namespace arua;
using namespace arua::ast;
using namespace std;

Ptr<CommentHeader> Module::getHeaderComment() const {
	return this->header;
}

void Module::setHeaderComment(Ptr<CommentHeader> header) {
	this->header = header;
}

ostream & arua::ast::operator <<(ostream &stream, const Module &value) {
	if (value.header) {
		stream << value.header << endl;
	}
	return stream;
}
