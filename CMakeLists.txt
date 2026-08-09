cmake_minimum_required(VERSION 3.10)
project(mini-cli C)

# 1. On déclare D'ABORD l'exécutable
add_executable(mini-cli
    main.c
    linked.c
    Fonction/fonction.c
    Get/interaction.c
)

# 2. On attache ENSUITE les dossiers d'en-têtes à la cible
target_include_directories(mini-cli PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Data
    ${CMAKE_CURRENT_SOURCE_DIR}/Fonction
    ${CMAKE_CURRENT_SOURCE_DIR}/Get
)
