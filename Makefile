# Why oh why do all build systems suck? :(

.PHONY: all
all: bin/arua-bootstrap-grammar

.PHONY: clean
clean:
	rm -rf bin
	make -C ext/peg clean

bin/arua-bootstrap-grammar: bin/obj/cli.o bin/obj/arua.leg.o
	$(CC) -o $@ $^

bin/obj/%.o: src/%.c
	mkdir -p bin/obj
	$(CC) -std=c99 -Wall -Wextra -Werror -pedantic -c -o $@ $<

bin/obj/arua.leg.o: bin/gen/arua.leg.c
	$(CC) -std=c99 -c -o $@ $<

bin/gen/arua.leg.c: src/arua.leg | ext/peg/leg
	mkdir -p bin/gen
	ext/peg/leg -o "$@" -P $<

ext/peg/leg: ext/peg/Makefile
	make -C ext/peg
