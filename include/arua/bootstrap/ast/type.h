#ifndef ARUA_BOOTSTRAP_AST_TYPE_H__
#define ARUA_BOOTSTRAP_AST_TYPE_H__
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

#include "arua/bootstrap/ast/node.h"
#include "arua/bootstrap/ptr.h"

namespace arua {
namespace bootstrap {
namespace ast {

enum class TypeClassification {
	NUMBER,
	DERIVED,
	ARRAY,
	TUPLE,
};

class Type : public Node {
public:
	virtual ~Type() = default;

	/**
		Returns the type classification for this type,
		which indicates which type of subclass to cast to and how
		to handle certain operations.
	*/
	virtual TypeClassification getTypeClassification() const = 0;
};

}
}
}

#endif


