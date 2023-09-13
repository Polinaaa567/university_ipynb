#include <iostream>
#include <mpi.h>
#include <stdint.h>
#include <cmath>

using namespace std;


int main(int argc, char *argv[])
{
    int rank, summ = 0, size, A[5];

	MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    for(int i = 0; i < rank + 1; i++) {
        A[i] = i;
        summ += A[i];
    }

    cout << "Process number: " << rank << "     Summ = "<< summ << endl;
	MPI_Finalize();

	return(0);
}

