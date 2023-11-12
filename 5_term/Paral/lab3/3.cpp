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
        n = 3*size;
        int *a=new  int[n];
        for(int i = 0; i < n; i++)
            a[i]=i;
        for(int i =1; i< n; i++)
        {
            if(i % size != 0)
                MPI_Send(&a[i],1,MPI_INT,i % size,777,MPI_COMM_WORLD);
        }
        printf( "rank = %d, a: ",rank ); 
            for(int i = 0; i < n; i++)
            cout<<a[i]<<" ";

        delete[]a;
    }
    else
    {
        int *b = new int[3];
        for (int i = 0; i < 3; i++)
            MPI_Recv(&b[i],1,MPI_INT,0,777,MPI_COMM_WORLD,&stat);

        printf( "rank = %d, b: ",rank ); 
            for(int i = 0; i < 3; i++)
            cout<<b[i]<<" ";

        cout<<endl;


    delete []b;
    }

    MPI_Finalize();
    return 0;
}

