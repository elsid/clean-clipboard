cmake_minimum_required(VERSION 2.6)

project(clean-clipboard)

set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -g -O2 -Wl,-subsystem,windows")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

set(CXX_FLAGS
    "-fexceptions"
    "-pipe"
    "-std=c++11"
    "-Wall"
    "-Wcast-qual"
    "-Wconversion"
    "-Wctor-dtor-privacy"
    "-Wextra"
    "-Winline"
    "-Wnon-virtual-dtor"
    "-Wold-style-cast"
    "-Woverloaded-virtual"
    "-Wpacked"
    "-Wredundant-decls"
)

foreach(FLAG ${CXX_FLAGS})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAG}")
endforeach()

add_subdirectory(src)
