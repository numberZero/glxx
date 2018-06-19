cmake_minimum_required(VERSION 3.0)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

project(gl++)

add_library(gl++
	c/functions.cxx
)

target_include_directories(gl++ PUBLIC ${CMAKE_SOURCE_DIR})
