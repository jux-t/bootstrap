#ifndef ARUA_BOOTSTRAP_AST_TYPE_TUPLE_H__
#define ARUA_BOOTSTRAP_AST_TYPE_TUPLE_H__
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

#include <initializer_list>
#include <string>
#include <vector>

#include "arua/bootstrap/ast/type.h"

namespace arua {
namespace bootstrap {
namespace ast {

class TupleType : public Type {
public:
	template <typename... T>
	TupleType(T... types)
			: types({types...}) {
	}

	TupleType(std::initializer_list<Ptr<Type>> types);
	TupleType(std::vector<Ptr<Type>> types);

	virtual std::string getTypeString() const;
	virtual std::string getValueString() const;

	virtual TypeClassification getTypeClassification() const;

	/**
		Returns the tuple's types
	*/
	std::vector<Ptr<Type>> getTypes() const;

private:
	std::vector<Ptr<Type>> types;
};

}
}
}

#endif



