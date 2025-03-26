cmake_minimum_required(VERSION 3.14)
project(xtensor_example)
set(PYTHON_ROOT /opt/aurora/python38)
set(ENV_ROOT /data/ericoliang/vcpkg/packages)

set(CMAKE_PREFIX_PATH 
    "${PYTHON_ROOT}/lib/python3.8/site-packages/pybind11" 
    "${ENV_ROOT}/xtensor_x64-linux/share/xtensor" 
    "${ENV_ROOT}/xtl_x64-linux/share/xtl" 
    "${ENV_ROOT}/nlohmann-json_x64-linux/share/nlohmann_json" 
    ${CMAKE_PREFIX_PATH})

find_package(pybind11 REQUIRED)
find_package(xtensor CONFIG REQUIRED)
find_package(xtl CONFIG REQUIRED)
find_package(Python COMPONENTS Development REQUIRED)

pybind11_add_module(xtensor_example examples/xtensor_example.cpp)

target_include_directories(xtensor_example PRIVATE "${ENV_ROOT}/xtensor_x64-linux/include")
target_include_directories(xtensor_example PRIVATE "${ENV_ROOT}/xtl_x64-linux/include")
target_include_directories(xtensor_example PRIVATE "${ENV_ROOT}/xtensor-blas_x64-linux/include")
target_include_directories(xtensor_example PRIVATE "${PYTHON_ROOT}/include/python3.8")

# target_link_libraries(xtensor_example PRIVATE pybind11::module xt::xtensor)
