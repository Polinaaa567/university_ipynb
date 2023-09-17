import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import seaborn as sb

# 2 and 3
x= np.linspace(0, 10,50)

# y = x
#
# plt.title("Линейная зависимость  y=x")
# plt.xlabel('x')
# plt.ylabel('y')
# plt.grid()
# # plt.plot(x, y)
# # plt.show()
#
# # 3
# plt.plot(x, y, "r--")
# plt.show()

# 4

y1 = x
y2 = [i**2 for i in x]

plt.title("Линейная зависимость  y1=x, y2 = x**2")
plt.xlabel('x')
plt.ylabel('y1, y2')
plt.grid()
plt.plot(x, y1, x, y2)
plt.show()

# 5
# df = sb.load_dataset('titanic')
# sb.barplot(x='sex', y='survived', hue='class', data=df)
# plt.show()

# kva ku-ka-re-ku beeeee fuuuu muuuuu
# hochu domoy