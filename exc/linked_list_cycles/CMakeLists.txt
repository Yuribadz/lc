cmake_minimum_required(VERSION 3.2)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Target creational
add_executable(linked_list_cycles linked_list_cycles.cpp)

find_program(VALGRIND "valgrind")
if(NOT VALGRIND)
    message(FATAL_ERROR "Valgrind not found")
endif()

# Create a custom target to run Valgrind
add_custom_target(run_valgrind
    COMMAND ${VALGRIND} --leak-check=full $<TARGET_FILE:linked_list_cycles>
    DEPENDS linked_list_cycles
    COMMENT "Running Valgrind linked_list_cycles"
)