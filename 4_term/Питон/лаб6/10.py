class summator:
    def transform(self, n):
        return n

    def sum(self, N):
        summ = 0
        for i in range(N + 1):
            summ += self.transform(i)
        return summ


class squaresummator(summator):
    def __init__(self):
        pass

    def transform(self, n):
        return n ** 2


class cubesummator(summator):
    def __init__(self):
        pass

    def transform(self, n):
        return n ** 3


s1 = summator()
print(s1.sum(7))
s2 = squaresummator()
print(s2.sum(7))
s3 = cubesummator()
print(s3.sum(7))
