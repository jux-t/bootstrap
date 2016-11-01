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

using namespace arua;
using namespace std;

ast::Comment::Comment(string text)
		: text(text) {
}

string ast::Comment::getTypeString() const {
	return "comment";
}

string ast::Comment::getValueString() const {
	return this->text;
}
