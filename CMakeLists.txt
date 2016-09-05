project (arua-bootstrap-ast)
cmake_minimum_required (VERSION 3.2)

set (SRC
	src/arua-ast.cc
)

add_library (arua-bootstrap-ast ${SRC})
add_executable (arua-bootstrap-ast-test src/test.cc)
target_link_libraries (arua-bootstrap-ast-test arua-bootstrap-ast)
