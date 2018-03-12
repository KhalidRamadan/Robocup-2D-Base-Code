cmake_minimum_required(VERSION 3.9)
project(Robocup-2D-Base-Code)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(SRCS
main.cpp
test.cpp
test.hpp
)

set(LEXER_SRC Grammar/Lexer.l)
set(PARSER_SRC Grammar/parser.y)

find_package(Qt5Core)
find_package(Qt5Network)
find_package(FLEX)
find_package(BISON)



flex_target(LEXER ${LEXER_SRC} ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
bison_target(PARSER ${PARSER_SRC} ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
add_flex_bison_dependency(LEXER PARSER)
set_property(SOURCE "${BISON_PARSER_OUTPUT_SOURCE}" PROPERTY SKIP_AUTOMOC ON)
set_property(SOURCE "${BISON_PARSER_OUTPUT_HEADER}" PROPERTY SKIP_AUTOMOC ON)
set_property(SOURCE "${FLEX_LEXER_OUTPUTS}" PROPERTY SKIP_AUTOMOC ON)
message("${BISON_PARSER_OUTPUTS}")

add_executable(${PROJECT_NAME}
	${SRCS}
	${LEXER_SRC}
	${PARSER_SRC}
	${FLEX_LEXER_OUTPUTS}
	${BISON_PARSER_OUTPUTS}
)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Network)