cmake_minimum_required(VERSION 3.20)
project(sort)

add_executable(main)

FILE(GLOB SORT_SOURCES testing/*.c)

target_sources(main PUBLIC ${SORT_SOURCES})

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	set_target_properties(main PROPERTIES
	COMPILE_FLAGS "-std=c89 -fsanitize=address"
	LINK_FLAGS "-fsanitize=address")
endif()


if (CMAKE_BUILD_TYPE STREQUAL "Release")
	set_target_properties(main PROPERTIES
	COMPILE_FLAGS "-Wall -Werror -pedantic -Wextra -std=c89")
endif()

if (CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
	set_target_properties(main PROPERTIES
	COMPILE_FLAGS "-std=c89 -fsanitize=address"
	LINK_FLAGS "-fsanitize=address")
endif()
