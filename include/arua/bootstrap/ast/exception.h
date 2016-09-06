#ifndef ARUA_BOOTSTRAP_AST_EXCEPTION_H__
#define ARUA_BOOTSTRAP_AST_EXCEPTION_H__
#pragma once
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

#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace arua {
namespace bootstrap {
namespace ast {

class AstException : public virtual std::exception {
	friend class AstExceptionThrower;
public:
	AstException();
	AstException(std::string what);
	AstException(const std::exception &existing);
	AstException(const AstException &other);

	virtual const char* what() const throw();

	template <typename T>
	AstException operator<<(const T& v) {
		this->message << v;
		return *this;
	}

	AstException operator<<(std::ostream&(*fp)(std::ostream&)) {
		this->message << fp;
		return *this;
	}

private:
	std::stringstream message;
};

class AstExceptionConstructor {
public:
	template <typename T>
	AstException operator<<(const T& v) {
		AstException ex;
		return ex << v;
	}
};

extern AstExceptionConstructor error;

}
}
}

#endif

