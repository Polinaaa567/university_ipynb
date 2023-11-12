#include <stdio.h>
#include "mpi.h"
#include "iostream"

using namespace std;

int main(int argc, char *argv[])
{
    int rank;
    int size;
    int n = 0;
    // MPI_Status stat;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int *b = new int[3 * size];
    int *a = new int[3];

    for (int i = 0; i < 3; i++)
        a[i] = rank;

    MPI_Gather(a, 3, MPI_INT, b, 3, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("b: ");
        for (int i = 3; i < 3 * size; i++)
            cout << b[i] << " ";
    }

    cout << endl;

    delete[] a;
    delete[] b;

    MPI_Finalize();
    return 0;
}
