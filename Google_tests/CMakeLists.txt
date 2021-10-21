cmake_minimum_required(VERSION 3.14)

add_subdirectory(./lib/googletest-master)
set(gtest_SOURCE_DIR, ./lib/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES NumbersFixture.cpp runAllTests.cpp NumbersTests.cpp MatrixTests.cpp)
add_executable(runGoogleTests ${TEST_SOURCE_FILES})
target_link_libraries(runGoogleTests gtest gtest_main)