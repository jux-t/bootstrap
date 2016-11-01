add_subdirectory (xopt)

set (LEG_SRC
	peg/src/tree.c
	peg/src/compile.c
	peg/src/leg.c)

add_executable (leg ${LEG_SRC})
