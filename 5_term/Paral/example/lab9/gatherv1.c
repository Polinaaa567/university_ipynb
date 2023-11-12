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

int *b=new int[rank+1];
for(int i = 0; i < rank+1; i++)
    b[i]=rank;

int *a=new int[size*(size+1)/2];

int *bl=new int[size];
int *ds=new int[size];

for(int i = 0; i < size; i++)
{
    bl[i]=i+1;
    ds[i]=i*(i+1)/2;
}

MPI_Gatherv(b,rank+1,MPI_INT,a,bl,ds,MPI_INT,0,MPI_COMM_WORLD);

double s=0;
    for(int i = 0; i < rank*1000000; i++)
	s+=0.0000000001;

printf( "rank = %d, a: ",rank ); 
    for(int i = 0; i < size*(size+1)/2; i++)
	cout<<a[i]<<" ";

cout<<endl;

delete []a;
delete []b;
delete []bl;
delete []ds;

MPI_Finalize();
return 0;
}

