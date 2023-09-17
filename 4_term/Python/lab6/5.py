class ReversedList:
    def __init__(self, lst):
        self.lst = lst[::-1]

    def __getitem__(self, item):
        return self.lst[item]

    def __len__(self):
        return len(self.lst)


r1 = ReversedList([10, 20, 30])

for i in range(len(r1)):
    print(r1[i])

r2 = ReversedList([])
print(f'r2 len = {len(r2)}')

r3 = ReversedList([10])
print(f'r3 len = {len(r3)}')
print(r3[0])
