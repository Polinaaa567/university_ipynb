import pandas as pd
import numpy as np

# 1
example1 = pd.Series(np.arange(1, 6), index=['a', 'b', 'c', 'd', 'e'])
print(example1)

# 1
print(example1['d'])
#
# 2
print(example1.b)

# 3
example1['f'] = 6
print(example1)

# 4
print(example1['c':'e'])

# 5
example2 = pd.DataFrame([[1, 2], [5, 3], [3.7, 4.8]], columns=['col1', 'col2'])
print(example2)
# нужен шттипи сервер или аппатч, вижуал студио

# 6
print(example2.at[2, 'col1'])

# 7
example2.at[1, 'col2'] = 9.0
print(example2)

# 8
print(example2[1:4])

# 9
example2['col3'] = example2['col1'] * example2['col2']
print(example2)
