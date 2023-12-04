cmake_minimum_required(VERSION 3.0.0)
project(app VERSION 0.1.0 LANGUAGES C)

add_library(lib STATIC
    lib/source/hash-table.c
    lib/source/list-graph.c
    lib/source/matrix-graph.c
    lib/source/priority-queue.c
    lib/source/stack.c
)

target_include_directories(lib PUBLIC lib/include)

add_executable(app main.c)

target_link_libraries(app lib)
