cmake_minimum_required(VERSION 4.1)
project(TemplateVB)

set(CMAKE_CXX_STANDARD 20)

add_executable(TemplateVB Class/main.cpp
        Class/TemplateVB.cpp
        Class/TemplateVB.h)
