import timeit
import matplotlib.pyplot as plt

test_in_x = timeit.Timer("'test' in x", globals=globals())

plt_x = []
list_test = []
set_test = []

for i in range(1000000, 10000001, 1000000):
    plt_x.append(i)

    x = list(range(i))
    time = test_in_x.timeit(number=5)
    list_test.append(time)

    x = set(range(i))
    pz = test_in_x.timeit(number=5)
    set_test.append(pz)

    print("%15.2f, %15.5f" % (pz, time))

plt.xlabel('Numbers')
plt.ylabel('Time')
plt.plot(plt_x, list_test, label='list_test')
plt.plot(plt_x, set_test, label='set_test')
plt.legend()

plt.show()
