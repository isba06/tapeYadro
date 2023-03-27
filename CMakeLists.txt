cmake_minimum_required(VERSION 3.23)
project(tapeYadro)

set(CMAKE_CXX_STANDARD 20)

#set(COMPILE_OPTS -O3 -Wall -Wextra -Werror -pedantic -pedantic-errors)
#set(LINK_OPTS "")
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/src/main.cpp)

add_library(tapeYadro_lib ${SRC_FILES})
target_compile_options(tapeYadro_lib PUBLIC ${COMPILE_OPTS})
target_link_options(tapeYadro_lib PUBLIC ${LINK_OPTS})

add_executable(tapeYadro ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_compile_options(tapeYadro PRIVATE ${COMPILE_OPTS})
target_link_options(tapeYadro PRIVATE ${LINK_OPTS})
target_link_libraries(tapeYadro tapeYadro_lib)

