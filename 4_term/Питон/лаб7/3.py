import numpy as np


def super_sort(rows, cols):
    A = np.random.randint(0, 101, (rows, cols))
    B = np.copy(A)
    B[:, ::2] = np.sort(B[:, ::2], axis=0)
    B[:, 1::2] = -np.sort(-B[:, 1::2], axis=0)
    print(A, B, sep='\n')


super_sort(7, 5)
