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

#include "ast/comment-doc.h"

using namespace arua;
using namespace std;

ast::CommentDoc::CommentDoc(string text)
		: ast::Comment(text) {
}

string ast::CommentDoc::getTypeString() const {
	return this->ast::Comment::getTypeString() + ":doc";
}
