#include <stdio.h>
#include "mpi.h"
#include "iostream"
#include "stdlib.h"
#include "time.h"

using namespace std;

int main(int argc, char *argv[])
{
int rank;
int size;
int n=0;
MPI_Status stat;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

if(rank==0)
{
for(int i = 1; i < size; i++)
{
    MPI_Recv(&n,1,MPI_INT,MPI_ANY_SOURCE,777,MPI_COMM_WORLD,&stat);
    printf( "n = %d source=%d\n", n , stat.MPI_SOURCE); 
}
}
else
{
srand(rank*17*time(0));
n=rand()%100;
MPI_Send(&n,1,MPI_INT,0,777,MPI_COMM_WORLD);
}

MPI_Finalize();
return 0;
}

