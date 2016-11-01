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

#include "cmdline.h"
#include "parser/parser.h"

using namespace arua;
using namespace std;

int main(int argc, const char **argv) {
	auto config = AruaCliConfig::parse(argc, argv);

	if (config->extras.size() == 0) {
		cerr << "arua-bootstrap: no inputs specified" << endl;
		return 2;
	}

	for (filesystem::path filename : config->extras) {
		cout << "arua-bootstrap: " << filename << endl;
		
		if (filename == "-") {
			AruaParserSetFile(stdin);
			AruaParse();
		} else {
			FILE *file = fopen(filename.str().c_str(), "r");
			if (file == NULL) {
				cerr << "arua-bootstrap: could not open " << filename << ": " << strerror(errno) << endl;
			}

			AruaParserSetFile(file);
			AruaParse();

			fclose(file);
		}
	}

	return 0;
}
