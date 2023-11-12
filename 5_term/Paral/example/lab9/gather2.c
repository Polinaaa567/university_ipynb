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

    int *b = new int[2];
    for (int i = 0; i < 2; i++)
        b[i] = rank;

    int *a = new int[2 * size];

    MPI_Gather(b, 2, MPI_INT, a, 2, MPI_INT, 0, MPI_COMM_WORLD);

    double s = 0;
    for (int i = 0; i < rank * 1000000; i++)
        s += 0.0000000001;

    printf("rank = %d, a: ", rank);
    for (int i = 0; i < 2 * size; i++)
        cout << a[i] << " ";

    cout << endl;

    delete[] a;
    delete[] b;

    MPI_Finalize();
    return 0;
}
