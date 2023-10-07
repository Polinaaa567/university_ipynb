def solve_sudoku(matrix):
    # Поиск пустой клетки
    for row in range(4):
        for col in range(4):
            if matrix[row][col] == 0:
                for num in range(1, 5):
                    # Проверка возможных значений
                    if is_valid(matrix, row, col, num):
                        matrix[row][col] = num
                        # Рекурсивный случай
                        if solve_sudoku(matrix):
                            return True
                        # Отмена выбранного значения
                        matrix[row][col] = 0
                return False
    return True


def is_valid(matrix, row, col, num):
    # Проверка строки и столбца
    for i in range(4):
        if matrix[row][i] == num or matrix[i][col] == num:
            return False
    # Проверка квадрата 2x2
    start_row = row // 2 * 2
    start_col = col // 2 * 2
    for i in range(start_row, start_row + 2):
        for j in range(start_col, start_col + 2):
            if matrix[i][j] == num:
                return False
    return True


matrix = [
    [0, 0, 0, 0],
    [0, 0, 2, 0],
    [0, 1, 0, 0],
    [3, 0, 0, 4]
]

if solve_sudoku(matrix):
    for row in matrix:
        print(row)
else:
    print("Нет правильного решения")
