cmake_minimum_required(VERSION 3.15)
project(StephenPrataExercises)

set(CMAKE_CXX_STANDARD 17)

add_executable(StephenPrataExercises main.cpp)
add_executable(chapter_4 chapter_4.cpp)
add_executable(chapter_5 chapter_5.cpp)
add_executable(chapter_6 chapter_6.cpp)
add_executable(chapter_7 chapter_7.cpp)
add_executable(chapter_8 chapter_8.cpp)
add_executable(chapter_9 chapter_9.cpp chapter_9_namespaces.h
        chapter_9_namespaces.cpp golf.h golf.cpp sales.h sales.cpp)
add_executable(chapter_10 chapter_10.cpp
        ch_10_bankbill.h ch_10_bankbill.cpp
        ch_10_person.h ch_10_person.cpp ch_10_sales.h ch_10_sales.cpp ch_10_list.h ch_10_list.cpp)