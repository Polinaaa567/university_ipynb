import math


class Weapon:  # оружие
    def __init__(self, name, damage, range):
        self.name = name
        self.damage = damage
        self.range = range

    def hit(self, actor, target):  # удар, target - препятствие, ну или злодей
        if target.is_alive():
            if math.sqrt((target.pos_x - actor.pos_x) ** 2 + (target.pos_y - actor.pos_y) ** 2) > self.range:
                print(f'Ох, враг слишком далеко для оружия {self.name}')
            else:
                print(f'Врагу нанесен урон оружием {self.name} в размере {self.damage}')
                target.hp -= self.damage
        #             между врагом и человеком есть расстояние....
        #             рассчитать можно через теорему пифагора их расстояние друг от друга...
        #             наверное...
        else:
            print('Враг уже повержен')

    def __str__(self):
        return self.name


class BaseCharacter:  # базовые персонажи
    def __init__(self, pos_x, pos_y, hp):
        self.pos_x = pos_x
        self.pos_y = pos_y
        self.hp = hp

    def move(self, delta_x, delta_y):  # Передвижение
        self.pos_x += delta_x
        self.pos_y += delta_y

    def is_alive(self):
        if self.hp > 0:
            return True
        else:
            return False

    def get_damage(self, amount):  # в каком размере
        if self.is_alive():
            self.hp -= amount

    def get_coords(self):
        return self.pos_x, self.pos_y


class BaseEnemy(BaseCharacter):
    def __init__(self, pos_x, pos_y, weapon, hp):
        super().__init__(pos_x, pos_y, hp)
        self.weapon = weapon

    def hit(self, target):
        if isinstance(target, MainHero):
            self.weapon.hit(self, target)
        else:
            print('Могу ударить только Главного героя')

    def __str__(self):
        return f'Враг на позиции ({self.pos_x}, {self.pos_y}) с оружием {self.weapon}'


class MainHero(BaseCharacter):
    def __init__(self, pos_x, pos_y, name, hp):
        super().__init__(pos_x, pos_y, hp)
        self.name = name
        self.weapons = []
        self.current_weapon = 0

    def hit(self, target):
        if self.weapons:
            if isinstance(target, BaseEnemy):
                self.weapons[self.current_weapon].hit(self, target)
            else:
                print('Могу ударить только Главного героя')
        else:
            print('Я безоружен')

    def add_weapon(self, weapon):
        if isinstance(weapon, Weapon):
            self.weapons.append(weapon)
            print(f'Подобрал {weapon}')
        else:
            print('Это не оружие')

    def next_weapon(self):
        if len(self.weapons) == 1:
            print('У меня только одно оружие')
        elif len(self.weapons) > 1:
            self.current_weapon += 1
            if self.current_weapon == len(self.weapons):
                self.current_weapon = 0
            print(f'Сменил оружие на {self.weapons[self.current_weapon]}')
        else:
            print('Я безоружен')

    def heal(self, amount):
        if self.hp < 200:
            self.hp += amount
            print(f'Полечился, теперь здоровья {self.hp}')


weapon1 = Weapon("Короткий меч", 5, 1)
weapon2 = Weapon("Длинный меч", 7, 2)
weapon3 = Weapon("Лук", 3, 10)
weapon4 = Weapon("Лазерная орбитальная пушка", 1000, 1000)
princess = BaseCharacter(100, 100, 100)
archer = BaseEnemy(50, 50, weapon3, 100)
armored_swordsman = BaseEnemy(10, 10, weapon2, 500)
archer.hit(armored_swordsman)
armored_swordsman.move(10, 10)
print(armored_swordsman.get_coords())
main_hero = MainHero(0, 0, "Король Артур", 200)
main_hero.hit(armored_swordsman)
main_hero.next_weapon()
main_hero.add_weapon(weapon1)
main_hero.hit(armored_swordsman)
main_hero.add_weapon(weapon4)
main_hero.hit(armored_swordsman)
main_hero.next_weapon()
main_hero.hit(princess)
main_hero.hit(armored_swordsman)
main_hero.hit(armored_swordsman)
