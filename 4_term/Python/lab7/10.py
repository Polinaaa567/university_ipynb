import numpy as np

a11, a12, a21, a22, b1, b2 = map(int, input().split())

a = np.array([[a11, a12], [a21, a22]], dtype=int)
b = np.array([b1, b2], dtype=int)

if np.linalg.det(a) == 0:
    print('Нет решения')
else:
    print(np.linalg.solve(a, b))
