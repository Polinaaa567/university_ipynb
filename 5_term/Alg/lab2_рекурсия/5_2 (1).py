# 5.2
import turtle


# Задаем цвет для "листьев" и "дерева" для пункта 2
def branch_color(branchLen):
    if branchLen > 15:
        return "brown"
    else:
        return "green"


def tree(branchLen, t):
    if branchLen > 5:
        t.color(branch_color(branchLen))  # 2
        t.forward(branchLen)
        t.right(20)
        tree(branchLen - 15, t)
        t.left(40)
        tree(branchLen - 15, t)
        t.right(20)
        t.color(branch_color(branchLen))  # 2
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
