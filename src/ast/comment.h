#ifndef ARUA_AST_COMMENT_H__
#define ARUA_AST_COMMENT_H__
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

#include "ast/node.h"

namespace arua {
namespace ast {

class Comment : public Node {
public:
	Comment(std::string text);
	virtual ~Comment() = default;
	
	virtual std::string getTypeString() const;
	virtual std::string getValueString() const;
	
private:
	std::string text;
};

}
}

#endif
