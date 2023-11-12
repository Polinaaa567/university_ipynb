#include <stdio.h>
#include "mpi.h"
#include "iostream"

using namespace std;

int main(int argc, char *argv[])
{
    int rank, size;
    int n=0;
    MPI_Status stat;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank==0)
    {
        int k = 0;
        n = ((size*(size+1))/2)-1;
        int *a=new  int[n];

        for(int i =1; i< size; i++)
        {   if (i ==1) 
                MPI_Recv(&a[i - 1], i+1,MPI_INT,i,777,MPI_COMM_WORLD, &stat);
            else{
                MPI_Recv(&a[i + k], i+1,MPI_INT,i,777,MPI_COMM_WORLD, &stat);
                k+=i;
            }
           
        }
        printf( "rank = %d, a: ",rank ); 
        for(int i = 0; i < n; i++)
            cout<<a[i]<<" ";

        cout<<endl;
        delete[]a;
    }
    else
    {
        int *b = new int[rank+1];
        for (int i = 0; i < rank + 1; i++)
            b[i] = rank;
        MPI_Send(&b[0],rank+1,MPI_INT,0,777,MPI_COMM_WORLD);


    delete []b;
    }

    MPI_Finalize();
    return 0;
}

