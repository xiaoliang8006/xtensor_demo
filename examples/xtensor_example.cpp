#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>
#include <xtensor/xrandom.hpp>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <xtensor-blas/xlinalg.hpp>

namespace py = pybind11;
using namespace xt;

// 使用xtensor进行矩阵乘法
xt::xtensor<double, 2> matrix_multiply(const xt::xtensor<double, 2>& a, const xt::xtensor<double, 2>& b) {
    return xt::linalg::dot(a, b);
}

// 将NumPy数组转换为xtensor数组
xt::xtensor<double, 2> numpy_to_xtensor(const py::array_t<double>& np_arr) {
    auto buf = np_arr.request();
    if (buf.ndim != 2) {
        throw std::runtime_error("Number of dimensions must be two");
    }
    // 使用正确的构造函数初始化xtensor
    xt::xtensor<double, 2> arr = xt::zeros<double>({buf.shape[0], buf.shape[1]});
    std::memcpy(arr.data(), buf.ptr, arr.size() * sizeof(double));
    return arr;
}


// 将xtensor数组转换为NumPy数组
py::array_t<double> xtensor_to_numpy(const xt::xtensor<double, 2>& arr) {
    auto result = py::array_t<double>(arr.shape());
    auto buf = result.request();
    std::memcpy(buf.ptr, arr.data(), arr.size() * sizeof(double));
    return result;
}

// 定义Python模块
PYBIND11_MODULE(xtensor_example, m) {
    m.def("matrix_multiply", &matrix_multiply, "Multiply two matrices using xtensor");
    
    // 为了方便，我们也可以直接暴露一个函数，接受NumPy数组并返回NumPy数组
    m.def("matrix_multiply_np", [](const py::array_t<double>& a, const py::array_t<double>& b) {
        auto a_xt = numpy_to_xtensor(a);
        auto b_xt = numpy_to_xtensor(b);
        auto result_xt = matrix_multiply(a_xt, b_xt);
        return xtensor_to_numpy(result_xt);
    }, "Multiply two matrices using xtensor (accepts and returns numpy arrays)");
}