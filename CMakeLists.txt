cmake_minimum_required(VERSION 3.15...4.0)
project(mandelbrot VERSION 0.1.0 
                   LANGUAGES CXX)

add_executable(mandelbrot src/main.cpp
                          src/mandelbrot.cpp
                          src/mandelbrot.h)

