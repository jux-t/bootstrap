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

#include "ast/ast-visitor.h"

using namespace arua;
using namespace std;

void AstVisitor::visit_eof() {
}

void AstVisitor::visit_indent() {
}

void AstVisitor::visit_dedent() {
}

void AstVisitor::visit_comment_header(string text) {
#pragma unused(text)
}

void AstVisitor::visit_comment_doc(string text) {
#pragma unused(text)
}

void AstVisitor::visit_statement_use() {
}

void AstVisitor::visit_statement_type() {
}

void AstVisitor::visit_statement_alias() {
}

void AstVisitor::visit_statement_fn() {
}

void AstVisitor::visit_statement_ret() {
}

void AstVisitor::visit_statement_decl_var() {
}

void AstVisitor::visit_pub() {
}

void AstVisitor::visit_alias() {
}

void AstVisitor::visit_canonical_path() {
}

void AstVisitor::visit_canonical_path_match() {
}

void AstVisitor::visit_identifier(string id) {
#pragma unused(id)
}

void AstVisitor::visit_identifier_wildcard() {
}

void AstVisitor::visit_type_array() {
}

void AstVisitor::visit_type_basic() {
}

void AstVisitor::visit_type_basic_template() {
}

void AstVisitor::visit_decl_var() {
}


void AstVisitor::visit_r_expression() {
}

void AstVisitor::visit_r_number(string text) {
#pragma unused(text)
}

void AstVisitor::visit_r_number_qualifier(string text) {
#pragma unused(text)
}

void AstVisitor::visit_r_number_sci(string text) {
#pragma unused(text)
}

void AstVisitor::visit_r_number_radix(string text) {
#pragma unused(text)
}

void AstVisitor::visit_r_number_radix_prefix(string text) {
#pragma unused(text)
}

void AstVisitor::visit_r_invocation() {
}

void AstVisitor::visit_r_string(string text) {
#pragma unused(text)
}
