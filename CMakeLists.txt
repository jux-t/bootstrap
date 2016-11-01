project (arua-bootstrap-ast)
cmake_minimum_required (VERSION 3.2)

set (SRC
	src/exception.cc
	src/ast/node.cc
	src/ast/type-number.cc
	src/ast/type-derived.cc
	src/ast/type-array.cc
	src/ast/type-tuple.cc
	src/ast/type-fn.cc
	src/ast/scope.cc
	src/ast/scope-nested.cc
)

add_definitions (-g3)
add_definitions (-Wall -Wextra -Werror -pedantic)
add_definitions (-std=c++11)

include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/src")

add_library (arua-bootstrap-ast ${SRC})

add_executable (arua-bootstrap-ast-test src/test.cc)
target_link_libraries (arua-bootstrap-ast-test arua-bootstrap-ast)
