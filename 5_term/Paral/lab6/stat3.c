#include <stdio.h>
#include "mpi.h"
#include "iostream"

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
int *a = new int [size];
for(int i = 0; i < size; i++)
    a[i]=0;

for(int i = 1; i < size; i++)
{
    MPI_Recv(&n,1,MPI_INT,MPI_ANY_SOURCE,777,MPI_COMM_WORLD,&stat);
    a[stat.MPI_SOURCE] = n;
    printf( "n = %d , status = %d \n", n, stat.MPI_SOURCE ); 
}
for (int i = 1; i < size; i++)
{
    printf("%d ",a[i]);
}
cout<<endl;
delete []a;
}
else
{
MPI_Send(&rank,1,MPI_INT,0,777,MPI_COMM_WORLD);
}

MPI_Finalize();
return 0;
}

