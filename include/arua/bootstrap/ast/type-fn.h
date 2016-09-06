#ifndef ARUA_BOOTSTRAP_AST_TYPE_FN_H__
#define ARUA_BOOTSTRAP_AST_TYPE_FN_H__
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

#include <vector>

#include "arua/bootstrap/ast/type.h"

namespace arua {
namespace bootstrap {
namespace ast {

class FnType : public Type {
public:
	FnType();
	FnType(Ptr<Type> returnType);
	FnType(std::vector<Ptr<Type>> argTypes);
	FnType(Ptr<Type> returnType, std::vector<Ptr<Type>> argTypes);

	virtual std::string getTypeString() const;
	virtual std::string getValueString() const;

	virtual TypeClassification getTypeClassification() const;
	virtual void assertValidForScope(const Scope &scope) const;

	/**
		Whether or not this function has a void return type

		Make sure to call this prior to calling getReturnType()
		as the latter will throw if this returns true.
	*/
	bool isVoid() const;

	/**
		Returns the return type for this function

		Will throw if it's a void return type. Make sure to call
		isVoid() first. :)
	*/
	Ptr<Type> getReturnType() const;

	/**
		Returns the list of argument types, if any
	*/
	const std::vector<Ptr<Type>> getArgumentTypes() const;

private:
	Ptr<Type> returnType;
	std::vector<Ptr<Type>> argTypes;
};

}
}
}

#endif
