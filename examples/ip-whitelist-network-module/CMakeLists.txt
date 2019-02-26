cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)


include_directories(../../interfaces)

set(SRC IpWhiteListModule.cpp IpWhiteListModule.hpp)

add_library(IpWhiteList SHARED ${SRC})

set_target_properties(IpWhiteList PROPERTIES PREFIX "mod")

target_compile_options(IpWhiteList PRIVATE
        # clang / GCC
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall -Wextra -Wshadow -Weffc++>
        # MSVC
        $<$<CXX_COMPILER_ID:MSVC>:"/W4">
        )