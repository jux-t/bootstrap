#ifndef ARUA_CMDLINE_H__
#define ARUA_CMDLINE_H__
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
#include <vector>

#include "ptr.h"

namespace arua {

struct AruaCliConfig {
	bool help;

	std::vector<std::string> extras;

	static Ptr<AruaCliConfig> parse(int argc, const char **argv);
};

}

#endif
