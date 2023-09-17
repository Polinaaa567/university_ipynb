import numpy as np

X = np.array([[-3, 4, 1], [4, 3, 1]])
y = np.array([10, 12])
I = np.eye(3)
lymbda = 0.1

print(np.linalg.inv(np.transpose(X) @ X + lymbda * I) @ np.transpose(X) @ y)
