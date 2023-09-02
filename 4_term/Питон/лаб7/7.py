import numpy as np

a = np.ones((4, 1, 3))
b = np.ones((12, 1))

c = a * b

print(c.shape)
