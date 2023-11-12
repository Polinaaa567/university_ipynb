#include <stdio.h>
#include "mpi.h"
#include "iostream"

using namespace std;

int main(int argc, char *argv[])
{
    int rank;
    int size;
    int n=0;
    double t1,t2,t,MFlops,s=0;
    MPI_Status stat;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    if(rank == 0){
        int* arr = new int[size];

        for(int i = 0; i < size; i++){
            arr[i] = 0;
        }

        for(int i = 1; i < size; i++){
            int n;
            MPI_Recv(&n, 1, MPI_INT, MPI_ANY_SOURCE, 777, MPI_COMM_WORLD, &stat);
            std::cout << "source=" << stat.MPI_SOURCE << std::endl;
            arr[stat.MPI_SOURCE] = n;
        }

        std::cout << "Arr=";

        for(int i = 0; i < size; i++){
            std::cout << arr[i] << " ";
        }

    }else{
        MPI_Send(&rank, 1, MPI_INT, 0, 777, MPI_COMM_WORLD);
    }



    MPI_Finalize();
    return 0;
}

