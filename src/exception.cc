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

#include "ast/exception.h"

using namespace arua;
using namespace std;

ast::AstExceptionConstructor arua::ast::error;

ast::AstException::AstException() {
}

ast::AstException::AstException(string what)
		: message(what) {
}

ast::AstException::AstException(const exception &existing)
		: message(existing.what()) {
}

ast::AstException::AstException(const ast::AstException &other)
		: message(other.message) {
}

const char* ast::AstException::what() const throw() {
	return this->message.c_str();
}

ostream & ast::operator<<(ostream &stream, const ast::AstException &ex) {
	return stream << ex.what();
}
