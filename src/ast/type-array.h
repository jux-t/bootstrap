#ifndef ARUA_BOOTSTRAP_AST_TYPE_ARRAY_H__
#define ARUA_BOOTSTRAP_AST_TYPE_ARRAY_H__
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

#include <string>

#include "ast/type.h"

namespace arua {
namespace ast {

class ArrayType : public Type {
public:
	ArrayType(Ptr<Type> base);

	virtual std::string getTypeString() const;
	virtual std::string getValueString() const;

	virtual TypeClassification getTypeClassification() const;
	virtual void assertValidForScope(const Scope &scope) const;

	/**
		Returns the type this type is based on
	*/
	Ptr<Type> getBaseType() const;

private:
	Ptr<Type> baseType;
};

}
}

#endif


