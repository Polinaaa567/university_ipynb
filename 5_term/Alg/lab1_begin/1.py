import timeit
import matplotlib.pyplot as plt


def foo(i):  # i - число
    digits = "0123456789"
    if i == 0:
        return "0"
    result = ""
    while i > 0:
        result = digits[i % 10] + result
        i = i // 10
    return result


plt_x = []
time = []
for i in range(10000, 100000, 10000):
    plt_x.append(i)
    time.append(timeit.timeit(
        f"foo({i})", number=5, globals=globals()))

plt.xlabel('Numbers')
plt.ylabel('Time')
plt.plot(plt_x, time)
plt.show()
