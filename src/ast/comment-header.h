#ifndef BIN_AST_COMMENT_HEADER_H__
#define BIN_AST_COMMENT_HEADER_H__
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

namespace arua {
namespace ast {

class CommentHeader {
public:
	CommentHeader(std::vector<std::string> &lines);
	virtual ~CommentHeader() = default;

	const std::vector<std::string> & getLines() const;

private:
	friend std::ostream & operator <<(std::ostream &stream, const CommentHeader &value);

	std::vector<std::string> lines;
};


}
}

#endif
