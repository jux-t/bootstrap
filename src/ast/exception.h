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
		std::stringstream ss;
		ss << this->message << v;
		this->message = ss.str();
		return *this;
	}

	AstException operator<<(std::ostream&(*fp)(std::ostream&)) {
		std::stringstream ss;
		ss << this->message << fp;
		this->message = ss.str();
		return *this;
	}

private:
	std::string message;
};

class AstExceptionConstructor {
public:
	template <typename T>
	AstException operator<<(const T& v) {
		AstException ex;
		return ex << v;
	}
};

std::ostream & operator<<(std::ostream &stream, const AstException &ex);

extern AstExceptionConstructor error;

}
}

#endif

