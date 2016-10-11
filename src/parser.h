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
	void (*statement_type)(void);
	void (*statement_alias)(void);
	void (*statement_fn)(void);
	void (*statement_ret)(void);
	void (*statement_decl_var)(void);
	void (*pub)(void);
	void (*alias)(void);
	void (*canonical_path)(void);
	void (*canonical_path_match)(void);
	void (*identifier)(const char *id);
	void (*identifier_wildcard)(void);
	void (*type_array)(void);
	void (*type_basic)(void);
	void (*type_basic_template)(void);
	void (*decl_var)(void);
	
	/* R/L expressions */
	void (*r_expression)(void);
	void (*r_number)(const char *text);
	void (*r_number_qualifier)(const char *text);
	void (*r_number_sci)(const char *text);
	void (*r_number_radix)(const char *text);
	void (*r_number_radix_prefix)(const char *text);
	void (*r_invocation)(void);
	void (*r_string)(const char *text);
} arua_bootstrap_parser_visitor;

#if __cplusplus
}
#endif

#endif
