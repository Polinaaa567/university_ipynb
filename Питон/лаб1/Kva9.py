while True:
    firstparol = input("Введите пароль: ")
    secondparol = input("Введите пароль заново: ")
    if (len(firstparol) < 8):
        print("Короткий!")
    elif ("123" in firstparol):
        print("Простой!")
    elif (firstparol != secondparol):
        print("Различаются!")
    else:
        print("OK")
        break
