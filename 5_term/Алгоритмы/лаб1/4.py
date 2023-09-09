import timeit
import matplotlib.pyplot as plt

test_in_x = timeit.Timer("del ", globals=globals())

plt_x = []
list_test = []
spisok_test = []

for i in range(1000000, 10000001, 1000000):
    plt_x.append(i)

    x = list(range(i))
    time = test_in_x.timeit(number=5)
    list_test.append(time)

    x = set(range(i))
    pz = test_in_x.timeit(number=5)
    spisok_test.append(pz)

    print("%15.2f, %15.5f" % (pz, time))

plt.plot(plt_x, list_test, plt_x, spisok_test)
plt.show()
