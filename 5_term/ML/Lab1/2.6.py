import numpy as np


def sorted_arr(k):
    A = np.array([1.7, 8.2, 0.1, 3.15, 2.5])

    print(np.sort(A)[:k])


sorted_arr(4)
