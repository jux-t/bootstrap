#ifndef BIN_AST_TYPE_NUMBER_H__
#define BIN_AST_TYPE_NUMBER_H__
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

#include "ast/type.h"

namespace arua {
namespace ast {

class TypeNumber : public Type {
public:
	enum class BaseType {
		UNSIGNED,
		SIGNED,
		FLOAT
	};

	virtual ~TypeNumber() = default;

	virtual bool isNumber() const;
	virtual bool isSigned() const;
	virtual bool isUnsigned() const;
	virtual bool isFloating() const;
	virtual unsigned int getWidth() const;

private:
	unsigned int width;
	BaseType type;
};


}
}

#endif
