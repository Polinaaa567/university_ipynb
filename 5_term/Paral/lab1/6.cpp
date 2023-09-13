#include <iostream>
#include <cstdlib>
#include <mpi.h>
#include <ctime>

using namespace std;


int main(int argc, char *argv[])
{
    int rank, size, numbers[100];

    double sum = 0, average = 0;

	MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    srand(time(NULL) + rank);

    for (int i = 0; i < 100; i++) {
        numbers[i] = rand() % 101;
        sum += numbers[i];
    }

    average = sum / 100;

    cout << "Process number: " << rank << "     Average = "<< average << endl;
	MPI_Finalize();

	return(0);
}

