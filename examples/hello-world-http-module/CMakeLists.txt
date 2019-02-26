cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)

include_directories(../../interfaces)

set(SRC HelloWorldModule.cpp HelloWorldModule.hpp)

add_library(HelloWorld SHARED ${SRC})

set_target_properties(HelloWorld PROPERTIES PREFIX "mod")

target_compile_options(HelloWorld PRIVATE
        # clang / GCC
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall -Wextra -Wshadow -Weffc++>
        # MSVC
        $<$<CXX_COMPILER_ID:MSVC>:"/W4">
        )