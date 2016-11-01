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

#include <stdio.h>

#include "exception.h"
#include "parser/parser.h"
#include "parser/visitor.h"

using namespace arua;
using namespace std;

static ParserVisitor *current_visitor = 0;

#define EVENT(name) []() { current_visitor->visit_##name(); }
#define STR_EVENT(name) [](const char *str) { current_visitor->visit_##name(str); }
static arua_bootstrap_parser_visitor bsp = {
	EVENT(eof),
	EVENT(indent),
	EVENT(dedent),
	STR_EVENT(comment_header),
	STR_EVENT(comment_doc),
	EVENT(statement_use),
	EVENT(statement_type),
	EVENT(statement_alias),
	EVENT(statement_fn),
	EVENT(statement_ret),
	EVENT(statement_decl_var),
	EVENT(pub),
	EVENT(alias),
	EVENT(canonical_path),
	EVENT(canonical_path_match),
	STR_EVENT(identifier),
	EVENT(identifier_wildcard),
	EVENT(type_array),
	EVENT(type_basic),
	EVENT(type_basic_template),
	EVENT(decl_var),
	EVENT(r_expression),
	STR_EVENT(r_number),
	STR_EVENT(r_number_qualifier),
	STR_EVENT(r_number_sci),
	STR_EVENT(r_number_radix),
	STR_EVENT(r_number_radix_prefix),
	EVENT(r_invocation),
	STR_EVENT(r_string),
};

static void register_visitor(Ptr<ParserVisitor> visitor) {
	AruaParserSetVisitor(&bsp);
	current_visitor = visitor.operator->();
}

void arua::ParseAruaStdin(Ptr<ParserVisitor> visitor) {
	register_visitor(visitor);
	AruaParserSetFile(stdin);
	AruaParse();
}

void arua::ParseAruaFile(filesystem::path filepath, Ptr<ParserVisitor> visitor) {
	register_visitor(visitor);
	FILE *file = fopen(filepath.str().c_str(), "r");
	if (file == NULL) {
		throw error << "could not open file for reading: " << filepath << " (" << strerror(errno) << ")" << endl;
	}
	AruaParserSetFile(file);
	AruaParse();
	fclose(file);
}
