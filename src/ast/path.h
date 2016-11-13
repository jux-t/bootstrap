#ifndef BIN_AST_PATH_H__
#define BIN_AST_PATH_H__
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

class Path {
public:
	Path(std::vector<std::string> &leafs);
	virtual ~Path() = default;

private:
	friend std::ostream & operator <<(std::ostream &stream, const Path &value);

	std::vector<std::string> leafs;
};


}
}

#endif
