cmake_minimum_required(VERSION 4.3)
project(SFML_Project_Master)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML COMPONENTS Audio Graphics Window System CONFIG REQUIRED)

add_subdirectory(Starter)

#add_executable(Starter main.cpp src/game.cc)
#target_link_libraries(Starter PUBLIC SFML::Graphics)
