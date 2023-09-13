#include <iostream>
#include <mpi.h>
#include <stdint.h>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    
	double begin, end, summ=0;

	MPI_Init(&argc, &argv);

	int j = 9;//принимает значения (6-9)
	begin = MPI_Wtime();

	for (int i = 0; i < pow(10, j); i++)
		summ += 1/(1 + i);

	end = MPI_Wtime();

	cout << "10^" << j << " ";
	printf("Summ=%f", summ);
	printf(" Time=%f", end - begin);
	cout << endl;

	MPI_Finalize();

	return(0);
}

