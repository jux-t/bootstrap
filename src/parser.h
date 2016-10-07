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
	void (*comment_header)(const char *);
	void (*comment_doc)(const char *);
	void (*statement_use)(void);
	void (*pub)(void);
	void (*alias)(const char *identifier);
	void (*canonical_path_match)(void);
	void (*canonical_path)(void);
	void (*identifier_wildcard)(void);
	void (*identifier)(const char *id);
} arua_bootstrap_parser_visitor;

#if __cplusplus
}
#endif

#endif
