cmake_minimum_required(VERSION 2.6)

project (SCALLOP C CXX)

set(SRC_LIST main.cpp LogFile.cpp)
add_executable(logtest ${SRC_LIST})
