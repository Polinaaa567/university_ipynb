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

int *a=new int[n];

if(rank==0)
{
    for(int i = 0; i < n; i++)
	a[i]=i;
	
    for(int i = 1; i < size; i++)
	MPI_Send(&a[0],n,MPI_INT,i,777,MPI_COMM_WORLD);
}
else
{
    MPI_Recv(a,n,MPI_INT,0,777,MPI_COMM_WORLD,&stat);
}

//sleep(rank);

double s=0;
    for(int i = 0; i < rank*1000000; i++)
	s+=0.0000000001;

printf( "rank = %d, a: ",rank ); 
    for(int i = 0; i < n; i++)
	cout<<a[i]<<" ";

cout<<endl;


delete []a;

MPI_Finalize();
return 0;
}

