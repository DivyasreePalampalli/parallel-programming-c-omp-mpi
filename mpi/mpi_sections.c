#include <mpi.h>
#include <stdio.h>
#include <unistd.h> //for sleep

void times_table(int n)
{
    int i, i_times_n, rank;
    
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    for (i=1; i<=n; ++i)
    {
        i_times_n = i * n;
        printf("Process %d says %d times %d equals %d.\n",
               rank, i, n, i_times_n );

        sleep(1);
    }
}

void countdown()
{
    int i, rank;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    for (i=10; i>=1; --i)
    {
        printf("Process %d says %d...\n", rank, i);
        sleep(1);
    }

    printf("Process %d says \"Lift off!\"\n", rank);
}

void long_loop()
{
    int i, rank;
    double sum = 0;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    for (i=1; i<=10; ++i)
    {
        sum += (i*i);
        sleep(1);
    }

    printf("Process %d says the sum of the long loop is %f\n",
            rank, sum);
}

int main(int argc, char **argv)
{
    int rank;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
        printf("This is the main process.\n");
        times_table(12);
    }
    else if (rank == 1)
    {
        countdown();
    }
    else if (rank == 2)
    {
        long_loop();
    }
    else
    {
        printf("I am not needed...\n");
    }

    MPI_Finalize();

    return 0;
}


// mpicc mpi_sections.c -o mpi_sections