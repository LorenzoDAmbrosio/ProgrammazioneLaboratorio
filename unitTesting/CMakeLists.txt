cmake_minimum_required(VERSION 3.24)

set(GOOGLETEST_VERSION 1.9.0)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR})
set(SOURCE_TEST_FILES runAllTests.cpp usersTests.cpp chatTests.cpp)
add_executable(runTests ${SOURCE_TEST_FILES})
target_link_libraries(runTests gtest gtest_main core)