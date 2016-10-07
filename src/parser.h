#ifndef ARUA_BOOTSTRAP_PARSER_H__
#define ARUA_BOOTSTRAP_PARSER_H__
#pragma once

#if __cplusplus
extern "C" {
#endif

typedef struct {
	void (*hello)(void);
} arua_bootstrap_parser_visitor;

#if __cplusplus
}
#endif

#endif
