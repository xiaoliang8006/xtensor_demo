// xtensor version: 0.25.0
// g++ -std=c++14 -I/data/ericoliang/vcpkg/packages/xtensor_x64-linux/include -I/data/ericoliang/vcpkg/packages/xtl_x64-linux/include test.cpp -o test
#include <iostream>
#include <xtensor/xtensor.hpp>
#include <xtensor/xio.hpp>


int main() {
    std::cout << "xtensor version: " << XTENSOR_VERSION_MAJOR << "."
        << XTENSOR_VERSION_MINOR << "."
        << XTENSOR_VERSION_PATCH << std::endl;
    xt::xtensor<double, 2> a = {{1, 2}, {3, 4}};
    xt::xtensor<double, 2> b = {{5, 6}, {7, 8}};
    xt::xtensor<double, 2> c = a + b;
    std::cout << "Result:" << std::endl;
    // 使用范围-based for 循环打印元素
    for (const auto& elem : a) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}