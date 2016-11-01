# Why oh why do all build systems suck? :(

.PHONY: all
all: bin/arua-bootstrap-grammar

.PHONY: clean
clean:
	rm -rf bin
	make -C ext/peg clean

.PHONY: test
test: bin/arua-bootstrap-grammar
	bin/arua-bootstrap-grammar < test/fixture/hello.u

bin/arua-bootstrap-grammar: bin/obj/cli.o bin/obj/arua.leg.o
	$(CXX) $(CXXFLAGS) -o $@ $^

bin/obj/%.o: src/%.c src/parser.h
	mkdir -p bin/obj
	$(CC) $(CFLAGS) -std=c99 -Wall -Wextra -Werror -pedantic -c -o $@ $<

bin/obj/%.o: src/%.cc src/parser.h
	mkdir -p bin/obj
	$(CXX) $(CXXFLAGS) -std=c++11 -Wall -Wextra -Werror -c -o $@ $<

bin/obj/arua.leg.o: bin/gen/arua.leg.c
	mkdir -p bin/obj
	$(CC) $(CFLAGS) -Isrc -std=c99 -c -o $@ $<

bin/gen/arua.leg.c: src/arua.leg | ext/peg/leg
	mkdir -p bin/gen
	ext/peg/leg -o "$@" -P $<

ext/peg/leg: ext/peg/Makefile
	make -C ext/peg
