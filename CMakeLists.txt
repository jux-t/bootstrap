project (arua-bootstrap-ast)
cmake_minimum_required (VERSION 3.2)

set (SRC
	src/arua-ast.cc
	src/exception.cc
	src/module.cc
	src/node.cc
	src/type.cc
	src/type-number.cc
	src/type-derived.cc
	src/type-array.cc
)

add_library (arua-bootstrap-ast ${SRC})
add_executable (arua-bootstrap-ast-test src/test.cc)
target_link_libraries (arua-bootstrap-ast-test arua-bootstrap-ast)
