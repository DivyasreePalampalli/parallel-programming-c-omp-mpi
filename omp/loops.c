#include <stdio.h>

#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif

int main(int argc, char **argv)
{
    int i, thread_id, nloops;

    #pragma omp parallel private(thread_id, nloops)
    {
        nloops = 0;

        #pragma omp for
        for (i=0; i<1000; ++i)
        {
            ++nloops;
        }

        thread_id = omp_get_thread_num();

        printf("Thread %d performed %d iterations of the loop.\n",
                thread_id, nloops );
    }

    return 0;
}

// gcc-15 -fopenmp loops.c -o loops