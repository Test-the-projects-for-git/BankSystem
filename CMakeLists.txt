cmake_minimum_required (VERSION 3.25.2)

project(BankSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable (BankSystemApp src/main.cpp
								src/bank.cpp
								includes/bank.hpp
								includes/headers.hpp)