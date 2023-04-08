# 9

class Triangle:
    def __init__(self, ab, bc, ca):
        self.ab = ab
        self.bc = bc
        self.ca = ca

    def perimeter(self):
        return self.ca + self.ab + self.bc


class EquilateralTriangle(Triangle):
    def __init__(self, line):
        super().__init__(line, line, line)


tr = EquilateralTriangle(6)
print(tr.perimeter())

tr2 = Triangle(1, 2, 3)
print(tr2.perimeter())

