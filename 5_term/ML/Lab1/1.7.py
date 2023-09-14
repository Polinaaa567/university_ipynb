import numpy as np

Arr_square = np.zeros((10, 10))

Arr_square[[0, -1], :] = 1
Arr_square[:, [0, -1]] = 1

print(Arr_square)
