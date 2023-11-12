#include <cmath>
#include "windows.h"
#include "mpi.h"

int main(int argc, char *argv[])
{
	int rank, size, a;
	double t1, t2;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 2)
		a = 100;

	t1 = MPI_Wtime();
	MPI_Bcast(&a, 1, MPI_INT, 2, MPI_COMM_WORLD);
	t2 = MPI_Wtime();
	printf("rank: %d a = %d\n", rank, a);

	if (rank == 0)
		printf("time: %g\n", t2 - t1);

	MPI_Finalize();
	return 0;
}
