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
cout<<"Enter n: ";
    cin>>n;
    for(int i = 1; i < size; i++){
	MPI_Send(&n,1,MPI_INT,i,777,MPI_COMM_WORLD);
    }
}
else
{
    MPI_Recv(&n,1,MPI_INT,0,777,MPI_COMM_WORLD,&stat);
}

printf( "rank = %d, n = %d \n",rank, n ); 


MPI_Finalize();
return 0;
}

