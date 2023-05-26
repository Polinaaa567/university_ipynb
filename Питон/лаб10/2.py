import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

data = [["Вжик", "Zipper the Fly", "fly", "0.7"],
        ["Гайка", "Gadget Hackwrench", "mouse", None],
        ["Дейл", "Dale", "chipmunk", "1"],
        ["Рокфор", "Monterey Jack", "mouse", "0.8"],
        ["Чип", "Chip", "chipmunk", "0.2"]]

df = pd.DataFrame(data)
# df = pd.DataFrame(data, columns=['ru_name', 'en_name', 'class', 'cheer'])
print(df[3].dtype)
df[3] = df[3].astype(float)

print(df)
print(df[3].dtype)

# 2
print(len(df))

# 3
print(df[3].count())

# 4
print(df.loc[2, 1])

# 5
df1 = df.iloc[1:4, 0:3]
print(df1)

print()

# 6
df.columns = ['ru_name', 'en_name', 'class', 'cheer']
print(df)

print()

# 7
df['logeheer'] = np.log(df['cheer'])
print(df)

# 8
x = df['class'].unique()
y = df['class'].value_counts()

plt.bar(x, y)
plt.title('Столбиковая диаграмма')
plt.xlabel('уникальные значения столбца class')
plt.ylabel('частоты')
plt.show()
