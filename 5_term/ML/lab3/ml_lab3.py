import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# 1 . Создайте объект Series, значениями которого являются целые числа от 1 до 5, а индексами символы 'a', 'b', 'c', 'd', 'e'.

obj_Ser = pd.Series([1, 2, 3 , 4, 5], index=['a', 'b', 'c', 'd', 'e'])
obj_Ser

# 1.1 С помощью обращения по явному индексу получите значение 4.

obj_Ser['d']

# 1.2 С помощью обращения по неявному индексу получите значение 2.

obj_Ser[1]

# 1.3  Добавьте в серию новый элемент.

obj_Ser['f'] = 6
obj_Ser

# 1.4  Используя операцию среза, получите значения 3, 4, 5.

print(obj_Ser['c':'e'])

# 1.5  Создайте объект DataFrame из списка [[1, 2], [5, 3], [3.7, 4.8]] с именами столбцов col1 и col2.

obj_DF = pd.DataFrame([[1, 2], [5, 3], [3.7, 4.8]], columns=['col1', 'col2'])

obj_DF

# 1.6 Используя операцию индексации, получите элемент 3.7

obj_DF['col1'][2]

# 1.7 Измените элемент 3 на 9

obj_DF['col2'][1] = 9
print(obj_DF)

# 1.8 Используя операцию среза, получите строки с индексами 1 и 2.

obj_DF[1:4]

# 1.9 Добавьте столбец col3, значения которого – результат поэлементного перемножения col1 и col2.

obj_DF['col3'] = obj_DF['col1'] * obj_DF['col2']
obj_DF

# 2.1   На основе этого списка создайте датафрейм df так, чтобы каждому показателю (ru_name, en_name, class, cheer) 
# соответствовал один столбец датафрейма. Проверьте, что последний столбец является числовым. Если нет, приведите его к типу float

data = [["Вжик", "Zipper the Fly", "fly", "0.7"],
        ["Гайка", "Gadget Hackwrench", "mouse", None],
        ["Дейл", "Dale", "chipmunk", "1"],
        ["Рокфор", "Monterey Jack", "mouse", "0.8"],
        ["Чип", "Chip", "chipmunk", "0.2"]]

df = pd.DataFrame(data)
print(df)
print(df[3].dtype)

df[3] = df[3].astype(float)
print(df[3].dtype)

# 2.2 Выведите число строк датафрейма df.

len(df)

# 2.3  Выведите число заполненных (не NaN) ячеек в последнем столбце.

df[3].count()

# 2.4  Выведите значение в ячейке, которая находится на пересечении третьей строки и второго столбца

df.loc[2, 1]

# 2.5 Сохраните в переменную df1 строки датафрейма df со второй по четвертую включительно и столбцы с первого по третий включительно. Продемонстрируйте содержимое df1"""

df1 = df.iloc[1:4, 0:3]
df1

# 2.6 Присвойте столбцам датафрейма df следующие названия: ru_name, en_name, class, cheer"""

df.columns = ['ru_name', 'en_name', 'class', 'cheer']
df

# 2.7 Добавьте в датафрейм df столбец logcheer, который содержит логарифмированные значения cheer (если в cheer встречается NaN, то и в logcheer тоже)"""

df['logcheer'] = np.log(df['cheer'])
print(df)

# 2.8 Сохраните массив уникальных значений столбца class в переменную x, а соответствующие им частоты (сколько раз значение встречается в столбце) — в
# переменную y. Используя полученные x и y, постройте столбиковую диаграмму,
# barplot, для class. Добавьте заголовок и подписи к осям

x = df['class'].unique()
y = df['class'].value_counts()

plt.bar(x, y)
plt.title('Диаграмма')
plt.xlabel('Уникальные значения столбца class')
plt.ylabel('Частоты значений столбца class')

# 3.1 Загрузите случайную выборку из набора и далее работайте с ней:"""

df_la = pd.read_csv('csv/la-crimes-sample.csv',delimiter=',' )
df_la

# 3.2 Кол-во строк и столбцов

print('кол-во строк =', df_la.shape[0])
print('кол-во столбцов =', df_la.shape[1])

# 3.3 Названия столбцов и их типы данных"""

df_la.columns
df_la.dtypes

# 3.4 Сколько в каждом из них уникальных значений?"""

df_la.nunique()

# 3.5 Сколько пропущенных значений?"""

df_la.isnull().sum()

# 3.6 Верно ли, что женщины чаще оказываются жертвами по сравнению с мужчинами?

df_la['Victim Sex'] #Проверка, какие значения вообще там присутствуют

victim_M = df_la[df_la['Victim Sex'] == 'M'].shape[0]
victim_M

victim_F = df_la[df_la['Victim Sex'] == 'F'].shape[0]
victim_F

if victim_F > victim_M:
   print('Верно. Мужчин =', victim_M, 'Женщин =', victim_F)
else:
  print('Враньё. Мужчин =', victim_M, 'Женщин =', victim_F)

# 3.7 Определите 10 самых распространенных преступлений в Лос-Анджелесе. Постройте график."""

top = df_la['Crime Code Description'].value_counts()[:10]

top.plot(kind='barh')
plt.ylabel('Crime Code Description')
plt.xlabel('Частота')

# 3.8 От каких преступлений чаще страдают женщины, а от каких мужчины?"""

print('Преступления, от которых чаще страдают Мужчины')
victim_M = df_la[df_la['Victim Sex'] == 'M']['Crime Code Description'].value_counts().head(5)
print(victim_M)

print()

print('Преступления, от которых чаще страдают Женщины')
victim_F = df_la[df_la['Victim Sex'] == 'F']['Crime Code Description'].value_counts().head(5)
print(victim_F)

# 3.9 Люди какого происхождения чаще всего подвергаются преступлениям?

df_la['Victim Descent']

df_la['Victim Descent'].value_counts()
# происхождения H (Hispanic/Latin/Mexican)

# 3.10 Отсортируйте районы, по количеству преступлений. Постройте график, показывающий самые безопасный и опасный районы"""

print(df_la['Area Name'].value_counts())

df_la['Area Name'].value_counts().plot(kind='barh')
plt.title('От самого опасного района до самого безопасного')
plt.ylabel('Районы')
plt.xlabel('Кол-во преступлений')

# 4.1 Загрузите датафрейм из файла polit.csv и сохраните его в переменную polit. Если в датафрейме есть строки с пропущенными значениями, то удалите их."""

polit = pd.read_csv('csv/polit.csv', delimiter=',').dropna()
polit

# 4.2 Выберите в датафрейме строки, которые соответствуют странам со значениями индекса Freedom House (fh09) выше 5."""

polit[polit['fh09'] > 5.0]

# 4.3 Выберите в датафрейме строки, которые соответствуют странам Африки (afri) с процентом женщин в парламенте (fparl08) выше 30"""

polit[(polit['afri'] == 1) & (polit['fparl08'] > 30.0)]

# 4.4 Выберите в датафрейме строки, которые соответствуют странам Африки или Латинской Америки (afri и lati) со значением индекса Polity2 (polity09) больше или равным 8."""

polit[(polit['afri'] | polit['lati']) & (polit['polity09'] >= 8.0)]

# 4.5 Добавьте в датафрейм polit столбец corr_round, в котором будут храниться округленные до 2 знака после запятой значения индекса Control of Corruption (corr0509)."""

polit['corr_round'] = polit['corr0509'].round(2)
polit

# 4.6 Добавьте в датафрейм polit столбец fh_status, в котором будут храниться типы стран в зависимости от значения индекса Freedom House (значения free, partly free, not free)."""

def status(fh09):
  if fh09 >= 1 and fh09 <= 2.5:
    return 'free'
  elif fh09 >= 3.0 and fh09 <= 5.0:
    return 'partly free'
  elif fh09 >=5.5 and fh09 <= 7.0:
    return 'not free'
  else:
    return 'unknown'


polit["fh_status"] = polit["fh09"].apply(status)

polit[['fh09', 'fh_status']]

# 4.7 Сгруппируйте строки в таблице в соответствии со значениями столбца fh_status, полученного в предыдущей части и выведите минимальное, среднее и максимальное значение показателя gini (индекс Джини) по каждой группе."""

polit.groupby('fh_status').agg({'gini': ['min', 'mean', 'max']})

# 4.8 Сгруппируйте строки в таблице в соответствии со значениями столбца fh_status и запишите строки, относящиеся к разным группам, в отдельные csv-файлы"""

group_status = polit.groupby('fh_status')

for group, status in group_status:
  status.to_csv(f'csv/4.8/{group}.csv')

# 5 Используя набор данных Video Game Sales https://www.kaggle.com/gregorut/videogamesales:"""

vgs = pd.read_csv('csv/vgsales.csv', delimiter=',')
vgs

# 5.1 Вывести все доступные платформы, на которых выпускалась хотя-бы одна игра"""

vgs['Platform'].unique()

# 5.2. Добавить к копии набора данных столбец metacritic_rating и заполнить его данными из набора данных Metacritic all time games stats (https://www.kaggle.com/skateddu/metacritic-all-time-games-stats)"""

data = pd.read_csv('csv/metacritic_games.csv', usecols=["name", "platform", "rating"])
data.rename(columns={"name": "Name", "platform": "Platform",
                     "rating": "Metacritic_rating"}, inplace=True)
vgs_copy = vgs.copy()
vgs_copy = vgs_copy.merge(data)

vgs_copy

#5.3 Вывести список игр, рейтинг которых равен "M" и год издания не ранее 2012 года;"""

vgs_copy2 = vgs_copy[(vgs_copy['Metacritic_rating'] == 'M') & (vgs_copy['Year'] >= 2012)]
vgs_copy2

#5.4 Рассчитать и вывести описательные статистики для списка, полученного в предыдущем пункте;"""

vgs_copy2.describe()

#5.5 Вывести жанры игр с количеством игр, которые принадлежат соответствующему жанру в виде "<жанр> - <количество игр>" для всех жанров, которые содержат в своем названии не менее 3 различных гласных"""

def count(word):
  vowels = ['a', 'o', 'e', 'i', 'u', 'y']
  count = 0
  for symbol in word.lower():
    if symbol in vowels:
      count += 1
  return count


vgs['vowel count'] = vgs['Name'].apply(count)
filter_list = vgs[vgs['vowel count'] >= 3]['Genre'].value_counts()
filter_list

# 6.1 На сайте http://aisori-m.meteo.ru/waisori/index0.xhtml можно получить информацию метеорологических наблюдений по выбранному городу. Скачайте информацию о каком-нибудь городе и выполните следующие задания. Пример того как выглядят данные для города Барнаул: https://cloud.mail.ru/public/kHoj/oHpFCipkg.
# 1. Загрузите данные из файла в объект DataFrame, Добавьте заголовки к столбцам: «index», «year», «month», «day», «min_t», «average_t», «max_t», «rainfall».
# Расшифровка:
# • index – индекс ВМО,
# • year – год,
# • month – месяц,
# • day – день,
# • min_t – минимальная температура воздуха,
# • average_t – средняя температура воздуха,
# • max_t – максимальная температура воздуха,
# • rainfall – количество осадков.

meteo_df = pd.read_csv('csv/wr88125.txt', delimiter=';',
                   names=['index', 'year', 'month', 'day',
                          'min_t', 'average_t', 'max_t', 'rainfall'])

num_cols = ["min_t", "average_t", "max_t", "rainfall"]

meteo_df[num_cols] = meteo_df[num_cols].apply(lambda x: pd.to_numeric(x.str.strip()))
meteo_df

# 6.2 Удалите столбец index."""

meteo_df = meteo_df.drop(columns='index')
meteo_df

# 6.3 Используя метод info(), oтветьте на вопросы:
# Есть ли в данных пропущенные значения?
# B каком столбце данных больше всего пропущенных значений?

meteo_df.info()

# """Есть пропущенные и больше всего в 'max_t'"""

meteo_df.count().idxmin()

# """6.4 В данных за какой год больше всего пропусков?"""

year_missing = meteo_df.groupby('year')['rainfall'].apply(lambda x:
x.isnull().sum()).idxmax()

year_missing

# """6.5 Объедините столбцы «Год», «Месяц» и «День» в один столбец «Дата» в формате
# гггг-мм-дд (2000-01-20). Данные в новом столбце должны иметь формат datetime;

meteo_df['Date'] = pd.to_datetime(meteo_df[['year', 'month', 'day']],
format="%Y-%m-%d")
meteo_df = meteo_df.drop(columns=["month", "day"])

meteo_df

# """6.6 Для каждого наблюдения рассчитайте размах температур (разность максимальной и минимальной суточных температур) и количество предшествующих ему дней без осадков (используйте циклы Python и условный оператор)"""

meteo_df['range'] = meteo_df['max_t'] - meteo_df['min_t']
meteo_df['days_bez_rain'] = 0

for i in range(1, len(meteo_df)):
  if meteo_df.loc[i, 'rainfall'] == 0:
    meteo_df.loc[i, 'days_bez_rain'] = meteo_df.loc[i - 1, 'days_bez_rain'] + 1

meteo_df

# """6.7 Определите самый длинный период засухи."""

meteo_df['days_bez_rain'].max()

# """6.8 Для каждого года вычислите среднегодовую температуру и общее количество
# осадков. Запишите результаты в объекты Series.
# Какой год можно считать самым теплым? Какой самым холодным?
# В какой год выпало больше всего осадков? В какой меньше всего?

sredne_godovay = meteo_df.groupby('year')['average_t'].mean()
kol_vo_osadkov = meteo_df.groupby('year')['rainfall'].sum()
type(sredne_godovay)

print('Very hot год = ', sredne_godovay.idxmax())
print('Very cold год = ', sredne_godovay.idxmin())

print('Год где больше всего осадков = ', kol_vo_osadkov.idxmax())
print('Год где меньше всего осадков = ', kol_vo_osadkov.idxmin())

# 6.9 Выведете наблюдения, удовлетворяющие условиям:

#  Средняя температура воздуха ниже -30 (для некоторых регионов можно использовать -10, -35 или -40).

#  Средняя температура воздуха выше 27 и количество дней без осадков больше 3.

print(meteo_df[meteo_df['average_t'] < -30])

print(meteo_df[(meteo_df['average_t'] > 27) & (meteo_df['days_bez_rain'] > 3)])