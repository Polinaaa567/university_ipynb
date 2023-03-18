def transpose(matrix):
    n = len(matrix)
    m = len(matrix[0])
    return [[matrix[i][j] for i in range(n)] for j in range(m)]


matrix = [[1, 2], [3, 4], [5, 6]]
for line in transpose(matrix):
    print(*line)
