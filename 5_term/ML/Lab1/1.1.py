import numpy as np

A = np.array([1, 7, 13, 105])

memory_size = A.nbytes
print("Размер памяти  массива", memory_size, "байт")

np.savetxt('A.txt', A)

np.save("A.npy", A)

loaded_txt = np.loadtxt("A.txt")
loaded_npy = np.load("A.npy")

print('Массив txt', loaded_txt)
print('Массив npy', loaded_npy)
