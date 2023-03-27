cmake_minimum_required(VERSION 3.24)
project(morpion)

set(CMAKE_CXX_STANDARD 17)

add_executable(morpion main.cpp Position.h Position.cpp Plateau.h Symbole.h Symbole.cpp Plateau.cpp Joueur.h Joueur.cpp)
