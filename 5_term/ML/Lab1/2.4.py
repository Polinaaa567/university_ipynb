import numpy as np

A = np.array([1, 2, 3, 4])

for i in range(1, 4):
    print(i, "Повторение\n", np.tile(A, i))
