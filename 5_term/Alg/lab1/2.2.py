import timeit
import matplotlib.pyplot as plt


def algoritm1(item):
    uniq_dict = {}
    for x in item:
        if x in uniq_dict:
            return False
        uniq_dict[x] = True
    return True


def algoritm2(item):
    uniq_lst = []
    for x in item:
        if x in uniq_lst:
            return False
        uniq_lst.append(x)
    return True


plt_x = []
time1 = []
time2 = []

for i in range(1000, 10001, 1000):
    plt_x.append(i)
    lst = list(range(i))

    time1.append(timeit.timeit(
        f"algoritm1({lst})", number=5, globals=globals()))

    time2.append(timeit.timeit(
        f"algoritm2({lst})", number=5, globals=globals()))

plt.xlabel('Numbers')
plt.ylabel('Time')
plt.plot(plt_x, time1, label='Algoritm1 - {}')
plt.plot(plt_x, time2, label='Algoritm2 - []')
plt.legend()
plt.show()
