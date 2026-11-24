cmake_minimum_required(VERSION 3.16)
project(c_sample_project C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(tasklib src/tasks.c)
target_include_directories(tasklib PUBLIC src)

add_executable(task_app src/main.c)
target_link_libraries(task_app tasklib)

enable_testing()
add_executable(test_tasks tests/test_tasks.c)
target_link_libraries(test_tasks tasklib)
add_test(NAME test_tasks COMMAND test_tasks)
