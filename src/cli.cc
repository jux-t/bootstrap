#include <iostream>

#include "parser.h"

using namespace std;

extern "C" int yyparse();

arua_bootstrap_parser_visitor arua_bsp_visitor = {
	[] () { cout << "EOF" << endl; },
	[] () { cout << "INDENT" << endl; },
	[] () { cout << "DEDENT" << endl; },
	[] (const char *contents) { cout << "##> " << contents << endl; },
	[] (const char *contents) { cout << "#:> " << contents << endl; },
	[] () { cout << "USE>" << endl << "   "; },
	[] () { cout << "<USE" << endl; },
	[] (const char *alias_id) { cout << "    alias: " << alias_id << endl; },
	[] () { cout << "    match-path:"; },
	[] () { cout << endl; },
	[] () { cout << " *"; },
	[] (const char *identifier) { cout << " " << identifier; }
};

int main() {
	while (yyparse());
	return 0;
}
