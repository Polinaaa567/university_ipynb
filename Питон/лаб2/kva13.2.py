string = input()

if len(string) % 2 == 0:
    middle = len(string) // 2 - 1
    for i in range(middle):
        print(' ' * (middle - i) + string[middle - i] + ' ' * i * 2 + string[middle + i + 1])
    print(string[0], " " * (middle * 2 - 2), string[-1])
