#include <stdio.h>
#include "mpi.h"
#include "iostream"
#include "stdlib.h"
#include "time.h"

using namespace std;

int main(int argc, char *argv[])
{
    int rank;
    int size;
    int count=0;
    MPI_Status stat;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    if(rank == 0){
        int** a = new int*[size];

        a[0] = new int[size*size];

        for(int i = 1; i < size; i++){
            a[i] = a[i-1]+size;
        }

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                a[i][j] = 0;
            }
        }

        for(int i = 1; i < size; i++){
            MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &stat);

            MPI_Get_count(&stat, MPI_INT, &count);

            MPI_Recv(a[stat.MPI_SOURCE], count, MPI_INT, stat.MPI_SOURCE, 777, MPI_COMM_WORLD, &stat);

            cout << "source = " << stat.MPI_SOURCE <<", count = "<<count<<endl;
        }

        cout << "Arr=\n";

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                cout<< a[i][j] << " ";
            }
            cout << endl;
        }

		delete []a[0];
		delete []a;

    } else{
		srand(rank*17*time(0));
		int k = rand() % (size - 1) + 1;
        int* b = new int[k];
        for(int i = 0; i < k; i++){
            b[i] = rank;
        }

		cout << "Array to send from process " << rank << ": ";
        for (int i = 0; i < k; i++) {
            cout << b[i] << " ";
        }
        cout << endl;

        MPI_Send(&b[0], k, MPI_INT, 0, 777, MPI_COMM_WORLD);

		delete[] b;
    }


    MPI_Finalize();
    return 0;
}

