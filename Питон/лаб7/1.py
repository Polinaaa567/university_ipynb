import numpy as np

arr_1 = np.empty([3, 4], dtype=int)
arr_1[...] = 3
print(arr_1)

# 1.b
arr_2 = np.random.randint(0, 10, (2, 4))

print(arr_2)
# 1.c
print(arr_1.size, arr_2.size)
# 1.d
array = np.concatenate((arr_1, arr_2), axis=0)
print(array)
# 1 e
arr_3 = np.array([1, 8, 6, 5, 8, 3])
print(arr_3)
# 1 f
arr_4 = arr_3 * 2 + 1
print(arr_4)
# 1 g
arr_5 = arr_3.reshape(2, 3)
print(arr_5)
# 1 h
print('bnfkbn')
print(np.min(arr_5, axis=1))
# 1 i
print('bnfkbn')
print(np.mean(arr_5))
# 1 j
arr_6 = np.arange(11) ** 2
print(arr_6)
# 1 k
print(arr_6[1:-1:2])
# 1 l
print(arr_6[::-1])
# 1 m
arr_6[1:-1:2] = 2
print(arr_6)
# 1 n
print(49 in arr_6)
# 1 o
A = np.random.randint(-5, 5, (4, 4))
print(A)

B = np.where(A < 0, A, 0)
print(B)
