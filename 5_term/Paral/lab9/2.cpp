// Создайте следующую параллельную программу: на всех процессах
// задается одномерный массив (a[i]=rank, i=0...size-rank, который
// отправляется на 0-й процесс; 0-й процесс принимает от всех остальных
// пересылаемые данные. Например, Вы запускаете программу на 4-х
// процессах, 0-й процесс будет отправлять следующий массив (0,0,0…0),
// состоящий из size элементов, 1-й процесс отправляет 0-му следующий
// массив (1,1…1), состоящий из size-1 элемента, …, (size-1)-й процесс
// отправляет 0-му - (size-1), 0-й процесс получает данные и, сохраняя в
// одномерный массив, выводит на экран следующее: 0,…,0,1…1,…,(size-1).

#include <stdio.h>
#include "mpi.h"
#include "iostream"

using namespace std;

int main(int argc, char *argv[])
{
    int rank;
    int size;
    int n = 0;
    MPI_Status stat;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int *b = new int[size - rank];

    for (int i = 0; i < size - rank; i++)
        b[i] = rank;

    int *a = new int[size * (size + 1) / 2];

    int *bl = new int[size];
    int *ds = new int[size];

    ds[0] = 0;
    for (int i = 1; i < size; i++)
    {
        ds[i] = ds[i - 1] + size - i + 1;
    }
    for (int i = 0; i < size; i++)
    {
        bl[i] = size - i;
    }

    MPI_Gatherv(b, size - rank, MPI_INT, a, bl, ds, MPI_INT, 0, MPI_COMM_WORLD);

    double s = 0;
    for (int i = 0; i < rank * 1000000; i++)
        s += 0.0000000001;

    if (rank == 0)
    {
        printf("rank = %d, a: ", rank);
        for (int i = 0; i < size * (size + 1) / 2; i++)
            cout << a[i] << " ";
    }
    // printf( "rank = %d, a: ",rank );

    cout << endl;

    delete[] a;
    delete[] b;
    delete[] bl;
    delete[] ds;

    MPI_Finalize();
    return 0;
}
