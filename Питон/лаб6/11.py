class summator:
    def transform(self, n):
        return n

    def sum(self, N):
        summ = 0
        for i in range(N + 1):
            summ += self.transform(i)
        return summ


class PowerSummator(summator):
    def __init__(self, b):
        self.b = b

    def transform(self, n):
        return n ** self.b


class squaresummator(PowerSummator):
    def __init__(self):
        super().__init__(2)


class cubesummator(PowerSummator):
    def __init__(self):
        super().__init__(3)


s1 = summator()
print(s1.sum(7))
s2 = squaresummator()
print(s2.sum(7))
s3 = cubesummator()
print(s3.sum(7))
s4 = PowerSummator(5)
print(s4.sum(7))
