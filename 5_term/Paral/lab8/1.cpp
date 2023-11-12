#include <stdio.h>
#include "mpi.h"
#include <cmath>
#include "windows.h"

int ourBcast (void* buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm) 
{
    int rank, size, _rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status stat;
    
    if (root >= size)
	{
		return -1;
	}

	if (rank >= root)
	{
		_rank = rank - root;
	}

    else
	{
		_rank = rank - root + size;
	}
    if(rank != root) 
    {
        MPI_Recv(buffer, count, datatype, MPI_ANY_SOURCE, 777, comm,  &stat);
    }

    for (int i = 0; i < ceil(log2(size)); i++)
    {
        if (_rank < pow(2, i))
            MPI_Send(buffer, count, datatype, int(ceil(pow(2, i) + rank)) % size, 777, comm);
    }
    MPI_Barrier(comm);
    return 0;
}

int main(int argc, char *argv[])
{
    int rank, size;
    double t1, t2;
    int a;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if(rank == 2)
        a = 10000;

    t1 = MPI_Wtime();
    ourBcast(&a, 1, MPI_INT, 2, MPI_COMM_WORLD);
    t2 = MPI_Wtime();

    if(rank == 0)
        printf("t = %g \n", t2 - t1);

    printf("rank: %d, a = %d\n", rank, a);

    MPI_Finalize();
    return 0;
}