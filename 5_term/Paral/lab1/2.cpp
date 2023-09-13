#include <iostream>
#include <mpi.h>
#include <stdint.h>

using namespace std;

int main(int argc, char *argv[])
{
    int my_rank;
    int size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    printf("Hello world! Processor %s, rank (processor number) %d of %d processor \n", processor_name, my_rank, size);
    
    MPI_Finalize();
    return 0;
}

