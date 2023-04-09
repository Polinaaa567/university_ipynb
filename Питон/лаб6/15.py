class Transformation:
    def __init__(self, numbers):
        self.numbers = numbers

    def new_action(self, command):
        if command == 'make_negative':
            for i in range(len(self.numbers)):
                number = int(self.numbers[i])
                if number > 0:
                    number *= -1
                self.numbers[i] = number

        elif command == 'square':
            for i in range(len(self.numbers)):
                number = int(self.numbers[i])
                number **= 2
                self.numbers[i] = number

        elif command == 'strange_command':
            for i in range(len(self.numbers)):
                number = int(self.numbers[i])
                if number % 5 == 0:
                    number += 1
                self.numbers[i] = number

        return self.numbers


numbers = input().split()
count = int(input())

for i in range(count):
    transformation = Transformation(numbers)
    command = input()
    numbers = transformation.new_action(command)

print(*numbers)
# 1 5 -2 0 30 -4
# 2
# square
# strange_command