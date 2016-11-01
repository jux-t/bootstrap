#ifndef ARUA_AST_COMMENT_HEADER_H__
#define ARUA_AST_COMMENT_HEADER_H__
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

#include "ast/comment.h"

namespace arua {
namespace ast {

class CommentHeader : public Comment {
public:
	CommentHeader(std::string text);
	virtual ~CommentHeader() = default;

	virtual std::string getTypeString() const;
};

}
}

#endif
