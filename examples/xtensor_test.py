import numpy as np
import xtensor_example

# 创建两个NumPy数组
a = np.array([[5, 2], [3, 4]], dtype=np.float64)
b = np.array([[5, 6], [7, 8]], dtype=np.float64)

# 使用xtensor进行矩阵乘法
result = xtensor_example.matrix_multiply_np(a, b)

print("Result of matrix multiplication:")
print(result)