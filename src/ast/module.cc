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

Module::Module(string name)
		: name(name) {
}

string Module::getTypeString() const {
	return "module";
}

string Module::getValueString() const {
	return this->name;
}

Ptr<CommentHeader> Module::getHeaderComment() const {
	return this->headerComment;
}

void Module::visitHeaderComment(Ptr<CommentHeader> comment) {
	this->headerComment = comment;
}
