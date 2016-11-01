#ifndef ARUA_BOOTSTRAP_AST_NODE_H__
#define ARUA_BOOTSTRAP_AST_NODE_H__
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

namespace arua {
namespace ast {

class Node {
public:
	/**
		Gets the type of this AST node as a string
	*/
	virtual std::string getTypeString() const = 0;

	/**
		Gets this AST node's representation
	*/
	virtual std::string getValueString() const = 0;

	/**
		Returns a standard, human-readable representation
		based on the above two methods
	*/
	std::string toString() const;
};

std::ostream & operator<<(std::ostream &stream, const Node &node);

}
}

#endif
