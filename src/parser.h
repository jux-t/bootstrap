#ifndef ARUA_BOOTSTRAP_PARSER_H__
#define ARUA_BOOTSTRAP_PARSER_H__
#pragma once

#if __cplusplus
extern "C" {
#endif

typedef struct {
	void (*eof)(void);
	void (*indent)(void);
	void (*dedent)(void);
	void (*header_comment)(const char *);
	void (*doc_comment)(const char *);
} arua_bootstrap_parser_visitor;

#if __cplusplus
}
#endif

#endif
