#ifndef BIN_AST_TYPE_STRUCT_H__
#define BIN_AST_TYPE_STRUCT_H__
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

#include "ast/type.h"
#include "ast/struct-members.h"
#include "ptr.h"

namespace arua {
namespace ast {

class TypeStruct : public Type {
public:
	virtual ~TypeStruct() = default;

	virtual bool isStruct() const;
	virtual Ptr<StructMembers> getStructMembers() const;
	virtual std::string getStructName() const;

private:
	std::string name;
	Ptr<StructMembers> members;
};


}
}

#endif
