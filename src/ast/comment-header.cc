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

#include "ast/comment-header.h"

using namespace arua;
using namespace arua::ast;
using namespace std;

CommentHeader::CommentHeader(vector<string> &lines)
		: lines(lines) {
}

const vector<string> & CommentHeader::getLines() const {
	return this->lines;
}

ostream & arua::ast::operator <<(ostream &stream, const CommentHeader &value) {
	for (const string &line : value.lines) {
		stream << "## " << line << endl;
	}
	return stream;
}
