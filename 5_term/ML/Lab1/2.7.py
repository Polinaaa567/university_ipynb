import numpy as np

A = np.array([0.5, 1.8, 2.1, 3.5, 4.87, 5.13, 6.49])
numbers = 3.09066280756759

print(A[np.abs(A - numbers).argmin()])
