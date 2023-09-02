znak = " "
factorial = 1

print('Для выхода напишите x')
while (znak != 'x'):
    first = int(input())
    znak = input()
    if (znak == 'x'):
        print(first)
        break
    else:
        if (znak == '!' and first > 0):
            for i in range(1, first + 1):
                factorial *= i
            print("Ответ =", factorial)
        elif(znak == '!' and first < 0):
            print('Error')
        else:
            second = int(input())
            if (znak == '+'):
                print("Ответ =", first + second)
            elif (znak == '-'):
                print('Ответ =', first - second)
            elif (znak == '*'):
                print('Ответ =', first * second)
            elif (znak == '/'):
                if (first == 0 or second == 0):
                    print('Error')
                else:
                    print('Ответ =', first / second)
            elif (znak == "%"):
                if (first == 0 or second == 0):
                    print('Error')
                else:
                    print('Ответ =', first % second)
