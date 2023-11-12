#include <stdio.h>
#include "mpi.h"
#include "iostream"

using namespace std;

int main(int argc, char *argv[])
{
int rank;
int size;
int n=10;
MPI_Status stat;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

int **a=new int*[n];
    a[0]=new int[n*n];
    for(int i = 1; i < n; i++)
	a[i]=a[i-1]+n;

if(rank==0)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
	    a[i][j]=10*(i+1)+j+1;

    for(int i = 0; i < n; i+=2)
        MPI_Send(&a[i][0],n,MPI_INT,1,777,MPI_COMM_WORLD);
}
if(rank==1)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
	    a[i][j]=0;
    for(int i = 0; i < n/2; i++)
        MPI_Recv(&a[i][0],n,MPI_INT,0,777,MPI_COMM_WORLD,&stat);
}

//sleep(rank);

double s=0;
    for(int i = 0; i < rank*1000000; i++)
	s+=0.0000000001;

printf( "rank = %d, a: \n",rank ); 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
	    cout<<a[i][j]<<" ";
    cout<<endl;
    }
cout<<endl;

delete []a[0];
delete []a;


MPI_Finalize();
return 0;
}

