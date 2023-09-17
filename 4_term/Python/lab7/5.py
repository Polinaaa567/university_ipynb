import timeit
import numpy as np

arr_1 = np.random.randint(0, 10, (100, 100))
arr_2 = np.random.randint(0, 10, (100, 100))


def mult():
    n = len(arr_1)
    arr_3 = [[0 for i in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                arr_3[i][j] += arr_1[i][k] * arr_2[k][j]
    return arr_3


def el_mult():
    n = len(arr_1)
    arr_3 = [[0 for i in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            arr_3[i][j] = arr_1[i][j] * arr_2[i][j]
    return arr_3


def np_mult():
    return arr_1 @ arr_2


def np_el_mult():
    return np.multiply(arr_1, arr_2)


start_time = timeit.default_timer()
mult()
print('mult()', timeit.default_timer() - start_time)

start_time = timeit.default_timer()
np_mult()
print('np_mult()', timeit.default_timer() - start_time)

start_time = timeit.default_timer()
el_mult()
print('el_mult()', timeit.default_timer() - start_time)

start_time = timeit.default_timer()
np_el_mult()
print('np_el_mult()', timeit.default_timer() - start_time)
