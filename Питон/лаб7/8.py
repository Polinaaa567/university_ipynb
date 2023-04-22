import numpy as np

n, m = 2, 3
A = np.random.randint(0, 10, (n, m), dtype=int)
B = np.random.randint(0, 10, (m), dtype=int)
C = np.random.randint(0, 10, (m, n), dtype=int)
D = np.random.randint(0, 10, (m), dtype=int)

print(5 * A @ B + np.transpose(C) @ D)
