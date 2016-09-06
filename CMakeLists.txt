project (arua-bootstrap-ast)
cmake_minimum_required (VERSION 3.2)

set (SRC
	src/arua-ast.cc
	src/exception.cc
	src/node.cc
	src/type-number.cc
	src/type-derived.cc
	src/type-array.cc
	src/type-tuple.cc
	src/scope.cc
	src/scope-nested.cc
)

add_definitions (-g3)
add_definitions (-Wall -Wextra -Werror -pedantic)

include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/src")

add_library (arua-bootstrap-ast ${SRC})
add_executable (arua-bootstrap-ast-test src/test.cc)
target_link_libraries (arua-bootstrap-ast-test arua-bootstrap-ast)
