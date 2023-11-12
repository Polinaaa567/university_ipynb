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
    n = 3*size;
    int *a=new  int[n];
    for(int i = 0; i < n; i++)
	a[i]=i;
    for(int i =1; i<size; i++)
	{
	    MPI_Send(&a[3*i],3,MPI_INT,i,777,MPI_COMM_WORLD);
	}
}
else
{
    int *b = new int[3];
    MPI_Recv(&b[0],3,MPI_INT,0,777,MPI_COMM_WORLD,&stat);

double s=0;
    for(int i = 0; i < rank*1000000; i++)
	s+=0.0000000001;

printf( "rank = %d, b: ",rank ); 
    for(int i = 0; i < 3; i++)
	cout<<b[i]<<" ";

cout<<endl;


delete []b;
}

MPI_Finalize();
return 0;
}

