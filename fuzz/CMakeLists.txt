cmake_minimum_required(VERSION 3.2)
project(fuzz)
include_directories("../include/")
link_directories("../")

ADD_EXECUTABLE(fuzz fuzz.cpp)
#target_link_libraries(fuzz modbus)
target_link_libraries(fuzz libmodbus.a)

#set(CMAKE_C_COMPILER "/usr/local/bin/afl-clang-fast++")
#set(CMAKE_CXX_COMPILER "/usr/local/bin/afl-clang-fast++")

set(CMAKE_C_COMPILER "afl-clang-fast")
set(CMAKE_CXX_COMPILER "afl-clang-fast")




set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -static-libsan -lstdc++ ")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++ -shared -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++ -fsanitize=address -static-libsan")