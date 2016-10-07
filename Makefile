# Why oh why do all build systems suck? :(

.PHONY: all
all: bin/arua-bootstrap-grammar

bin/arua-bootstrap-grammar: bin/obj/cli.o
	$(CC) -o $@ $^

bin/obj/%.o: src/%.c
	mkdir -p bin/obj
	$(CC) -std=c99 -Wall -Wextra -Wall -pedantic -c -o $@ $<
