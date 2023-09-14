import numpy as np

# a) pow(x, 2) - 4 * x + 7

B = np.array([1, -4, 7])

print(np.roots(B))

# b) pow(x, 4) - 11* pow(x, 3) + 9*pow(x, 2) + 11*x -10

A = np.array([1, -11, 9, 11, -10])

print(np.roots(A))
