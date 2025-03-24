cmake_minimum_required(VERSION 3.14)
project(xtensor_example)


set(CMAKE_PREFIX_PATH 
    "/opt/aurora/python38/lib/python3.8/site-packages/pybind11" 
    "/data/ericoliang/vcpkg/packages/xtensor_x64-linux/share/xtensor" 
    "/data/ericoliang/vcpkg/packages/xtl_x64-linux/share/xtl" 
    "/data/ericoliang/vcpkg/packages/nlohmann-json_x64-linux/share/nlohmann_json" 
    ${CMAKE_PREFIX_PATH})

find_package(pybind11 REQUIRED)
find_package(xtensor CONFIG REQUIRED)
find_package(xtl CONFIG REQUIRED)
find_package(Python COMPONENTS Development REQUIRED)

pybind11_add_module(xtensor_example xtensor_example.cpp)

target_include_directories(xtensor_example PRIVATE "/data/ericoliang/vcpkg/packages/xtensor_x64-linux/include")
target_include_directories(xtensor_example PRIVATE "/data/ericoliang/vcpkg/packages/xtl_x64-linux/include")
target_include_directories(xtensor_example PRIVATE "/data/ericoliang/vcpkg/packages/xtensor-blas_x64-linux/include")
target_include_directories(xtensor_example PRIVATE "/opt/aurora/python38/include/python3.8")

# target_link_libraries(xtensor_example PRIVATE pybind11::module xt::xtensor)
