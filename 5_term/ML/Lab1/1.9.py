import numpy as np

arr_1 = np.ones((4, 4), np.int8)
arr_1[4 % 2::2, ::2] = 0
arr_1[(4 + 1) % 2::2, 1::2] = 0

print(arr_1)
