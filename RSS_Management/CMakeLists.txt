cmake_minimum_required(VERSION 3.20)
project(RSS_Management)

set(CMAKE_CXX_STANDARD 14)
add_executable(RSS_Management main.cpp src/SerialPort.cpp src/SP.cpp src/RSS_Parser.cpp src/MainMenu.cpp headers/MainMenu.h)
target_include_directories(RSS_Management PRIVATE ./headers)
