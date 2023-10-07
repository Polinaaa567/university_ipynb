# 5.3

import turtle
# Импортируем рандом для произвольного выбора углов для пункта 3
import random


def tree(branchLen, t):
    if branchLen > 5:
        angle = random.randint(15, 45)  # 3
        t.forward(branchLen)
        t.right(angle)  # 3
        tree(branchLen - 15, t)
        t.left(angle * 2)  # 3
        tree(branchLen - 15, t)
        t.right(angle)  # 3
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
