#ifndef BIN_AST_STRUCT_MEMBERS_H__
#define BIN_AST_STRUCT_MEMBERS_H__
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
#include <vector>

#include "ast/decl-var.h"
#include "ptr.h"

namespace arua {
namespace ast {

class StructMembers {
public:
	virtual ~StructMembers() = default;

	const std::vector<Ptr<DeclVar>> getMembers() const;

private:
	friend std::ostream & operator <<(std::ostream &stream, const StructMembers &value);

	std::vector<Ptr<DeclVar>> members;
};


}
}

#endif
