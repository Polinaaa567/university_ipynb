import numpy as np

a = np.arange(-2 * np.pi, 2 * np.pi)

sum = np.sum(np.sin(a)**2 + np.cos(a) **2)
print(sum)
print(np.all(sum))
