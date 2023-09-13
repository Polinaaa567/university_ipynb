import timeit
import matplotlib.pyplot as plt

test_del_x = timeit.Timer("del x[0]", globals=globals())

plt_x = []
list_test = []
map_test = []

for i in range(1000000, 10000001, 1000000):
    plt_x.append(i)

    x = list(range(i))
    time = test_del_x.timeit(number=1)
    list_test.append(time)

    x = {x: i for x in range(i)}
    pz = test_del_x.timeit(number=1)
    map_test.append(pz)

    print("%15.2f, %15.5f" % (pz, time))

plt.plot(plt_x, list_test, plt_x, map_test)
plt.show()

