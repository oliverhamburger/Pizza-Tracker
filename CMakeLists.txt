cmake_minimum_required(VERSION 3.13)
project(Pizza_Delivery)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pizza_Delivery Driver.cpp Order.cpp Restaurant.cpp Time.cpp interface.cpp)