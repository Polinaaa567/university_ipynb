import turtle


def snowflake(length, depth):
    if depth == 0:
        turtle.forward(length)
        return
    length /= 3.0
    snowflake(length, depth - 1)
    turtle.left(60)
    snowflake(length, depth - 1)
    turtle.right(120)
    snowflake(length, depth - 1)
    turtle.left(60)
    snowflake(length, depth - 1)


turtle.speed(0)
turtle.up()
turtle.goto(-200, 0)
turtle.down()
for i in range(3):
    snowflake(400, 4)
    turtle.right(120)

turtle.done()
