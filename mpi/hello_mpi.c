#include <stdio.h>

int main(int argc, char **argv)
{
    printf("Hello MPI!\n");

    return 0;
}

//mpicc hello_mpi.c -o hello_mpi
// mpirun hello_mpi
// mpiprun -np 2 hello_mpi