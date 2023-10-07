# 5.4

import turtle
# Импортируем рандом для изменения рекурсивной части branchLen для пункта 4 (мной взять диапазон от 5 до 20)
import random


def tree(branchLen, t):
    if branchLen > 5:
        t.forward(branchLen)
        t.right(20)
        tree(branchLen - random.randint(5, 20), t)  # 4
        t.left(40)
        tree(branchLen - random.randint(5, 20), t)  # 4
        t.right(20)
        t.backward(branchLen)


def main():
    t = turtle.Turtle()
    myWin = turtle.Screen()
    t.left(90)
    t.up()
    t.backward(100)
    t.down()
    t.color("green")
    tree(75, t)
    myWin.exitonclick()


main()
