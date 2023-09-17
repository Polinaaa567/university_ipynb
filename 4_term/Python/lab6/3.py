class Selector:
    def __init__(self, value):
        self.value = value

    def get_odds(self):
        odds = []
        for i in self.value:
            if i % 2 != 0:
                odds.append(i)
        return odds

    def get_evens(self):
        evens = []
        for i in self.value:
            if i % 2 == 0:
                evens.append(i)
        return evens


values = [11, 12, 13, 14, 15, 16, 22, 44, 66]
selector = Selector(values)
odds = selector.get_odds()
evens = selector.get_evens()
print(' '.join(map(str, odds)))
print(' '.join(map(str, evens)))
