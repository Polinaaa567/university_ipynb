class SparseArray:
    def __init__(self):
        self.arr = {}

    def __getitem__(self, item):
        return self.arr.get(item, 0)

    def __setitem__(self, item, value):
        self.arr[item] = value


arr = SparseArray()
arr[1] = 10
arr[8] = 20
for i in range(10):
    print('arr[{}] = {}'.format(i, arr[i]))
