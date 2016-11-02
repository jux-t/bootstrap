#ifndef ARUA_BOOTSTRAP_PARSER_H__
#define ARUA_BOOTSTRAP_PARSER_H__
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

#include "filesystem/path.h"

namespace arua {

void ParseStdin();
void ParseFile(filesystem::path filepath);

}

#endif
