cmake_minimum_required(VERSION 3.24)
project(ProgrammazioneLaboratorio)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(unitTesting)
set(SOURCE_FILES Observer.h ChatRegister.cpp ChatRegister.h Subject.h User.cpp User.h Chat.cpp Message.cpp Message.h Chat.h)

add_executable(ProgrammazioneLaboratorio main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ProgrammazioneLaboratorio core)