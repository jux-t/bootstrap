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

#include "exception.h"

using namespace std;

arua::ExceptionConstructor arua::error;

arua::Exception::Exception() {
}

arua::Exception::Exception(string what)
		: message(what) {
}

arua::Exception::Exception(const exception &existing)
		: message(existing.what()) {
}

arua::Exception::Exception(const arua::Exception &other)
		: message(other.message) {
}

const char* arua::Exception::what() const throw() {
	return this->message.c_str();
}

ostream & arua::operator<<(ostream &stream, const arua::Exception &ex) {
	return stream << ex.what();
}
