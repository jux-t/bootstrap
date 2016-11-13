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

#include "ast/path.h"

using namespace arua;
using namespace arua::ast;
using namespace std;


Path::Path(vector<string> &leafs)
		: leafs(leafs) {
}

ostream & arua::ast::operator <<(ostream &stream, const Path &value) {
	const char *delim = "";
	for (const string &leaf : value.leafs) {
		stream << delim << leaf;
		delim = ".";
	}

	return stream;
}
