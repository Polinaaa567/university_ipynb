import numpy as np

a = np.arange(-2 * np.pi, 2 * np.pi)
b = np.sin(a) ** 2 + (np.cos(a) ** 2)
print(np.sum(b))
print(np.all(b == 1))
