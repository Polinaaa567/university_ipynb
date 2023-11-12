#include <iostream>
#include <mpi.h>
#include <stdint.h>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	int rank, size, n;

	MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank % 2 == 0) {
        n = 2 * rank;
    } else {
        n = 3 * rank;
    }
	
	cout << "Process " << rank << ": n = " << n << endl;

	MPI_Finalize();

	return(0);
}

