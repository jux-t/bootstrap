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

/*
	This is not a great parser. This is not intended to be a great parser.
	Forgive me, Father Ritchie.
*/

#include <deque>
#include <iostream>
#include <sstream>

#include "ast/ast-visitor.h"
#include "exception.h"

using namespace arua;
using namespace std;

enum AruaParserElement : unsigned int {
	APE_HEADER_DOC,
};

AstVisitor::AstVisitor()
	: indent(0)
	, header_finished(false) {
}

void AstVisitor::visit_eof() {
	this->_burn_header_comments();
}

void AstVisitor::visit_indent() {
	this->_burn_header_comments();
	++indent;
}

void AstVisitor::visit_dedent() {
	--indent;
}

void AstVisitor::visit_comment_header(string text) {
	this->stack.push(APE_HEADER_DOC);
	this->resources.push(text);
}

void AstVisitor::visit_comment_doc(string text) {
#pragma unused(text)
	this->_burn_header_comments();
}

void AstVisitor::visit_statement_use() {
	this->_burn_header_comments();
}

void AstVisitor::visit_statement_type() {
	this->_burn_header_comments();
}

void AstVisitor::visit_statement_alias() {
	this->_burn_header_comments();
}

void AstVisitor::visit_statement_fn() {
	this->_burn_header_comments();
}

void AstVisitor::visit_statement_ret() {
	this->_burn_header_comments();
}

void AstVisitor::visit_statement_decl_var() {
	this->_burn_header_comments();
}

void AstVisitor::visit_pub() {
	this->_burn_header_comments();
}

void AstVisitor::visit_alias() {
	this->_burn_header_comments();
}

void AstVisitor::visit_canonical_path() {
	this->_burn_header_comments();
}

void AstVisitor::visit_canonical_path_match() {
	this->_burn_header_comments();
}

void AstVisitor::visit_identifier(string id) {
#pragma unused(id)
	this->_burn_header_comments();
}

void AstVisitor::visit_identifier_wildcard() {
	this->_burn_header_comments();
}

void AstVisitor::visit_type_array() {
	this->_burn_header_comments();
}

void AstVisitor::visit_type_basic() {
	this->_burn_header_comments();
}

void AstVisitor::visit_type_basic_template() {
	this->_burn_header_comments();
}

void AstVisitor::visit_decl_var() {
	this->_burn_header_comments();
}

void AstVisitor::visit_r_expression() {
	this->_burn_header_comments();
}

void AstVisitor::visit_r_number(string text) {
#pragma unused(text)
	this->_burn_header_comments();
}

void AstVisitor::visit_r_number_qualifier(string text) {
#pragma unused(text)
	this->_burn_header_comments();
}

void AstVisitor::visit_r_number_sci(string text) {
#pragma unused(text)
	this->_burn_header_comments();
}

void AstVisitor::visit_r_number_radix(string text) {
#pragma unused(text)
	this->_burn_header_comments();
}

void AstVisitor::visit_r_number_radix_prefix(string text) {
#pragma unused(text)
	this->_burn_header_comments();
}

void AstVisitor::visit_r_invocation() {
	this->_burn_header_comments();
}

void AstVisitor::visit_r_string(string text) {
#pragma unused(text)
	this->_burn_header_comments();
}

void AstVisitor::_burn_header_comments() {
	if (!this->stack.size() || this->stack.top() != APE_HEADER_DOC) {
		return;
	}

	if (this->indent) {
		throw error << "header comments cannot be indented";
	}

	if (this->header_finished) {
		throw error << "encountered header comments after initial header";
	}

	deque<string> elements;

	while (this->stack.size()) {
		if (this->stack.top() != APE_HEADER_DOC) {
			throw error << "encountered element other than a header doc: " << this->stack.top();
		}

		elements.push_front(this->resources.top());
		this->stack.pop();
		this->resources.pop();
	}

	stringstream ss;
	string delim = "";

	for (string elem : elements) {
		ss << delim << elem;
		delim = "\n";
	}

	this->header_finished = true;

	// TODO visit an AST element
	cout << "HEADER DOC  ---------------------" << endl;
	cout << ss.str() << endl;
	cout << "---------------------------------" << endl;
	// TODO
}
