cmake_minimum_required(VERSION 3.10)

project(mini-cli LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(mini-cli
    main.c
    linked.c
    linked.h
    Get/interaction.c
    Get/interaction.h
    Fonction/fonction.c
    Fonction/fonction.h
    Data/data.h
)

target_include_directories(mini-cli PRIVATE Data Get Fonction)

install(TARGETS mini-cli RUNTIME DESTINATION bin)
