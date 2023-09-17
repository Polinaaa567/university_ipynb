#include <stdio.h>
#include "mpi.h"
#include "iostream"

using namespace std;

int main(int argc, char *argv[])
{
int rank;
int size;
int n=0, s=0;
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

for(int i=rank;i<n;i+=size)
    s+=i;



if(rank==0)
{
int s1;
    for(int i = 1; i < size; i++)
    {
	MPI_Recv(&s1,1,MPI_INT,i,777,MPI_COMM_WORLD,&stat);
	s+=s1;
    }
    
printf( "rank = %d, s = %d \n",rank, s ); 
}
else
{
    MPI_Send(&s,1,MPI_INT,0,777,MPI_COMM_WORLD);
}

MPI_Finalize();
return 0;
}

