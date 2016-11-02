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

#include <iostream>
#include <vector>

#include "cmdline.h"
#include "exception.h"
#include "parser/parser.h"

using namespace arua;
using namespace std;

int main(int argc, const char **argv) {
	auto config = AruaCliConfig::parse(argc, argv);

	if (config->extras.size() == 0) {
		cerr << "arua-bootstrap: no inputs specified" << endl;
		return 2;
	}

	int exitCode = 0;
	for (filesystem::path filename : config->extras) {
		try {
			cout << "arua-bootstrap: " << filename << endl;
	
			if (filename == "-") {
				ParseStdin();
			} else {
				ParseFile(filename);
			}

		} catch (arua::Exception &e) {
			cerr << "arua-bootstrap: error: " << e << endl;
			exitCode = 1;
		}
	}

	if (exitCode) {
		return exitCode;
	}

	return 0;
}
