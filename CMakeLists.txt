project (arua-bootstrap)
cmake_minimum_required (VERSION 3.2)

add_subdirectory (ext)

set (SRC
	src/cli.cc
	src/exception.cc
	src/cmdline.cc)

add_custom_command (OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/arua.leg.cc"
	COMMAND $<TARGET_FILE:leg> -o "${CMAKE_CURRENT_BINARY_DIR}/arua.leg.cc" -P "${CMAKE_CURRENT_SOURCE_DIR}/src/parser/arua.leg"
	MAIN_DEPENDENCY src/parser/arua.leg
	COMMENT "Generating Arua grammar parser"
	VERBATIM)

add_library (arua-bootstrap-parser "${CMAKE_CURRENT_BINARY_DIR}/arua.leg.cc")

add_definitions (-g3)
add_definitions (-std=c++11)

set (ARUA_FLAGS -Wall -Wextra -Werror -pedantic)

include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/src")
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/ext/xopt")
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/ext/filesystem")

add_executable (arua-bootstrap ${SRC})

target_link_libraries (arua-bootstrap xopt)
target_link_libraries (arua-bootstrap arua-bootstrap-parser)

target_compile_options (arua-bootstrap PRIVATE ${ARUA_FLAGS})
