class Transformation:
    def __init__(self):
        self.functions = {}

    def f_x(self, x):
        return x

    def sqrt_fun(self):
        return self.f_x(x) ** 0.5

    def define(self, name_f, f1, operator, f2):
        def f():
            if operator == '+':
                return f1() + f2()
            elif operator == '-':
                return f1() - f2()
            elif operator == '*':
                return f1() * f2()
            else:
                return f1() / f2()

        self.functions[name_f] = f()

    def calculate(self, f, *spisok):
        for i in spisok:
            self.functions[f](i)


n = int(input())
name_f = []
for i in range(n):
    string = input()
    string = string.split()
    if string[0] == 'define':
        name_f.append(string[1])
        x = string[2]
        operator = string[3]
        f2 = string[4]
        transformation = Transformation()
        transformation.define(name_f, x, operator, f2)

# 2
# calculate x -2 0 1 2
# calculate sqrt_fun 0 1 2 3 4
