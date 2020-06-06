cmake_minimum_required(VERSION 3.10.2)
project(Graph)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")


set(SOURCE_FILES main.cc)
set(TEST_FILES test_target.cc)
set(BOOST_EXAMPLE_FILES boost_example.cc)

# llvm example
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

find_package(Threads)

# gtest example
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# boost example
find_package(Boost COMPONENTS thread REQUIRED) # 要求thread库, otherwise link phase would be error
link_directories(${Boost_LIBRARY_DIRS})


# opencv example
find_package(OpenCV REQUIRED)   
include_directories(${OpenCV_INCLUDE_DIRS})

message(STATUS "This is BINARY dir" ${PROJECT_BINARY_DIR})
message(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")



# llvm example
add_executable(hello-world ${SOURCE_FILES})
## https://stackoverflow.com/questions/11933485/building-llvm-example
llvm_map_components_to_libnames(llvm_libs support core irreader nativecodegen support  ExecutionEngine Interpreter)
target_link_libraries(hello-world ${llvm_libs})


# gtest example
add_executable(test_target ${TEST_FILES})
target_link_libraries(test_target
        ${GTEST_BOTH_LIBRARIES}
        pthread )
gtest_discover_tests(test_target)


# booost example BOOST_EXAMPLE_FILES
add_executable(boost_example ${BOOST_EXAMPLE_FILES})
target_link_libraries(boost_example -lboost_system ${Boost_LIBRARIES} Threads::Threads)