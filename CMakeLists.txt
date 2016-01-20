cmake_minimum_required(VERSION 2.6)

project (SCALLOP C CXX)

add_subdirectory(json lib)
include_directories(json)
#add_subdirectory(log)
#add_subdirectory(pool)
link_directories(${SCALLOP_SOURCE_DIR}/lib)

set(APP_SRC scallop.cpp)
set(EXECUTABLE_OUTPUT_PATH ${SCALLOP_SOURCE_DIR}/bin)
add_executable(scallop ${APP_SRC})
target_link_libraries(scallop libcjson)


