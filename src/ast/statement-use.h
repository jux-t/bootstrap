#ifndef BIN_AST_STATEMENT_USE_H__
#define BIN_AST_STATEMENT_USE_H__
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

#include "ast/path.h"
#include "ptr.h"

namespace arua {
namespace ast {

class StatementUse {
public:
	virtual ~StatementUse() = default;

	Ptr<Path> getImport() const;
	std::string getAlias() const;

private:
	friend std::ostream & operator <<(std::ostream &stream, const StatementUse &value);

	Ptr<Path> import;
	std::string alias;
};


}
}

#endif
