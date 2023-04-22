import numpy as np


def make_field(size):
    arr_1 = np.ones((size, size), np.int8)
    arr_1[size % 2::2, ::2] = 0
    arr_1[(size + 1) % 2::2, 1::2] = 0
    print(arr_1)


make_field(8)
