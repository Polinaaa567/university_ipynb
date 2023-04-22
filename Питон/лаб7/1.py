import numpy as np

arr_1 = np.empty([3, 4], dtype=int)
arr_1[...] = 3
print('1.a', arr_1, sep='\n')

# 1.b
arr_2 = np.random.randint(0, 10, (2, 4))
print('1.b', arr_2, sep='\n')

# 1.c
print('1.c', arr_1.size, arr_2.size, sep='\n')

# 1.d
array = np.concatenate((arr_1, arr_2), axis=0)
print('1.d', array, sep='\n')

# 1 e
arr_3 = np.array([1, 8, 6, 5, 8, 3])
print('1.c', arr_3, sep='\n')

# 1 f
arr_4 = arr_3 * 2 + 1
print('1.f', arr_4, sep='\n')

# 1 g
arr_5 = arr_3.reshape(2, 3)
print('1.g', arr_5, sep='\n')

# 1 h
print('1.h', np.min(arr_5, axis=1), sep='\n')

# 1 i
print('1.i', np.mean(arr_5), sep='\n')

# 1 j
arr_6 = np.arange(11) ** 2
print('1.j', arr_6, sep='\n')

# 1 k
print('1.k', arr_6[1:-1:2], sep='\n')

# 1 l
print('1.l', arr_6[::-1], sep='\n')

# 1 m
arr_6[1:-1:2] = 2
print('1.m', arr_6, sep='\n')

# 1 n
print('1.n', 49 in arr_6, sep='\n')

# 1 o
A = np.random.randint(-5, 5, (4, 4))

B = np.where(A < 0, A, 0)
print(B)
print('1.o', 'A:', A, 'B:', B, sep='\n')
