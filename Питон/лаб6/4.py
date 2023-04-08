# 4

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __eq__(self, other):
        return other.x == self.x and other.y == self.y


p1 = Point(1, 2)
p2 = Point(5, 6)

if p1 == p2:
    print('Equal True')
else:
    print('Equal False')

if p1 != p2:
    print('Not equal True')
else:
    print('Not equal False')
