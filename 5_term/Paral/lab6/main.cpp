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
        int** arr = new int*[size];

        arr[0] = new int[size*size];

        for(int i = 1; i < size; i++){
            arr[i] = arr[i-1]+size;
        }


        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                arr[i][j] = 0;
            }
        }

        for(int i = 1; i < size; i++){
            MPI_Probe(MPI_ANY_SOURCE, 777, MPI_COMM_WORLD, &stat);
            MPI_Get_count(&stat, MPI_INT, &n);
            MPI_Recv(arr[stat.MPI_SOURCE], n, MPI_INT, stat.MPI_SOURCE, 777, MPI_COMM_WORLD, &stat);
            std::cout << "source=" << stat.MPI_SOURCE << std::endl;
        }

        std::cout << "Arr=\n";

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                std::cout<< arr[i][j] << " ";
            }
            std::cout << std::endl;
        }


    }else{
        srand(rank*17*time(0));
        int k =rand()%100;
        int* arr = new int[k];

        for(int i = 0; i < k; i++){
            arr[i] = 0;
        }

        MPI_Send(&arr[0], k, MPI_INT, 0, 777, MPI_COMM_WORLD);
    }


    MPI_Finalize();
    return 0;
}

