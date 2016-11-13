#ifndef BIN_AST_MODULE_H__
#define BIN_AST_MODULE_H__
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

#include "ast/comment-header.h"
#include "ptr.h"

namespace arua {
namespace ast {

class Module {
public:
	virtual ~Module() = default;

	Ptr<CommentHeader> getHeaderComment() const;
	void setHeaderComment(Ptr<CommentHeader> header);
private:
	friend std::ostream & operator <<(std::ostream &stream, const Module &value);

	Ptr<CommentHeader> header;
};


}
}

#endif
