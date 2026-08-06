cmake_minimum_required(VERSION 3.0)

project(mini-cli LANGUAGES C)

add_executable(mini-cli main.c)

install(TARGETS mini-cli RUNTIME DESTINATION bin)
