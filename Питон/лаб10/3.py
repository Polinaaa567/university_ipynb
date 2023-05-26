import numpy as np

import pandas as pd

df = pd.read_csv('1.csv', delimiter=';',
                 names=['index', 'year', 'month', 'day', 'min_t', 'average_t', 'max_t', 'rainfall'])
print(df)

print()
# 2
df = df.drop(columns='index')
print(df)
print()

# 3
df.info()
print()

# есть пропущенные значения и больше всего в столбце rainfall

# 4
year_missing = df.groupby('year')['rainfall'].apply(lambda x: x.isnull().sum()).idxmax()
print(year_missing)

print()

# 5
df['Date'] = pd.to_datetime(df[['year', 'month', 'day']], format="%Y-%m-%d")
df = df.drop(columns=["month", "day"])
print(df)

print()

# 6
# print(df.info())
# print(df.dtypes.dtype)
columns_obj = df.dtypes[df.dtypes.map(lambda v: v == 'object')].index.values
# print("Это колонки object-type:", columns_obj)
tmp = df[columns_obj]
tmp = tmp.applymap(func=lambda v: v.strip())
tmp[tmp == ''] = np.nan
df[columns_obj] = tmp.astype(np.float32)
# print("sum: ", df[columns_obj].isna().sum())

df['range'] = df['max_t'] - df['min_t']
df['days_bez_rain'] = 0

for i in range(1, len(df)):
    if df.loc[i, 'rainfall'] == 0:
        df.loc[i, 'days_bez_rain'] = df.loc[i - 1, 'days_bez_rain'] + 1

print(df)
print()

# 7
max_zasuha = df['days_bez_rain'].max()
print(max_zasuha)

# 8
sredne_godovay = df.groupby('year')['average_t'].mean()
kol_vo_osadkov = df.groupby('year')['rainfall'].sum()
print(sredne_godovay)
print(kol_vo_osadkov)
# print(df)

# a
print('Very hot год = ', sredne_godovay.idxmax())
print('Very cold год = ', sredne_godovay.idxmin())

# b
print('Год где больше всего осадков = ', kol_vo_osadkov.idxmax())
print('Год где меньше всего осадков = ', kol_vo_osadkov.idxmin())

# 9
print(df[df['average_t'] < -40])
print(df[(df['average_t'] > 27) & (df['days_bez_rain'] > 3)])
