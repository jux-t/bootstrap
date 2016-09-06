#ifndef ARUA_BOOTSTRAP_AST_TYPE_DERIVED_H__
#define ARUA_BOOTSTRAP_AST_TYPE_DERIVED_H__
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

#include "arua/bootstrap/ast/type.h"

namespace arua {
namespace bootstrap {
namespace ast {

class DerivedType : public Type {
public:
	DerivedType(std::string name, Ptr<Type> base);

	virtual std::string getTypeString() const;
	virtual std::string getValueString() const;

	virtual TypeClassification getTypeClassification() const;

	/**
		Returns the type this type is based on
	*/
	Ptr<Type> getBaseType() const;

	/**
		Returns the name of this type
	*/
	std::string getName() const;
private:
	std::string name;
	Ptr<Type> baseType;
};

}
}
}

#endif

