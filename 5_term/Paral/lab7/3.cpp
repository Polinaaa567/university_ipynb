#include <stdio.h>
#include "mpi.h"
int main(int argc, char *argv[])
{
    int rank;
    int size;
    int a=0,b=0;
    MPI_Status stat;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(rank%2 == 0)
    {
        a=44;
        MPI_Sendrecv(&a,1,MPI_INT,rank+2,777,&a,1,MPI_INT,rank+2,777,MPI_COMM_WORLD,&stat);
        printf("rank= %d, a= %d \n ", rank,a);

    }
    if(rank%2 == 1)
    {
        b=55;
        MPI_Sendrecv(&b,1,MPI_INT,rank+2,777,&b,1,MPI_INT,rank+2,777,MPI_COMM_WORLD,&stat);
        printf("rank= %d, b=%d \n ", rank,b);
    }
    MPI_Finalize();
    return 0;
}


