// #include <stdio.h>
// #include "mpi.h"
// #include "iostream"
// using namespace std;

// int main(int argc, char *argv[])
// {
// int rank;
// int size;
// int n=0;
// double t1,t2,a=0,t,fl;
// MPI_Init(&argc, &argv);
// MPI_Comm_rank(MPI_COMM_WORLD, &rank);
// MPI_Comm_size(MPI_COMM_WORLD, &size);

// n = 1000000000;

// t1=MPI_Wtime();
// for(int i=0;i<n;i++)
//     a=a+0.000000000001;
// t2=MPI_Wtime();

// t=(t2-t1)/n;

// fl=1./t/1000000000;


//   printf( "n = %d, t2-t1=%g t = %g Gflops=%g\n",n,t2-t1,t,fl ); 


// MPI_Finalize();
// return 0;
// }


#include <mpi.h>
#include <stdio.h>
int main( int argc, char *argv[ ] ){
  int rank, size, j;
  long int n=1000000000;
  double t1,t2,s;
  MPI_Init( &argc, &argv );
  
  t1=MPI_Wtime();
  for(j=0;j<n;j++)
    s=s+0.00000000001+0.00000000001;
  t2=MPI_Wtime();
  printf("n=%d MF=%f t= %f s=%f\n",2*n,2*n/(1000000*(t2-t1)),t2-t1,s);
  
  MPI_Finalize();
return(0);
}