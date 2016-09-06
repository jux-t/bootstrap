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

#include "arua/bootstrap/ast/exception.h"

using namespace arua::bootstrap;
using namespace std;

ast::AstExceptionConstructor arua::bootstrap::ast::error;

ast::AstException::AstException() {
}

ast::AstException::AstException(string what)
		: message(what) {
}

ast::AstException::AstException(const exception &existing)
		: message(existing.what()) {
}

ast::AstException::AstException(const ast::AstException &other) {
	this->message << other.message.rdbuf();
}

const char* ast::AstException::what() const throw() {
	return this->message.str().c_str();
}
