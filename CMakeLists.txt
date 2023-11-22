cmake_minimum_required(VERSION 3.19)
project(ProgrammazioneLaboratorio)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProgrammazioneLaboratorio main.cpp Observer.h ChatRegister.cpp ChatRegister.h Subject.h User.cpp User.h Chat.cpp Message.cpp Message.h
        Chat.h
)