#ifndef BIN_AST_DECL_VAR_H__
#define BIN_AST_DECL_VAR_H__
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
#include <string>

#include "ptr.h"

namespace arua {
namespace ast {

class Type;

class DeclVar {
public:
	virtual ~DeclVar() = default;

	bool isReference() const;
	bool isMutable() const;
	bool isNullable() const;
	std::string getIdentifier() const;
	Ptr<Type> getType() const;

private:
	friend std::ostream & operator <<(std::ostream &stream, const DeclVar &value);

	bool reference;
	bool mut;
	bool nullable;
	std::string identifier;
	Ptr<Type> type;
};


}
}

#endif
