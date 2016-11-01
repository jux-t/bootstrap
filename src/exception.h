#ifndef ARUA_BOOTSTRAP_EXCEPTION_H__
#define ARUA_BOOTSTRAP_EXCEPTION_H__
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

class Exception : public virtual std::exception {
	friend class ExceptionThrower;
public:
	Exception();
	Exception(std::string what);
	Exception(const std::exception &existing);
	Exception(const Exception &other);

	virtual const char* what() const throw();

	template <typename T>
	Exception operator<<(const T& v) {
		std::stringstream ss;
		ss << this->message << v;
		this->message = ss.str();
		return *this;
	}

	Exception operator<<(std::ostream&(*fp)(std::ostream&)) {
		std::stringstream ss;
		ss << this->message << fp;
		this->message = ss.str();
		return *this;
	}

private:
	std::string message;
};

class ExceptionConstructor {
public:
	template <typename T>
	Exception operator<<(const T& v) {
		Exception ex;
		return ex << v;
	}
};

std::ostream & operator<<(std::ostream &stream, const Exception &ex);

extern ExceptionConstructor error;

}

#endif

