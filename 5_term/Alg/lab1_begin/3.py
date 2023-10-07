def t1(n):
    return n**2 - n - 10


def t2(n):
    return 4 * n + 40


for i in range(1000000):
    if t1(i) == t2(i):
        print(i)

