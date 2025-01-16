cmake_minimum_required(VERSION 3.10)
project(Koyo-str)

add_library(facekid STATIC src/koyo-str.c)
target_include_directories(koyo-str PUBLIC include)