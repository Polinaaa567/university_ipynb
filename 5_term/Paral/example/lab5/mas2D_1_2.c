#include <stdio.h>
#include "mpi.h"
#include "iostream"

using namespace std;

int main(int argc, char *argv[])
{
int rank;
int size;
int n=9;
MPI_Status stat;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

if(rank==0)
{
int **a=new int*[2*size];
    a[0]=new int[2*size*n];
    for(int i = 1; i < 2*size; i++)
        a[i]=a[i-1]+n;

    for(int i = 0; i < 2*size; i++)
        for(int j = 0; j < n; j++)
            a[i][j]=10*(i+1)+j+1;

    for(int i = 1; i < size; i++)
        MPI_Send(a[2*i],2*n,MPI_INT,i,777,MPI_COMM_WORLD);

delete []a[0];
delete []a;

}
else
{
int **b=new int*[2];
    b[0]=new int[2*n];
    for(int i = 1; i < 2; i++)
        b[i]=b[i-1]+n;

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n; j++)
	    b[i][j]=0;

    MPI_Recv(&b[0][0],2*n,MPI_INT,0,777,MPI_COMM_WORLD,&stat);

//sleep(rank);

double s=0;
    for(int i = 0; i < rank*1000000; i++)
	s+=0.0000000001;

printf( "rank = %d, b: \n",rank );
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
	    cout<<b[i][j]<<" ";
    cout<<endl;
    }
cout<<endl;

delete []b[0];
delete []b;
}

MPI_Finalize();
return 0;
}

