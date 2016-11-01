#ifndef ARUA_AST_MODULE_H__
#define ARUA_AST_MODULE_H__
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

#include "ast/ast-visitor.h"
#include "ast/comment-header.h"
#include "ast/node.h"
#include "ast/scope.h"
#include "ptr.h"

namespace arua {
namespace ast {

class Module : public Node, private AstVisitor {
public:
	Module(std::string name);
	virtual ~Module() = default;

	virtual std::string getTypeString() const;
	virtual std::string getValueString() const;

	Ptr<CommentHeader> getHeaderComment() const;

private:
	virtual void visitHeaderComment(Ptr<CommentHeader> comment);

	std::string name;
	Ptr<CommentHeader> headerComment;
};

}
}

#endif
