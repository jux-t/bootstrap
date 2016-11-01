project (arua-bootstrap-ast)
cmake_minimum_required (VERSION 3.2)

add_subdirectory (ext)

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

add_custom_command (OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/arua.leg.cc"
	COMMAND $<TARGET_FILE:leg> -o "${CMAKE_CURRENT_BINARY_DIR}/arua.leg.cc" -P "${CMAKE_CURRENT_SOURCE_DIR}/src/parser/arua.leg"
	MAIN_DEPENDENCY src/parser/arua.leg
	COMMENT "Generating Arua grammar parser"
	VERBATIM)

add_library (arua-bootstrap-grammar "${CMAKE_CURRENT_BINARY_DIR}/arua.leg.cc")

add_definitions (-g3)
set (ARUA_FLAGS -Wall -Wextra -Werror -pedantic)
add_definitions (-std=c++11)

include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/src")

add_library (arua-bootstrap-ast ${SRC})
add_executable (arua-bootstrap-test src/test.cc)

target_link_libraries (arua-bootstrap-test arua-bootstrap-ast)
target_link_libraries (arua-bootstrap-test arua-bootstrap-grammar)

target_compile_options (arua-bootstrap-test PRIVATE ${ARUA_FLAGS})
target_compile_options (arua-bootstrap-ast PRIVATE ${ARUA_FLAGS})
