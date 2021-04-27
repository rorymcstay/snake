cmake_minimum_required(VERSION 3.20)
project(snake)

add_compile_options(-DBOOST_LOG_DYN_LINK 
    -Wall -Wextra -Wpedantic  
    #-lboost_log -lpthread -lboost_log_setup -ljsoncpp 
    -std=c++20
    # required for clang
    -Wno-error=unused-command-line-argument
    -Wno-unused-command-line-argument
    -Wgcc-compat
)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package (Threads)

add_executable(snake src/snake.cpp)
target_link_libraries(snake pthread)

install(TARGETS
    snake
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
)
