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
#include <vector>

#include "ast/decl-var.h"
#include "ast/type.h"
#include "ptr.h"

namespace arua {
namespace ast {

class TypeStruct : public Type {
public:
	virtual ~TypeStruct() = default;

	virtual bool isStruct() const;
	virtual std::vector<Ptr<DeclVar>> getStructMembers() const;
	virtual std::string getStructName() const;

private:
	std::string name;
	std::vector<Ptr<DeclVar>> members;
};

}
}

#endif
