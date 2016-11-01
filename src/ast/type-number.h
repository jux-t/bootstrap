#ifndef ARUA_BOOTSTRAP_AST_TYPE_NUMBER_H__
#define ARUA_BOOTSTRAP_AST_TYPE_NUMBER_H__
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

#include "ast/type.h"

namespace arua {
namespace ast {

enum class NumberClassification {
	INT,
	UINT,
	FLOAT,
};

class NumberType : public Type {
public:
	NumberType(NumberClassification numberClassification, unsigned int width);

	virtual std::string getTypeString() const;
	virtual std::string getValueString() const;

	virtual TypeClassification getTypeClassification() const;
	virtual void assertValidForScope(const Scope &scope) const;

	/**
		Returns the number's general type (float, integer, etc.)
	*/
	NumberClassification getNumberClassification() const;

	/**
		Returns the number's width, in bits.
	*/
	unsigned int getWidth() const;

private:
	const NumberClassification numberClassification;
	const unsigned int width;
};

}
}

#endif
