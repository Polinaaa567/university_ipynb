import numpy as np

A = np.array([10, 10, 20, 10, 20, 20, 20, 30, 30, 50, 40, 40])

unique, frequencies = np.unique(A, return_counts=True)

print(unique)
print(frequencies)
