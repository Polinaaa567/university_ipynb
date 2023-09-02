ooo = []

for i in range(int(input())):
    who = input()

    if who.find("Кто последний?") != -1:
        ooo.append(who[19: len(who) - 1])
    if who.find("Я только спросить!") != -1:
        ooo.insert(0, who[23:len(who) - 1])
    if "Следующий" in who:
        if ooo:
            print(f"Заходит {ooo.pop(0)}!")
        else:
            print("В очереди никого нет")