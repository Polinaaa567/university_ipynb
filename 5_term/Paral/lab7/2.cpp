#include <stdio.h>
#include "iostream"
#include "mpi.h"
#include "windows.h"

using namespace std;



int main(int argc, char *argv[])
{
	int rank;
	int size;
    int *a;
    int *b;
	MPI_Status stat;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	double t1, t2;
	int n = 1000000;
    //cin >> n;
	if (rank == 0)
    {

		 int* a = new int[n];
		for (int i = 0; i < n; i++)
        {
			a[i] = 0;
		}
		t1 = MPI_Wtime();
        // MPI_Send(a, n, MPI_INT, 1, 777, MPI_COMM_WORLD);
		MPI_Sendrecv(a, n, MPI_INT, 1, 777, a, n, MPI_INT, 1, 777, MPI_COMM_WORLD, &stat);
        // MPI_Recv(a, n, MPI_INT, 1, 777, MPI_COMM_WORLD, &stat);
		t2 = MPI_Wtime();
		printf("rank=%d t2-t1=%g\n", rank, t2-t1);
        delete []a;
	}
	if (rank == 1){
		b = new int[n];
		for (int i = 0; i < n; i++){
			b[i] = 1;
		}
		t1 = MPI_Wtime();
            // MPI_Recv(b, n, MPI_INT, 0, 777, MPI_COMM_WORLD, &stat);
            // MPI_Send(b, n, MPI_INT, 0, 777, MPI_COMM_WORLD);
        
		MPI_Sendrecv(b, n, MPI_INT, 0, 777, b, n, MPI_INT, 0, 777, MPI_COMM_WORLD, &stat);
        t2 = MPI_Wtime();
		printf("rank=%d t2-t1=%g\n", rank, t2 - t1);
        delete []b;

	}

	MPI_Finalize();
	return 0;
}