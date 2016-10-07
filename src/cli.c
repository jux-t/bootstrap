#include <stdio.h>

extern int yyparse(void);

int main(void) {
	while (yyparse());
	return 0;
}
