#include <stdio.h>
#include "mpi.h"
#include "iostream"

using namespace std;

int main(int argc, char *argv[])
{
    int rank, size, next, prev;
    int a = 0;

    MPI_Status stat;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    next = rank + 1;
    prev = rank - 1;

    if(rank == 0) {
        prev = size - 1;
    }

    if(rank == size - 1)  {
        next = 0;
    }

    if(rank==0)
    {
    cout<<"Enter a: ";
        cin>>a;
        MPI_Send(&a,1,MPI_INT,next,777,MPI_COMM_WORLD);
        MPI_Recv(&a,1,MPI_INT,prev,777,MPI_COMM_WORLD, &stat);
    }
    else
    {
        MPI_Recv(&a,1,MPI_INT,prev,777,MPI_COMM_WORLD,&stat);
        a++;
        MPI_Send(&a,1,MPI_INT,next,777,MPI_COMM_WORLD);
    }

    printf( "rank = %d, a = %d \n",rank, a ); 


    MPI_Finalize();
    return 0;
}

