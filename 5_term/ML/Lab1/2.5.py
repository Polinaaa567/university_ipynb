from cmath import nan

import numpy as np

A = np.array([nan, 0, nan])

print(A[~np.isnan(A)])
