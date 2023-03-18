person = {}


def add_friends(name_of_person, list_of_friends):
    if person.get(name_of_person):
        person[name_of_person] = person.get(name_of_person) + list_of_friends
    else:
        person[name_of_person] = list_of_friends


def are_friends(name_of_person1, name_of_person2):
    if name_of_person2 in person[name_of_person1]:
        return True
    return False


def print_friends(name_of_person):
    print(sorted(person[name_of_person]))


add_friends("Алла", ["Марина", "Иван"])
print(are_friends("Алла", "Никита"))
add_friends("Алла", ["Никита", "Антон", "Стас"])
print(are_friends("Алла", "Никита"))
print_friends("Алла")
