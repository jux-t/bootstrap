#ifndef ARUA_PARSER_VISITOR_H__
#define ARUA_PARSER_VISITOR_H__
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

#include "filesystem/path.h"

#include "parser/parser.h"
#include "ptr.h"

namespace arua {

struct ParserVisitor {
	virtual ~ParserVisitor() = default;

	virtual void visit_eof() = 0;
	virtual void visit_indent() = 0;
	virtual void visit_dedent() = 0;
	virtual void visit_comment_header(std::string text) = 0;
	virtual void visit_comment_doc(std::string text) = 0;
	virtual void visit_statement_use() = 0;
	virtual void visit_statement_type() = 0;
	virtual void visit_statement_alias() = 0;
	virtual void visit_statement_fn() = 0;
	virtual void visit_statement_ret() = 0;
	virtual void visit_statement_decl_var() = 0;
	virtual void visit_pub() = 0;
	virtual void visit_alias() = 0;
	virtual void visit_canonical_path() = 0;
	virtual void visit_canonical_path_match() = 0;
	virtual void visit_identifier(std::string id) = 0;
	virtual void visit_identifier_wildcard() = 0;
	virtual void visit_type_array() = 0;
	virtual void visit_type_basic() = 0;
	virtual void visit_type_basic_template() = 0;
	virtual void visit_decl_var() = 0;

	virtual void visit_r_expression() = 0;
	virtual void visit_r_number(std::string text) = 0;
	virtual void visit_r_number_qualifier(std::string text) = 0;
	virtual void visit_r_number_sci(std::string text) = 0;
	virtual void visit_r_number_radix(std::string text) = 0;
	virtual void visit_r_number_radix_prefix(std::string text) = 0;
	virtual void visit_r_invocation() = 0;
	virtual void visit_r_string(std::string text) = 0;
};

void ParseAruaStdin(Ptr<ParserVisitor> visitor);
void ParseAruaFile(filesystem::path filepath, Ptr<ParserVisitor> visitor);

}

#endif
