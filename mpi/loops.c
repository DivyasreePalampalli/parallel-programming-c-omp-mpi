#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int i, rank, nprocs, count, start, stop, nloops;

    MPI_Init(&argc, &argv);

    // get the number of processes, and the id of this process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    // we want to perform 1000 iterations in total. Work out the 
    // number of iterations to perform per process...
    count = 1000 / nprocs;

    // we use the rank of this process to work out which
    // iterations to perform.
    start = rank * count;
    stop = start + count;

    // now perform the loop
    nloops = 0;

    for (i=start; i<stop; ++i)
    {
        ++nloops;
    }

    printf("Process %d performed %d iterations of the loop.\n",
           rank, nloops);

    MPI_Finalize();

    return 0;
}
// mpicc loops.c -o loops