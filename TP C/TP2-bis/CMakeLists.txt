cmake_minimum_required(VERSION 3.23)
project(TP2_bis C)

set(CMAKE_C_STANDARD 11)

include_directories("Tab foot dyn")

add_executable(TP2_bis
        "Tab foot dyn/equipe.c"
        "Tab foot dyn/equipe.h"
        "Tab foot dyn/equipe_alloc_dyn.c"
        "Tab foot dyn/equipe_alloc_dyn.h"
        "Tab foot dyn/main.c")
