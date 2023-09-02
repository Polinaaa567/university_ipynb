text = ''


def print_without_duplicates(message):
    global text
    if message != text:
        print(message)
    text = message


print_without_duplicates('Привет')
print_without_duplicates('Привет')
print_without_duplicates('Не могу до тебя дозвониться')
print_without_duplicates('Не могу до тебя дозвониться')
print_without_duplicates('Не могу до тебя дозвониться')
print_without_duplicates('Когда доедешь до дома')
print_without_duplicates('Ага, жду')
print_without_duplicates('Ага, жду')
