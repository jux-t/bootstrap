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

#include "arua/bootstrap/ast/node.h"

using namespace arua::bootstrap;
using namespace std;

string ast::Node::toString() const {
	return "[" + this->getTypeString()  + " " + this->getValueString() + "]";
}

ostream & ast::operator<<(ostream &stream, const ast::Node &node) {
	return stream << node.toString();
}
