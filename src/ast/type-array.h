#ifndef BIN_AST_TYPE_ARRAY_H__
#define BIN_AST_TYPE_ARRAY_H__
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
#include "ptr.h"

namespace arua {
namespace ast {

class TypeArray : public Type {
public:
	virtual ~TypeArray() = default;

	virtual bool isArray() const;
	virtual Ptr<Type> getBase() const;

private:
	Ptr<Type> base;
};

}
}

#endif
