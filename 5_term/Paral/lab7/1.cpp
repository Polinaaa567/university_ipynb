#include <stdio.h>
#include "mpi.h"
int main(int argc, char *argv[])
{
    int rank;
    int size;
    int a=44,b=55;
    MPI_Status stat;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    // Начало кольца
    if(rank == 0 || rank == 1)
    { 
        if (rank == 0) 
        {
            MPI_Sendrecv(&a, 1, MPI_INT, rank + 2, 777, &a, 1, MPI_INT, MPI_ANY_SOURCE, 777, MPI_COMM_WORLD, &stat);
            printf("rank%2 ==0 result rank= %d, a= %d \n ", rank,a);
        }
        else 
        {
            MPI_Sendrecv(&b, 1, MPI_INT, rank + 2, 777, &b, 1, MPI_INT, MPI_ANY_SOURCE, 777, MPI_COMM_WORLD, &stat);
            printf("rank%2 ==1 result rank= %d, b= %d \n ", rank, b);
        }
    }
    

    // Последние процессы колец

    else if (rank == size - 1 || rank == size - 2)
    {
        if(rank%2 == 0)
        {
            MPI_Recv(&a, 1, MPI_INT, rank - 2, 777, MPI_COMM_WORLD, &stat);
            a++;
            MPI_Send(&a,1,MPI_INT,0,777, MPI_COMM_WORLD);
            printf("rank%2 ==0 rank= %d, a= %d \n ", rank,a);

        }
        else
        {
            MPI_Recv(&b, 1, MPI_INT, rank - 2, 777, MPI_COMM_WORLD, &stat);
            b++;
            MPI_Send(&b,1,MPI_INT,1,777, MPI_COMM_WORLD);
            
            printf("rank%2 == 1 rank= %d, b=%d \n ", rank,b);
        }
    }
// между 
    else 
    {
        if(rank%2 == 0)
        {
            MPI_Recv(&a, 1, MPI_INT, rank - 2, 777, MPI_COMM_WORLD, &stat);
            a++;
            MPI_Send(&a,1,MPI_INT, rank + 2,777, MPI_COMM_WORLD);
            printf("rank%2 ==0 rank= %d, a= %d \n ", rank,a);

        }
        else
        {
            MPI_Recv(&b, 1, MPI_INT, rank - 2, 777, MPI_COMM_WORLD, &stat);
            b++;
            MPI_Send(&b,1,MPI_INT,rank + 2,777, MPI_COMM_WORLD);
            
            printf("rank%2 == 1 rank= %d, b=%d \n ", rank,b);
        }
    }
    MPI_Finalize();
    return 0;
}