def palindrome(s):
    string = ''.join(s.split())

    if len(string) % 2 == 0:
        first_part = string[:len(string) // 2]
        second_part = string[len(string) // 2:]
        second_part = second_part[::-1]

        if first_part == second_part:
            print("Палиндром")
        else:
            print("Не палиндром")
    else:
        first_part = string[:len(string) // 2].lower()
        second_part = string[len(string) // 2 + 1:].lower()
        second_part = second_part[::-1]

        if first_part == second_part:
            print("Палиндром")
        else:
            print("Не палиндром")


palindrome('1221')
palindrome('А роза упала на лапу Азора')
