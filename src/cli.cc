#include <iostream>

#include "parser.h"

using namespace std;

extern "C" int yyparse();

#define EVENT(name) .name = []() { cout << "\x1b[38;5;255m" #name "\x1b[m" << endl; },
#define CEVENT(name) .name = [](const char *text) { cout << "\x1b[38;5;255m" #name "\x1b[m: \x1b[35;1m" << text << "\x1b[m" << endl; },
arua_bootstrap_parser_visitor arua_bsp_visitor = {
	EVENT(eof)
	EVENT(indent)
	EVENT(dedent)
	CEVENT(comment_header)
	CEVENT(comment_doc)
	EVENT(statement_use)
	EVENT(statement_type)
	EVENT(statement_alias)
	EVENT(statement_fn)
	EVENT(pub)
	EVENT(alias)
	EVENT(canonical_path)
	EVENT(canonical_path_match)
	EVENT(identifier_wildcard)
	CEVENT(identifier)
	EVENT(type_array)
	EVENT(type_basic)
	EVENT(type_basic_template)
	EVENT(decl_var)
};

int main() {
	while (yyparse());
	return 0;
}
