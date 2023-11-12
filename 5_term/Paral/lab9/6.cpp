// Модифицируйте предыдущий пример, осуществляя сохранение каждой
// строки, начиная с элемента на главной диагонали. Например, запустив
// программу на 5-и процессах, в итоге Вы должны получить следующую
// матрицу:

#include <stdio.h>
#include "mpi.h"
#include "iostream"

using namespace std;

int main(int argc, char *argv[])
{
    int rank;
    int size;
    int n = 0, i, j;
    MPI_Status stat;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int *b = new int[size - rank];
    for (i = 0; i < size - rank; i++)
        b[i] = rank;

    int **a = new int *[size];
    a[0] = new int[size * size];

    for (i = 1; i < size; i++)
        a[i] = a[i - 1] + size;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            a[i][j] = 0;

    int *bl = new int[size];
    int *ds = new int[size];

    for (int i = 0; i < size; i++)
    {
        bl[size - i - 1] = i + 1;
        ds[i] = i * size + i;
    }

    MPI_Gatherv(b, size - rank, MPI_INT, *a, bl, ds, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("rank = %d, a: \n", rank);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }

    delete[] a[0];
    delete[] a;
    delete[] b;

    delete[] bl;
    delete[] ds;

    MPI_Finalize();
    return 0;
}
