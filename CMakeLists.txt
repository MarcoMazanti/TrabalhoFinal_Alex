cmake_minimum_required(VERSION 3.31)
project(TrabalhoFinal C)

set(CMAKE_C_STANDARD 99)

# Busca todos os arquivos .c, exceto o main.c
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)

# Mostra no console todos os arquivos encontrados
message(STATUS "Arquivos encontrados: ${SOURCES}")

# Remove o main.c da lista (ajusta o caminho se necessário)
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.c")

# Cria a biblioteca estática com os arquivos auxiliares
add_library(TrabalhoFinalLib STATIC ${SOURCES})

# Cria o executável principal
add_executable(TrabalhoFinal main.c)

# Linka o executável com a biblioteca
target_link_libraries(TrabalhoFinal PRIVATE TrabalhoFinalLib)
