#include <iostream>

#include "parser.h"

using namespace std;

extern "C" int yyparse();

arua_bootstrap_parser_visitor arua_bsp_visitor = {
	[] () { cout << "EOF" << endl; },
	[] () { cout << "INDENT" << endl; },
	[] () { cout << "DEDENT" << endl; }
};

int main() {
	while (yyparse());
	return 0;
}
