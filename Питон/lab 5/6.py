def arithmetic_operation(operation):
    if operation == '+':
        return lambda a, b: a + b
    elif operation == '-':
        return lambda  a, b: a - b
    elif operation == '*':
        return lambda a, b: a * b
    elif operation == '/':
        return lambda a, b: a / b
    else:
        return lambda a, b: 0


operation = arithmetic_operation('+')
print(operation(1, 4))

operation = arithmetic_operation('-')
print(operation(1, 4))

operation = arithmetic_operation('*')
print(operation(1, 4))

operation = arithmetic_operation('/')
print(operation(1, 4))
