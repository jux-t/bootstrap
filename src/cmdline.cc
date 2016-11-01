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

#include "xopt.h"

#include "cmdline.h"

using namespace arua;
using namespace std;

static xoptOption options[] = {
	{
		"help",
		'?',
		offsetof(AruaCliConfig, help),
		0,
		XOPT_TYPE_BOOL,
		0,
		"show this help message"
	},

	XOPT_NULLOPTION
};

Ptr<AruaCliConfig> AruaCliConfig::parse(int argc, const char **argv) {
	auto config = arua::Ptr<AruaCliConfig>::make();

	const char *err = 0;
	xoptContext *ctx = xopt_context("arua-bootstrap", &options[0], XOPT_CTX_POSIXMEHARDER | XOPT_CTX_STRICT, &err);
	if (err) {
		cerr << "arua-bootstrap: error: " << err << endl;
		exit(2);
	}

	const char ** extras;
	int extraCount = xopt_parse(ctx, argc, argv, config.operator->(), &extras, &err);
	if (err) {
		cerr << "arua-bootstrap: error: " << err << endl;
		exit(2);
	}

	if (config->help) {
		xoptAutohelpOptions opts;
		opts.usage = "arua-bootstrap: usage: arua-bootstrap <file ...>";
		opts.prefix = "The Arua bootstrap compiler.";
		opts.suffix = 0;
		opts.spacer = 15;

		xopt_autohelp(ctx, stderr, &opts, &err);
		exit(2);
	}

	for (int i = 0; i < extraCount; i++) {
		config->extras.push_back(extras[i]);
	}

	free(extras);
	free(ctx);

	return config;
}
