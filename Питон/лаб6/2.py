# 2

class Balance:
    def __init__(self):
        self.number_left = 0
        self.number_right = 0

    def add_right(self, number):
        self.number_right += number

    def add_left(self, number):
        self.number_left += number

    def result(self):
        if self.number_right == self.number_left:
            return "="

        elif self.number_right > self.number_left:
            return "R"

        return "L"


balance = Balance()
balance.add_right(10)
balance.add_left(9)
balance.add_left(2)
print(balance.result())