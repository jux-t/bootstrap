#ifndef ARUA_AST_AST_VISITOR_H__
#define ARUA_AST_AST_VISITOR_H__
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

#include <string>
#include <stack>

#include "ast/comment-header.h"
#include "parser/visitor.h"
#include "ptr.h"

namespace arua {
namespace ast {

class AstVisitor : private ParserVisitor {
protected:
	AstVisitor();

	virtual void visitHeaderComment(Ptr<CommentHeader> comment) = 0;

private:
	virtual void visit_eof();
	virtual void visit_indent();
	virtual void visit_dedent();
	virtual void visit_comment_header(std::string text);
	virtual void visit_comment_doc(std::string text);
	virtual void visit_statement_use();
	virtual void visit_statement_type();
	virtual void visit_statement_alias();
	virtual void visit_statement_fn();
	virtual void visit_statement_ret();
	virtual void visit_statement_decl_var();
	virtual void visit_pub();
	virtual void visit_alias();
	virtual void visit_canonical_path();
	virtual void visit_canonical_path_match();
	virtual void visit_identifier(std::string id);
	virtual void visit_identifier_wildcard();
	virtual void visit_type_array();
	virtual void visit_type_basic();
	virtual void visit_type_basic_template();
	virtual void visit_decl_var();

	virtual void visit_r_expression();
	virtual void visit_r_number(std::string text);
	virtual void visit_r_number_qualifier(std::string text);
	virtual void visit_r_number_sci(std::string text);
	virtual void visit_r_number_radix(std::string text);
	virtual void visit_r_number_radix_prefix(std::string text);
	virtual void visit_r_invocation();
	virtual void visit_r_string(std::string text);

	void _burn_header_comments();

	int indent;
	bool header_finished;

	std::stack<unsigned int> stack;
	std::stack<std::string> resources;
};

}
}

#endif
