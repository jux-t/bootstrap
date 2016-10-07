# Why oh why do all build systems suck? :(

.PHONY: all
all: bin/arua-bootstrap-grammar

.PHONY: clean
clean:
	rm -rf bin
	rm -rf ext/peg/peg ext/peg/leg ext/peg/*.o

bin/arua-bootstrap-grammar: bin/obj/cli.o bin/obj/arua.peg.o
	$(CC) -o $@ $^

bin/obj/%.o: src/%.c
	mkdir -p bin/obj
	$(CC) -std=c99 -Wall -Wextra -Werror -pedantic -c -o $@ $<

bin/obj/arua.peg.o: bin/gen/arua.peg.c
	$(CC) -std=c99 -c -o $@ $<

bin/gen/arua.peg.c: src/arua.peg | ext/peg/peg
	mkdir -p bin/gen
	ext/peg/peg -o "$@" -P $<

ext/peg/peg: ext/peg/Makefile # kind of a hack but oh well
	make -C ext/peg
